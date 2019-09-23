#ifndef KBHIT_H
#define KBHIT_H

#include <stdio.h>
#include <sys/select.h>
#include <termios.h>

#define STDIN_FILENO 0
#define NB_ENABLE 0
#define NB_DISABLE 1

int kbhit(void);
void nonblock(int state);

#endif
