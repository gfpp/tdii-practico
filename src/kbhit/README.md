# Lectura del teclado no-bloqueante

Se muestra la forma de configurar la terminal y la entrada estándar para poder hacer lecturas no-bloqueantes desde el teclado.
El código fuente está basado en el ejemplo mostrado en [Non-blocking user input in loop without ncurses](https://web.archive.org/web/20180401093525/http://cc.byexamples.com/2007/04/08/non-blocking-user-input-in-loop-without-ncurses/).
Las funciones para configurar la entrada de teclado como no-bloqueantes están separados en los archivos `kbhit.h` y `kbhit.c` para poder utilizarlas en diferentes aplicaciones.

Las aplicaciones de prueba son:

 1. El ejemplo de la página
 1. Ejemplo de blink de LED hasta que se presiona una tecla

Compilar la aplicación de prueba:
```
> gcc -Wall -std=c90 test.c kbhit.c
```

Compilar la aplicación blink:
```
> gcc -Wall -std=c90 blink.c kbhit.c -lwiringPi
```

