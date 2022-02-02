Una NTC es un resistencia variable con coeficiente negativo respecto a la temperatura, por tanto podemos saber la temperatura que hace midiendo la resistencia que tiene nuestra NTC... pero el problema que nos encontramos es que esta variación no es lineal si no que esta curva se puede ajustar a una ecuacion de orden 2 o 3, en internet se pueden encontrar muchas ecuaciones para parametrizar la curva e incluso si el rango de variación de la temperatura es pequeño se puede linealizar la ecuación.

En nuestro caso utilizamos la ecuación de Steinhart-Hart (3 parámetros) la cual podemos encontrar detallada en el pdf que hay subido.

Basicamente esta ecuación necesita calcular 3 parámetros A B y C, para ello realizamos 3 medidas de resistencia de la NTC a diferentes temperaturas, el método mas fácil es medir en agua con hielo (0ºC) agua hirviendo (100ºC) y a temperatura ambiente, introducimos los datos y obtenemos los valores de A B y C.

Cabe destacar que la conexión de la NTC se realiza en la configuración de divisor de tensión.

<img src="https://github.com/antonioescamezalvarez/STM32/blob/main/NTC/NTC%20Conexion.jpg" width="400" height="300" />
