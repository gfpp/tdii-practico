/* 
 * Basado en el código fuente ejemplo de:
 * https://www.raspberrypi.org/forums/viewtopic.php?f=33&t=8476&p=101994
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>
#include <stdint.h>

static volatile unsigned int *gpio;

int main(int argc, char **argv)
{
  int fd ;

  // Obtain handle to physical memory
  printf("Opening file /dev/mem...\n");
  if( (fd = open ("/dev/mem", O_RDWR | O_SYNC) ) < 0 ) 
  {
    printf("Unable to open /dev/mem: %s\n", strerror(errno));
    return -1;
  }

  // Map a page of memory to gpio at offset 0x20200000 which is 
  // where GPIO goodnessstarts
  printf("Mapping memmory...\n");
  gpio = (volatile unsigned int *)mmap(0, getpagesize(), 
      PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0x3f200000);

  if(gpio < 0)
  {
    printf("Mmap failed: %s\n", strerror(errno));
    return -1;
  }

  // Set gpio17 as an output
  // Increment the pointer to 0x20200004
  // Set the value through a little bit twiddling where we only modify the 
  // bits 21-23 in the register
/*  *(gpio + 1) = (*(gpio + 1) & ~(7 << 21)) | (1 << 21);*/
  printf("Setting GPIO as output...\n");
  *(gpio + 1) = (*(gpio + 1) & ~(7 << 18)) | (1 << 18);

  printf("Blinky...\n");
  // Toggle gpio17 every second
  while(1)
  {
    // Set the pin high
    // Increment the pointer to 0x2020001C
/*    *(gpio + 7) = 1 << 17;*/
    *(gpio + 7) = 1 << 16;

    // Sleep
    sleep(1);

    // Set the pin to low
    // Increment the pointer to 0x20200028
/*    *(gpio + 10) = 1 << 17;*/
    *(gpio + 10) = 1 << 16;

    sleep(1);
  }
}

