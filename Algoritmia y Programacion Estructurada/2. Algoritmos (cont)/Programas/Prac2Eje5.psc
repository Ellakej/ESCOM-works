Funcion res <- fibo ( n ) //Obtencion de variable e inicio de funcion fibo
	Si n!=0 Entonces //si el valor es igual a cero emprezara a realizar el valor recursivo ya que sale del if 
		
		res<-fibo(n-1)+2 //Operacion que suma los numeros anteriores cuando luego inicia la recursividad 
		
	Fin Si
Fin Funcion

Algoritmo sin_titulo
	n<-0 //Inicializacion de variable 
	Escribir "Ingrese el valor para la sucecion" 
	Leer n //Lectura de variable del valor a buscar
	m<-fibo(n) //envio de variables a la funcion fibonacci
	Escribir m+n //impresion de valores teniendo en cuanta el premer valor usado 
FinAlgoritmo


