## Temporizador
Esta librería se utiliza para controlar tareas periódicas como el encendido de un motor, parpadeo de un led etc..., se indica el tiempo que va a estar encendido y el tiempo que va a estar apagado en milisegundos.

Una vez esta el temporizador inicializado se pone en marcha con la función temporizador_start(&temporizador) y por último en el bucle while se actualiza el temporizador con la función comprobar_temporizador(&temporizador)
