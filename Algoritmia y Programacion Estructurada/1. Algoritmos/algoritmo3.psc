Algoritmo algoritmo3
	// Lectura de datos de la primer recta
	Escribir 'Escribe las coordenadas de la primer recta'
	Leer Rx1
	Escribir 'Escribe la coordenada y1 del primer par de coordenadas, primer Recta'
	Leer Ry1
	Escribir 'Escribe la coordenada x2 del segundo par de coordenadas, primer Recta'
	Leer Rx2
	Escribir 'Escribe la coordenada y2 del segundo par de coordenadas, primer Recta'
	Leer Ry2
	// Lectura de datos de la segunda recta
	Escribir 'Escribe la coordenada x1 del primer par de coordenadas, segunda Recta'
	Leer Lx1
	Escribir 'Escribe la coordenada y1 del primer par de coordenadas, segunda Recta'
	Leer Ly1
	Escribir 'Escribe la coordenada x2 del segundo par de coordenadas, segunda Recta'
	Leer Lx2
	Escribir 'Escribe la coordenada y2 del segundo par de coordenadas, segunda Recta'
	Leer Ly2
	// Aplicada la formula del punto pendiente y al mismo tiempo multiplicar ambas para sacar la pendiente
	temp <- ((Ry2-Ry1)/(Rx2-Rx1))*((Ly2-Ly1)/(Lx2-Lx1))
	// En caso de que sea menor o igual a -1 sera perpendicular, si no entonces no
	Si temp <= -0.9 && temp >= -1.9 Entonces
		Escribir 'Las rectas son perpendiculares'
	SiNo
		Escribir 'Las rectas NO son perpendiculares'
	FinSi
FinAlgoritmo

