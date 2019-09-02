# Programación de la terminal de Linux

## Modo canónico vs. no-canónico

Por defecto, la entrada por teclado desde la terminal no se envía al programa hasta que el usuario presiona la tecla Enter. En la mayoría de los casos, esto es un beneficio dado que permite al usuario corregir errores de escritura usando la tecla Backspace, y solo cuando se está satisfecho con lo escrito en pantalla, se presiona Enter para enviar dicha cadena de texto al programa.

Este comportamiento se llama modo canónico o estándar. Toda la entrada se procesa en términos de líneas. Hasta que se complete una línea de entrada (generalmente cuando el usuario presiona Enter), la interfaz del terminal gestiona todas las pulsaciones de teclas, incluido el Backspace, y la aplicación no puede leer ningún carácter. El comportamiento contrario es el modo no canónico, donde la aplicación tiene un control mucho mayor sobre el procesamiento de los caracteres de entrada. 

Entre otras cosas, el controlador de la terminal de Linux ayuda al traducir caracteres de interrupción a señales (por ejemplo, deteniendo el programa cuando presiona Ctrl-C) y procesa de forma automática las teclas Backspace y Delete, para no tener que volver a implementar su comportamiento en cada programa que se escribe.

## Estructura `termios`

La configuración de la [terminal](https://www.gnu.org/software/libc/manual/html_node/Low_002dLevel-Terminal-Interface.html) se realiza mediante la estructura `termios` (archivo de cabecera `termios.h`):

```
struct termios
  {
    tcflag_t c_iflag;		/* input mode flags */
    tcflag_t c_oflag;		/* output mode flags */
    tcflag_t c_cflag;		/* control mode flags */
    tcflag_t c_lflag;		/* local mode flags */
    cc_t c_line;			 /* line discipline */
    cc_t c_cc[NCCS];		 /* control characters */
    speed_t c_ispeed;		/* input speed */
    speed_t c_ospeed;		/* output speed */
  };
```

Para utilizar el modo no-canónico de la terminal se debe modificar el campo `c_lflag`. [Local Modes](https://www.gnu.org/software/libc/manual/html_node/Local-Modes.html#Local-Modes)

