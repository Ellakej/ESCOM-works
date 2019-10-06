Algoritmo algoritmo1
	//Declaracion de la variable resultado igualada a 0
	res <- 0
	
	//Lectura de Datos IN
	Escribir 'Introduce el primer numero'
	Leer a
	Escribir 'Introduce el segundo numero'
	Leer b
	Escribir 'Introduce el tercer numero'
	Leer c
	Escribir 'Introduce el cuarto numero'
	Leer d
	
	//Iteracion que define la cantidad de divisores que tiene un numero, aplicando el Algoritmo de Euclides
	Mientras (a!=0) Y (b!=0) Hacer
		res <- a MOD b
		a <- b
		b <- res
	FinMientras
	
	Mientras (a!=0) Y (c!=0) Hacer
		res <- a MOD c
		a <- c
		c <- res
	FinMientras
	
	Mientras (a!=0) Y (d!=0) Hacer
		res <- a MOD d
		a <- d
		d <- res
	FinMientras
	
	
	//Impresion de Resultados OUT
	Escribir 'El MCD es ',a
FinAlgoritmo
