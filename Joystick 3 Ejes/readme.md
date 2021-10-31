## Joystick 3 Ejes
Este tipo de Joysticks emplean potenciometros para medir la posición en cada eje.

Por defecto viene precableado el eje Z el cual es rotativo.

El cableado es el siguiente:
* Azul (2 cables) ➡️  Son los dos cables del pulsador que trae
* Rojo            ➡️  3V3
* Blanco          ➡️  GND
* Negro           ➡️  Pin de lectura del STM32

Tenemos que soldar los dos potenciometros externos siguiendo el mismo esquema, la patilla intermedia es la que irá al microcontrolador.

Para leer los 3 ejes vamos a hacer uso del DMA para liberar al microcontrolador de dicha tarea.

El pinout que hemos seleccionado es el siguiente

<img src="https://github.com/antonioescamezalvarez/Ejemplos-STM32/blob/main/Joystick%203%20Ejes/Pinout.png" width="600" />
