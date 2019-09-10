#include <wiringPi.h>

#define GPIO_OUT 21

int main(void)
{
  wiringPiSetupGpio();
  pinMode(GPIO_OUT, OUTPUT);

  for(;;)
  {
    digitalWrite(GPIO_OUT, HIGH);
    delay(500);
    digitalWrite(GPIO_OUT, LOW);
    delay(500);
  }

  return 0;
}

