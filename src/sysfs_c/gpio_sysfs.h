#ifndef _GPIO_SYSFS_H
#define _GPIO_SYSFS_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define GPIO_DIR_OUT (0)
#define GPIO_DIR_IN (1)

int openGpio(int gpio, int dir);
int writeGpio(int fd, int val);
int readGpio(int fd);
int closeGpio(int gpio, int fd);


#endif
