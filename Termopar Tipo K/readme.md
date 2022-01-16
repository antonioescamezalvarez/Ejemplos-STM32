Es importante entender el funcionamiento del módulo MAX6675.
Primeramente comentar que este módulo funciona por SPI.
Si observamos el datasheet podemos ver que cuando seleccionamos el dispositivo poniendo a bajo el CS el módulo nos va a enviar 16 bits con la siguiente configuración
[0][15][14][13][12][11][10][9][8][7][6][5][4][3][2][1][0][][]
