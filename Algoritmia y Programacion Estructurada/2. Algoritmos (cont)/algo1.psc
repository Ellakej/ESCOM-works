Proceso algoritmo1
	//Inicializacion de contador en 0
	cont<-0
	
	//Instruccion de Proceso antes del ciclo (Do-while)
	Repetir
		Si cont MOD 2==0 Entonces
			pares<-pares+cont+2
		Sino
			impares<-impares+cont
		FinSi
		cont<-cont+1
	Hasta Que cont==1000
	Escribir 'Promedio Pares: ',pares/(cont/2),' Numeros Pares: ',pares,' Promedio Impares: ',impares/(cont/2),' Numeros Imapares: ',impares
FinProceso

