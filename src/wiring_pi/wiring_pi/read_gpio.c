#include <stdio.h>
#include <stdlib.h>

#include <wiringPi.h>

int in_array(const unsigned char * , int , const unsigned char );

/* GPIO input */
const unsigned char N_GPIO_IN = 6;
const unsigned char gpio_in[] = {17, 27, 5, 6, 12, 19};


int main(int argc, char *argv[])
{
  unsigned char gpio;

  if(argc != 2)
  {
    printf("Uso: %s <gpio_pi>\n", argv[0]);
    return -1;
  }

  gpio = atoi(argv[1]);
  if(in_array(gpio_in, N_GPIO_IN, gpio) == 0)
  {
    printf("ERROR: GPIO no válido!\n");
    return -1;
  }

  /* Wiring Pi GPIO configuration */
  iringPiSetupGpio();
  pinMode((int)gpio, INPUT);

  printf("Leyendo GPIO %d...\n", gpio);
  for(;;)
  {
    printf("%d\n", digitalRead(gpio));
    delay(500);
  }

  return 0;
}


int in_array(const unsigned char *array, int N,
    const unsigned char val)
{
  int i;
  
  for(i = 0; i < N; i++)
    if(array[i] == val)
      return 1;

  return 0;
}

