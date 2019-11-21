# Técnicas Digitales II - Proyecto

Los siguientes ejercicios a desarrollar en los prácticos de laboratorio constituyen la columna vertebral del proyecto:

1. Escribir una estructura switch-case en código assembly del ARM. Esto permite implementar un menú.

1. Escribir en código assembly del ARM la siguiente función escrita en C. 
```
void retardo (unsigned long int a)
{
  while (a) a--;
}
```
1. Implementar el control de acceso al sistema mediante password. Se debe mostrar un mensaje: `"Ingrese su password de 5 dígitos:"`, mostrar por cada dígito entrado un `*` y comparar con una clave ya cargada en memoria. Si la clave es correcta imprimir un mensaje de `"Bienvenido al Sistema"` y si no lo es imprimir un mensaje de `"Password no válida"`. Después de 3 intentos el programa aborta.

1. Se dispone de la placa Raspberry 3 modelo B con puertos de salida y de entrada (GPIO). Se desea implementar un bucle que finalice con una tecla apretada y que saque por las salidas lo que está presente en las entradas.

1. Con la misma placa del ejercicio anterior implementar una secuencia de luces denominada "Auto fantástico" y finalizar con una tecla apretada. (Usar algoritmo).

1. Implementar mediante el uso de una tabla de datos en lugar de algoritmo la secuencia de luces denominada "La carrera".

1. Con un hardware adicional a la placa Raspberry conectar un conversor analógico/digital con 8 canales analógicos de manera que se puedan leer cada uno de ellos mediante una rutina que deberá escribir.

1. Comunicar la placa Raspberry 3 con una PC a través de RS-232. La comunicación implica programar los parámetros de comunicación: baud rate, bits de datos, bit de paridad y bits de parada. Implementar rutinas de transmisión y de recepción usando las señales de handshake: DTR, RTS, DSR y CTS.

## Proyecto

Este proyecto consiste en integrar dichos ejercicios de la siguiente manera:

a. Realice un programa a fin de que el usuario pueda seleccionar desde un menú, una de ocho secuencias de luces posibles. Cuatro de ellas serán comunes para todos los proyectos y son: "El auto fantástico", "El choque", "La apilada" y "La carrera". Las otras cuatros serán propias de cada grupo y se deberán implementar dos de ellas con algoritmo y las dos restantes por medio de la técnica de tablas de datos.

b. Implemente el control de acceso a este menú mediante password.

c. Cada vez que el usuario seleccione una secuencia el programa deberá cambiar la pantalla para indicar cual secuencia está ejecutándose y como hacer para salir de la misma. Al optar por abandonar la actual, el programa deberá regresar al menú principal inmediatamente sin completar la secuencia que se está desarrollando y apagando todas las luces.

d. Permita la posibilidad de controlar la velocidad de cada secuencia. Presionando la flecha hacia arriba se incrementará la velocidad y presionando la flecha hacia abajo se reducirá. Introduzca el sensado de las teclas oprimidas en el lugar apropiado de su programa a fin de percibir la reacción del sistema en forma inmediata, independiente de la velocidad actual. La velocidad ajustada en cada secuencia deberá conservarse entre llamadas a diferentes secuencias.

e. El valor inicial correspondiente a la velocidad de las secuencias deberá ingresarse mediante la lectura del estado de los potenciómetros que están conectados a las entradas analógicas del conversor A/D.

f. Generar una opción en el programa que permita establecer dos modos de trabajo: local y remoto. En modo local las secuencias de luces se ejecutarán en los LEDs que se encuentran en el hardware adicionado a la placa Raspberry donde se ejecuta el programa. En modo remoto las secuencias se ejecutarán sobre el hardware adicional colocado en otra Raspberry y conectada a la que ejecuta el programa mediante un cable serie RS-232. Se podrá usar el mismo programa para implementar esta opción en las dos Raspberry o realizar uno principal y otro secundario.

g. Como opción genere una sección destinada a establecer las velocidades iniciales de las secuencias realizando el ajuste de los potenciómetros.

## Condiciones de presentación 

El proyecto deberá ser presentado en la fecha establecida oportunamente (no deberá en ningún caso superar la última semana de clase), y estará en condiciones de hacerlo todo programa que cumpla con las especificaciones mínimas enunciadas anteriormente. El trabajo se llevará a cabo en grupo de dos estudiantes, que al momento de la presentación deberán estar en condiciones de contestar indistintamente cualquier pregunta, demostrando en todo momento precisión, claridad conceptual de los temas involucrados en el proyecto, y contribución personal al programa. Hay que recordar que el proyecto es una evaluación con una modalidad diferente a la tradicional, pero evaluación al fin. Por lo tanto la nota es personal, pudiendo darse el caso eventualmente de diferente notas entre los miembros de un mismo equipo, llegando incluso al aplazo de alguno de ellos. 

Al proyecto se le podrán agregar toda clase de opciones que sean pertinentes con lo esbozado anteriormente y que significará una mejor evaluación. Estas características deberán ser claramente remarcadas en la presentación.

Si por cualquier motivo no se presentara el proyecto en la fecha indicada, se deberá presentar antes del examen final como requisito de la parte práctica del mismo.
