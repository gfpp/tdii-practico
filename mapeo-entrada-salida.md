# Mapa de memoria de entrada/salida 

En un procesador de 32 bits, el rango de memoria llega hasta 2^32 bytes (4GB). En la arquitectura ARM el espacio de memoria de dividie en 5 segmentos:
 1. el segmento _text_:
 1. el segmento de datos globales
 1. el segmento de datos dinámicos (stack y heap)
 1. el segmento para el manejo de excepciones
 1. el sistema operativo y de entrada/salida (I/O)

En las direcciones de memorias altas se mapean los dispositivos de entrada/salida de forma tal que al leer o escribir se está leyendo y escribiendo los registros de los dispositivos de E/S. Este método de comunicación con dispositivos de E/S se denomina _E/S mapeada en memoria_.

Bajo el sistema operativo GNU/Linux se puede consultar las direcciones de memoria de E/S desde el sistema de archivos `/proc`.

```
> sudo cat /proc/iomem 
00000000-3b3fffff : System RAM
  00008000-00bfffff : Kernel code
  00d00000-00e6ad0f : Kernel data
3f006000-3f006fff : dwc_otg
3f007000-3f007eff : dma@7e007000
3f00a000-3f00a023 : watchdog@7e100000
3f00b840-3f00b87b : mailbox@7e00b840
3f00b880-3f00b8bf : mailbox@7e00b880
3f100000-3f100113 : watchdog@7e100000
3f101000-3f102fff : cprman@7e101000
3f104000-3f10400f : rng@7e104000
3f200000-3f2000b3 : gpio@7e200000
3f201000-3f2011ff : serial@7e201000
  3f201000-3f2011ff : serial@7e201000
3f202000-3f2020ff : mmc@7e202000
3f212000-3f212007 : thermal@7e212000
3f215000-3f215007 : aux@7e215000
3f300000-3f3000ff : mmcnr@7e300000
3f980000-3f98ffff : dwc_otg
```
Por ejemplo: la direcciones de GPIO están entre `3f200000-3f2000b3`.

Los registros de E/S de la Raspberry Pi se corresponden con los registros propios del SoC (System On Chip) BCM2835.

## Entradas y salidas de propósitos generales

```
> dmesg | grep gpiomem
[    0.278846] gpiomem-bcm2835 3f200000.gpiomem: Initialised: Registers at 0x3f200000

```

Los registros para el control de las entradas/salidas de propósitos generales (GPIO, General Purpose Input/Outpu) son:
 * `GPFSEL0...5` (GPIO Function Select register): fija la funcionalidad del pin
 * `GPSET0,1` (GPIO Pin Output Set register): pone en alto el valor del pin
 * `GPCLR0,1` (GPIO Pin Output Clear register): pone en bajo el valor del pin
 * `GPLEV0,1` (GPIO Pin Level register): obtener el valor del pin

