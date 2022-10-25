Algoritmo algoritmo5
	//Inicializacion de variable cont en 2, para sicronizarse con impresion en pantalla
	cont <- 2
	
	//Lectura de datos
	Escribir "NUMERO ENTERO POSITIVO No. 1 INTRODUCE 0 PARA DETENER EL PROGRAMA"
	Leer num
	
	//Iteracion condicional que sigue leeyendo numeros hasta que el usuario introduzca un 0
	Mientras num != 0 Hacer
		
		//Acomulador
		temp <- temp + num
		
		//Letura de datos
		Escribir "NUMERO ENTERO POSITIVO NO. " cont " INTRODUCE 0 PARA DETENER EL PROGRAMA"
		Leer num
		
		//Contador
		cont <- cont +1
	Fin Mientras
	
	//Impresion de datos ya con la formula para promediar
	Escribir temp / (cont - 2)
FinAlgoritmo
