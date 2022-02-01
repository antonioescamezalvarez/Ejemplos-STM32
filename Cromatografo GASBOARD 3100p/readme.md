El cromatógrafo funciona por UART a 9600 con la configuración estandar de 8N1.

El pinout del conector DB9 es el siguiente (Queda pendiente mirar el pinout del conector de RS232 del Gasboard):

<img src="https://github.com/antonioescamezalvarez/STM32/blob/main/Cromatografo%20GASBOARD%203100p/Pinout.jpeg" width="200" />

El dispositivo solamente envia la trama response despues de recibir un request por parte del master.

El request consiste en la trama 0x11 0x01 0x01 0xED.

El response por su lado consiste en 3 bytes de cabecera (no los necesitamos consultar) y seguidos de la composición de cada gas que se calcula como:
CO % = ([BYTE3]*256 +[BYTE4])/100

<img src="https://github.com/antonioescamezalvarez/STM32/blob/main/Cromatografo%20GASBOARD%203100p/Codigo.png" width="500" />
