Algoritmo algoritmo4
	//Inicializacion de variables num, contador y el booleano switch
	num <- 3
	contador <- 2
	switch <- Falso
	
	//Lectura del numero
	Escribir num
	
	//Iteracion que llega hasta 8 puesto que una de las 2 formulas requiere un aumento 8 veces
	Mientras contador<8 Hacer
		
		//Interruptor que alterna entre las 2 formulas
		Si !(switch) Entonces
			//Formula que agrega n + 1 al valor actual
			num <- num+contador
			Escribir num
			switch <- Verdadero
			contador <- contador+1
		SiNo
			//Formula que resta 1 al valor actual
			num <- num-1
			Escribir num
			switch <- Falso
		FinSi
	FinMientras
FinAlgoritmo

