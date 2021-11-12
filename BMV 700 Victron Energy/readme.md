El BMV 700 envia los datos por uart a 19200 baudios por segundos. 

En nuestro caso, el único valor que nos insteresa es el SOC de la batería, el BMV 700 envia continuamente todos los parámetros que monitoriza (tensión, intensidad etc...) el objetivo de este programa es de captar únicamente el porcentaje de la batería y enviarlo por uart al pc donde se gestiona el resto de la lógica.

El pinout del BMV 700 es el siguiente:

<img src="https://github.com/antonioescamezalvarez/Ejemplos-STM32/blob/main/BMV%20700%20Victron%20Energy/BMV700%20Pinout.png" width="500" />

En nuestro caso haremos uso del GND y del pin TX (cabe destacar que en mi caso el pinout no coincide ya que RX y TX estan cambiados).

<img src="https://github.com/antonioescamezalvarez/Ejemplos-STM32/blob/main/BMV%20700%20Victron%20Energy/bmv702-2.jpg" width="500" />


