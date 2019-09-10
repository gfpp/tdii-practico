#include "gpio_sysfs.h"

int openGpio(int gpio, int dir)
{
  char buf[256];
  int fd;
  int mode;

  // Export GPIO
  fd = open("/sys/class/gpio/export", O_WRONLY);
  if(fd == -1)
  {
    printf("ERROR: /sys/class/gpio/export\n");
    return -1;
  }

  sprintf(buf, "%d", gpio);
  write(fd, buf, strlen(buf));
  close(fd);

  // Direction
  sprintf(buf, "/sys/class/gpio/gpio%d/direction", gpio);
  fd = open(buf, O_WRONLY);
  if(fd == -1)
  {
    printf("ERROR: %s\n", buf);
    return -1;
  }

  if(dir == GPIO_DIR_OUT)
  {
    write(fd, "out", 3);
    mode = O_WRONLY;
  }
  else
  {
    write(fd, "in", 2);
    mode = O_RDONLY;
  }
  close(fd);

  // Open GPIO for read/write
  sprintf(buf, "/sys/class/gpio/gpio%d/value", gpio);
  fd = open(buf, mode);
  if(fd == -1)
  {
    printf("ERROR: %s\n", buf);
    return -1;
  }

  return fd;
} 

int writeGpio(int fd, int val)
{
  if(val == 0)
    write(fd, "0", 1);
  else
    write(fd, "1", 1);

  return 0;
}

int readGpio(int fd)
{
  int value;

  read(fd, &value, 1);

  if(value == '0')
    value = 0;
  else
    value = 1;

  return value;
}

int closeGpio(int gpio, int fd)
{
  char buf[256];

  close(fd);

  fd = open("/sys/class/gpio/unexport", O_WRONLY);
  if(fd == -1)
  {
    printf("ERROR: /sys/class/gpio/unexport\n");
    return -1;
  }
  sprintf(buf, "%d", gpio);
  write(fd, buf, strlen(buf));
  close(fd);

  return 0;
}

