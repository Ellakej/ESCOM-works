Algoritmo sin_titulo
	
	s<-0 //inicializacion de valores
	j<-3.14 //Dato que desamos calcular 
	
	
	Para i<-1 Hasta j Hacer //Un for que va a presindir desde cero hasta que el valor de "j"
		
		Si i%2==0 Entonces //Estructura if que va a identificar si el contador "i" esta en un numero par si es asi hara una iperacion sino gara otra 
			s <- s-(4/((i*2)-1)) //Operacin de TAYLOR
		Sino
			s <- s+(4/((i*2)-1))
		Fin Si
	Fin Para
	
	Escribir "Resultado: ",s //IMPRESION DE RESULTADOS		
	
FinAlgoritmo
