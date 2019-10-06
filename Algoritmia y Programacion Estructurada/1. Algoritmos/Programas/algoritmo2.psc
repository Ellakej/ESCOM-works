Algoritmo algoritmo2
	//Inicializacion de variable contadora en -2 para reciclarla y usarla para imprimir en pantalla tambien
	cont <- 2
	
	//Primer entrada de Datos
	Escribir 'Ingresa el numero 1'
	Leer a
	
	//Declaracion de variable temporal temp
	temp <- a
	
	//Iteracion que permite rellenar 10 numeros e irlos acomulando en temp
	Mientras cont<=10 Hacer
		
		//Lectura de datos
		Escribir 'Ingresa el numero ',cont
		Leer a
		
		//Aumentador
		cont <- cont+1
		
		//Si el valor introducido es menor que temp, entonces temp ahora adopta ese valor
		Si a<temp Entonces
			temp <- a
		FinSi
	FinMientras
	
	//Impresion del numero menor almacenado en temp
	Escribir 'El menor numero fue ',temp
FinAlgoritmo

