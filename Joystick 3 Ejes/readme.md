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

<img src="https://github.com/antonioescamezalvarez/Ejemplos-STM32/blob/main/Joystick%203%20Ejes/Pinout.png" width="500" />

Primeramente seleccionamos el ADC1 y habilitamos 3 canales de lectura (uno para cada eje)

<img src="https://github.com/antonioescamezalvarez/Ejemplos-STM32/blob/main/Joystick%203%20Ejes/ADC.png" width="400" />

Configuramos el modo de conversión continua, el modo scan, y el DMA, indicamos el numero de conversiones (3 una por cada canal).

<img src="https://github.com/antonioescamezalvarez/Ejemplos-STM32/blob/main/Joystick%203%20Ejes/Config1.png" width="400" />

Indicamos en los Rank los diferentes canales que vamos a leer asi como los ciclos de reloj que vamos a emplear en cada conversión.

<img src="https://github.com/antonioescamezalvarez/Ejemplos-STM32/blob/main/Joystick%203%20Ejes/Config2.png" width="400" />

Por último habilitamos el DMA en modo Circular con incremento de la dirección de memoria y con un tamaño de palabra de HALF WORD

<img src="https://github.com/antonioescamezalvarez/Ejemplos-STM32/blob/main/Joystick%203%20Ejes/Config3.png" width="400" />
