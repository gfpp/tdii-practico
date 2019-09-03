# Manejo de GPIO mediante `sysfs`

## Introducción

*Sysfs* es un sistema de archivo virtual (similar a `/proc`) disponible en las versiones recientes del Kernel de Linux.
Permite tener acceso a dispositivos y drivers que de otra forma serían solo accesibles dentro del espacio de Kernel restringido.

El sistema de archivos `sysfs` se encuentra montado en el directorio `sys`.
Los directorios en `sysfs` forma una estructura jerárquica de dispositivos.

Ejemplo:
```
> sudo cat /sys/kernel/debug/gpio
```

* `led0`: se le llama `ACT LED` (activity LED) y por defecto muestra la actividad de la memoria microSD.
* `led1`: se le llama `PWR LED` e indica alimentación en la placa.

## Interactuando con los LED onboard

```
> cd /sys/class/leds/led0
> cat trigger
```
Se puede ver la funcionalidad actual del `led0` que por defecto indica `mm0`.

Cambiar a modo `heartbeat`
```
> sudo sh -c "echo heartbeat > trigger"
```

Cambiar a modo "manual", encender y apagar el LED.
```
> sudo sh -c "echo none > trigger"
> sudo sh -c "echo 1 > brightness"
> sudo sh -c "echo 0 > brightness"
```

Volver a fijar el modo de actividad de la memoria microSD.
```
> sudo sh -c "echo mmc0 > trigger"
```

## Interactuando con GPIO

 * Ir al directorio donde se mapea el `gpio` y exportar el GPIO a utilizar, en este caso el GPIO21
```
> cd /sys/class/gpio
> sudo sh -c "echo 21 > export"
```
 * Moverse al directorio `gpio21` creado a exportar el GPIO, configurar la dirección y escribir los valores
```
> cd gpio21
> sudo sh -c "echo out > direction"
> sudo sh -c "echo 1 > value"
> sudo sh -c "echo 0 > value"
```
 * Revertir la exportación del GPIO21
```
> cd ..
> sudo sh -c "echo 21 > unexport"
```
