#include <wiringPi.h>
#include "kbhit.h"

#define GPIO_OUT 21

int main(void)
{
  wiringPiSetupGpio();
  pinMode(GPIO_OUT, OUTPUT);

  // Non-blicking keyboard.
  nonblock(NB_ENABLE);

  while(!kbhit())
  {
    digitalWrite(GPIO_OUT, HIGH);
    delay(500);
    digitalWrite(GPIO_OUT, LOW);
    delay(500);
  }

  digitalWrite(GPIO_OUT, LOW);
  return 0;
}

