Algoritmo algoritmo1
	//Declaracion de la variable resultado igualada a 0
	res <- 0
	
	//Lectura de Datos IN
	Escribir 'Introduce el primer numero'
	Leer a
	Escribir 'Introduce el segundo numero'
	Leer b
	
	//Iteracion que define la cantidad de divisores que tiene un numero, aplicando el Algoritmo de Euclides
	Mientras (a!=0) Y (b!=0) Hacer
		res <- a MOD b
		a <- b
		b <- res
	FinMientras
	
	//Impresion de Resultados OUT
	Escribir 'El MCD es ',a+b
FinAlgoritmo
