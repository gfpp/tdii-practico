#include <stdio.h>
#include <termios.h>

#define FD_STDIN 0

int main(void)
{
  struct termios term;

  tcgetattr(FD_STDIN, &term);

  /* Non-canonical input, without eco */
  term.c_lflag |= (ICANON | ECHO);

  tcsetattr(FD_STDIN, TCSANOW, &term);

  return 0;
}

