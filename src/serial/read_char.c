#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "termset.h"

#define SIZE 10

int main(int argc, char * argv[])
{
  int i, fd;
  unsigned char buf[SIZE];
  ssize_t n_read;

  if(argc == 2)
  {
    printf("USAGE: %s <device> <baudrate>\n", argv[0]);
    return -1;
  }

  // Open device.
  fd = open(argv[1], O_RDONLY | O_NOCTTY | O_SYNC);
  if(fd < -1)
  {
    printf("ERROR: opening serial port\n");
    return -1;
  }

  if(termset(fd, atoi(argv[2]), &ttyold, &ttynew) == -1)
  {
    printf("ERROR: setting tty\n");
    return -1;
  }

  for(;;)
  {
    n_read = read(fd, buf, SIZE);
    for(i = 0; i < n_read; i++)
      printf("%d ", buf[i]);
    printf("\n");
  }

  close(fd);
  return 0;
}

