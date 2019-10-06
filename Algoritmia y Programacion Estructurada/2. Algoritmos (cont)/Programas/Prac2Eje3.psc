Funcion res <- fibo ( n ) //Obtencion de valores que desea para la variable "res"
	Si n==0 o n==1 Entonces //Comparacio que indica el fin del ciclo e inicio de la recursividad para la obtencion de las sumas resecivas de Fibonacci
		
		res<-1 //Designacion para inicio de la funcion de recursividad e inicio de suma de la misma 
		
	Sino
		
		res<-fibo(n-1)+fibo(n-2)//Operacion de fibonacci en la cual el valor "n" sera intercambiado una vez que la condicion se cumpla la condicion e inicie la recursividad 
		
	Fin Si
Fin Funcion

Algoritmo sin_titulo
	
	n<-0 //Inicializacion de variables 
	
	Mientras n!=25 Hacer //Mientras que indica que el valor n sera enviado a la funcion "fibo" 25 veces hasta que se cumplete la sucesion numerica 
		m<-fibo(n)//Asiganacion para la variable "m" y envio de la variable "n" para la funcion "fibo"
		Escribir "Fibonacci: ", m //Impresion de "m"
		n<-n+1//Aumento con respecto a uno para "n"
	Fin Mientras

FinAlgoritmo
