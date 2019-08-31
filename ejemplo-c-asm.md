# Ejemplo de proyecto en lenguale C y ensamblador

Se muestra un ejemplo de proyecto que incluye archivos fuentes en lenguaje C y en asembler.
El programa realiza la suma de dos valores enteros inicializados en el código fuente que es devuelto por la función `main()`.

 * Archivo `.c`: *"declara"* la función `suma` como externa, o sea, le indica que es una función que recibe dos enteros y devuelve un entero
 * Archivo `.s`: *"define"* la función `suma`

Código en lenguaje C
```c
#include <stdio.h>

extern int suma(int a, int b);

int main(void)
{
  int a = 71;
  int b = 29;
  int c;

  c = suma(a,b);

  return c;
} 
```

Código en lenguaje ensamblador
```nasm
.text
.arm
.global suma

suma:
  add   r2, r0, r1
  mov   r0, r2                    
  mov   pc, lr  

```

## Construcción para simulación


```
arm-none-eabi-gcc -Wall -mcpu=arm7tdmi -g -c main.c -o main.o
arm-none-eabi-as -mcpu=arm7tdmi -g suma.s -o suma.o
arm-none-eabi-gcc -Ttext=0 -nostartfiles -g main.o suma.o -o suma.elf
```

* La primer línea compila el código fuente del archivo `main.c` y genera el archivo objeto `main.o`
* La segunda línea ensambla el archivo fuente `suma.s` y genera el archivo `suma.o`
* La última línea enlaza los dos archivos objetos (`main.o` y `suma.o`) y genera el archivo `suma.elf`

Las diferentes opciones utilizadas son:
   * `-c` para detener la construcción luego de la etapa de compilación y tiene como salida el archivo objeto (`.o`). 
   * `-o` para indicar el nombre del archivo de salida. 
   * `-Wall` para habilitar todos las advertencias (warnings) del compilador. 
   * `-mcpu=arm7tdmi` para indiar la arquitectura del procesador.
   * `-g` para incluir información de depuración en los archivos de salida. 


### Simulación en PC con gdb
   
A COMPLETAR

## Construcción utilizando `make`

Archivo `Makefile` para la compilación cruzada 
```make
CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
LD = arm-none-eabi-ld

OBJECTS = main.o suma.o

CFLAGS = -Wall -mcpu=arm7tdmi -g  -c
ASFLAGS = -mcpu=arm7tdmi -g 
LDFLAGS = -Ttext=0 -nostartfiles -g 

suma.elf: $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o suma.elf

suma.o: suma.s 
	$(AS) $(ASFLAGS) suma.s -o suma.o

main.o: main.c
	$(CC) $(CFLAGS) main.c

clean:
	rm *.o *.elf 
```

Archivo `Makefile` para la compilación sobre la RPi
```make
CC = gcc
AS = as
LD = ld

OBJECTS = main.o suma.o

CFLAGS = -Wall -g  -c
ASFLAGS = -g 
LDFLAGS = -g 

suma.elf: $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o suma.elf

suma.o: suma.s 
	$(AS) $(ASFLAGS) suma.s -o suma.o

main.o: main.c
	$(CC) $(CFLAGS) main.c

clean:
	rm *.o *.elf 
```
