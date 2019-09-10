#include <stdio.h>
#include <signal.h>
#include "gpio_sysfs.h"

#define GPIO (16)

unsigned int flag = 1;
void handler(int );

int main(void)
{
  int fd;

  signal(SIGINT, handler);

  printf("Opening GPIO...\n");
  fd = openGpio(GPIO, GPIO_DIR_OUT);
  if(fd == -1)
    return -1;

  printf("Blinky...\n");
  while(flag)
  {
    writeGpio(fd, 0);
    sleep(1);
    writeGpio(fd, 1);
    sleep(1);
  }

  printf("Closing GPIO...\n");
  writeGpio(fd, 0);
  closeGpio(GPIO, fd);
  return 0;
}

void handler(int sig)
{
  flag = 0;
}

