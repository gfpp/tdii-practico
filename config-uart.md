# Configuración para utilizar la UART

Agregar al final del archivo `/boot/config.txt` las siguientes líneas

```
dtoverlay=pi3-miniuart-bt
dtoverlay=pi3-disable-bt
enable_uart=1
```

