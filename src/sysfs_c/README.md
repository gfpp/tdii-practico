# Manejo de GPIO con el sistema de archivos `sys`

El programa de ejemplo `blink_sysfs` muestra cómo parpadear un LED conectado a un GPIO utilizando el sistema de archivos `sys`. También muestra como capturar la señal `Ctrl+C` para detener el programa y poder apagar el LED antes de salir.


Las funciones necesarias para el manejo de GPIO mediante el `sysfs` están separadas en los archivos `gpio_sysfs.h` y `gpio_sysfs.c` para poder utilizarlas en otra aplicación. Esta aplicación debe incluir el archivo de cabecera `gpio_sysfs.h` y debe compilarse junto al archivo fuente `gpio_sysfs.c`.

Compilar:
```
> gcc -Wall -std=c90 blink_sysfs.c gpio_sysfs.c
```

