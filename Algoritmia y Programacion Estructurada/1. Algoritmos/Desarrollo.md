# Algoritmos

_Consiste en desarrollar un poco de logica de programacion para resolver problemas mediante pseudocodigo_

## Problemas

* Dados 2 números enteros positivos, retornar el Máximo Común Divisor entre ellos
* Identifica el número menor de diez números positivos ingresados por el usuario, considera que los datos se ingresan de uno a uno.
* Determinar si 2 rectas son perpendiculares. Considera que el usuario ingresa las coordenadas de 2 puntos de cada una de ellas.
* Analiza la siguiente serie numérica, desarrolla su algoritmo y muestra los siguientes 7 números de la sucesión.
```
3	5	4	7	6	__	__	__	__	__	__	__
```
* Calcule la media de una serie de números positivos, suponiendo que los datos se leen uno a uno. **Un valor de cero como entrada indicará que se ha alcanzado al final de la serie de números positivos ingresados por el usuario.**

## Diagramas de Flujo

| Algoritmo 1 | Algoritmo 2 | Algoritmo 3 | Algoritmo 4 | Algoritmo 5 |
| :--- | :--- | :--- | :--- | :--- |
| ![Diagrama1](https://github.com/Ellakej/ESCOM-works/blob/master/Algoritmia%20y%20Programacion%20Estructurada/1.%20Algoritmos/assets/dia1.png) | ![Diagrama2](https://github.com/Ellakej/ESCOM-works/blob/master/Algoritmia%20y%20Programacion%20Estructurada/1.%20Algoritmos/assets/dia2.png) | ![Diagrama3](https://github.com/Ellakej/ESCOM-works/blob/master/Algoritmia%20y%20Programacion%20Estructurada/1.%20Algoritmos/assets/dia3.png) | ![Diagrama4](https://github.com/Ellakej/ESCOM-works/blob/master/Algoritmia%20y%20Programacion%20Estructurada/1.%20Algoritmos/assets/dia4.png) | ![Diagrama5](https://github.com/Ellakej/ESCOM-works/blob/master/Algoritmia%20y%20Programacion%20Estructurada/1.%20Algoritmos/assets/dia5.png)

## Códigos

| Algoritmo 1 | Algoritmo 2 | Algoritmo 3 | Algoritmo 4 | Algoritmo 5 |
| :--- | :--- | :--- | :--- | :--- |
| ![Codigo1](https://github.com/Ellakej/ESCOM-works/blob/master/Algoritmia%20y%20Programacion%20Estructurada/1.%20Algoritmos/assets/codigo1.png) | ![Codigo2](https://github.com/Ellakej/ESCOM-works/blob/master/Algoritmia%20y%20Programacion%20Estructurada/1.%20Algoritmos/assets/codigo2.png) | ![Codigo3](https://github.com/Ellakej/ESCOM-works/blob/master/Algoritmia%20y%20Programacion%20Estructurada/1.%20Algoritmos/assets/codigo3.png) | ![Codigo4](https://github.com/Ellakej/ESCOM-works/blob/master/Algoritmia%20y%20Programacion%20Estructurada/1.%20Algoritmos/assets/codigo4.png) | ![Codigo5](https://github.com/Ellakej/ESCOM-works/blob/master/Algoritmia%20y%20Programacion%20Estructurada/1.%20Algoritmos/assets/codigo5.png) |

## Funcionamiento
### Algoritmo 1 

* <b> Prueba de Escritorio </b>

|  A  |  B  |  res  |  A + B(MCD)  |
| --- | --- | --- | --- |
|  90 |  0  |   0   |      -       |
|  90 |  0  |   0   |      -       | 

* <b> Resultados de Salida </b>

| ENTRADA | PROCESO | SALIDA |
| --- | --- | --- |
| a <- 90 <br> b <- 0 <br> res <- 0 | Mientras (a != 0) && (b != 0) Hacer <br> res <- a % b <br> a <- b <br> b <- res | 90

* <b> Captura de Pantalla de la salida </b>

![Captura1](https://github.com/Ellakej/ESCOM-works/blob/master/Algoritmia%20y%20Programacion%20Estructurada/1.%20Algoritmos/assets/capt1.png)

### Algoritmo 2
 * <b> Prueba de Escritorio </b>
 
 | cont | a | temp |
 | --- | --- | --- |
 | 2 | -5 | -5 |
 | 2 | 0 | -5 |
 | 3 | 90 | -5 |
 | 4 | -40 | -40 |
 | 5 | 49 | -40 |
 | 6 | 89 | -40 |
 | 7 | 40 | -40 |
 | 8 | 9 | -40 |
 | 9 | 9 | -40 |
 | 10 | 1 | -40 |
 
 * <b> Resultados de Salida </b>
 
 | ENTRADA | PROCESO | SALIDA |
 | --- | --- | --- |
 | a <- 4 <br> a <- 2 <br> a <- 0 <br> a <- (-40) <br> a <- 100 <br> a <- 2 <br> a <- (-432) <br> a <- 9 <br> a <- 9 <br> a <- 1 | temp <- a <br> Mientras cont <= 10 Hacer <br> Si a < temp Entonces <br> a <- temp <br> cont ++ <br> Sino  <br> cont ++ | temp |
 
 * <b> Captura de Pantalla de la Salida </b>
 
![Captura2](https://github.com/Ellakej/ESCOM-works/blob/master/Algoritmia%20y%20Programacion%20Estructurada/1.%20Algoritmos/assets/capt2.png)

### Algoritmo 3

* <b> Prueba de Escritorio </b>

| Rx1 | Ry1 | Rx2 | Ry2 | Lx1 | Ly1 | Lx2 | Ly2 | temp |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 3 | 5 | 7 | -1 | 0 | 0 | 12 | 8 | - |
| 3 | 5 | 7 | -1 | 0 | 0 | 12 | 8 | -1 |

* <b> Resultados de Salida </b>
 
| ENTRADA | PROCESO | SALIDA |
| --- | --- | --- |
| (3,5),(7,-1) <br> (0,0),(12,8) | temp <- ((Ry2-Ry1)/(Rx2-Rx1))*((Ly2-Ly1)/(Lx2-Lx1)) <br> Si temp <= -0.9 && temp >= -1.9 Entonces <br> Escribir 'Las rectas son perpendiculares' <br> SiNo <br> Escribir 'Las rectas NO son perpendiculares' <br> FinSi | Las Rectas son perpendiculares

* <b> Captura de Pantalla de la Salida </b>

![Captura3](https://github.com/Ellakej/ESCOM-works/blob/master/Algoritmia%20y%20Programacion%20Estructurada/1.%20Algoritmos/assets/capt3.png)

### Algoritmo 4

* <b> Prueba de Escritorio </b>

| num | contador | switch |
| --- | --- | --- |
| 3 | 2 | F |
| 5 | 3 | V |
| 4 | 3 | F |
| 7 | 4 | V |
| 6 | 4 | F |
| 10 | 5 | V |
| 9 | 5 | F |
| 14 | 6 | V |
| 13 | 6 | F |
| 19 | 7 | V |
| 18 | 7 | F |
| 25 | 8 | V |

* <b> Resultado de Salida </b>

| ENTRADA | PROCESO | SALIDA |
| --- | --- | --- |
| n/a | Escribir num <br> Mientras contador<8 Hacer <br> Si !(switch) Entonces <br> num <- num+contador <br> Escribir num <br> switch <- Verdadero <br> contador <- contador+1 <br> SiNo <br> num <- num-1 <br> Escribir num <br> switch <- Falso <br> FinSi <br> FinMientras | 3 <br> 5 <br> 4 <br> 7 <br> 6 <br> 10 <br> 9 <br> 14 <br> 13 <br> 19 <br> 18 <br> 25

* <b> Captura de Pantalla de la salida </b>

![Captura4](https://github.com/Ellakej/ESCOM-works/blob/master/Algoritmia%20y%20Programacion%20Estructurada/1.%20Algoritmos/assets/capt4.png)


### Algoritmo 5

* <b> Prueba de Escritorio </b>

| num | temp | cont |
| --- | --- | --- |
| - | - | 2 |
| 8 | 8 | 2 |
| 6 | 14 | 3 |
| 7 | 21 | 4 |
| 0 | 7 | - |

* <b> Resultados de Salida </b>

| ENTRADA | PROCESO | SALIDA |
| --- | --- | --- |
| 8, 6, 7, 0, | cont <- 2 <br> Escribir "NUMERO ENTERO POSITIVO No. 1 INTRODUCE 0 PARA DETENER EL PROGRAMA" <br> Leer num <br> Mientras num != 0 Hacer <br> temp <- temp + num <br> Escribir "NUMERO ENTERO POSITIVO NO. " cont " INTRODUCE 0 PARA DETENER EL PROGRAMA" <br> Leer num <br> cont <- cont +1 <br> Fin Mientras <br> Escribir temp / (cont - 2) | 7

* <b> Captura de Pantalla de Salida </b>

![Captura5](https://github.com/Ellakej/ESCOM-works/blob/master/Algoritmia%20y%20Programacion%20Estructurada/1.%20Algoritmos/assets/capt5.png)

## Conclusiones

* El problema plantea resolver un Máximo Común Divisor, para ello se recurrió primero a buscar más información sobre este en el sitio web de [Wikipedia](https://es.wikipedia.org/wiki/M%C3%A1ximo_com%C3%BAn_divisor) <br> Tras revisar la información, se encontró el algoritmo de Euclides, lo cual llevó a realizar otra investigación en la web hasta encontrar un artículo que explica a detalle su uso, el artículo de [Khan Academy](https://es.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/the-euclidean-algorithm). <br>
El algoritmo de Euclides ayudo bastante, ya que se considera óptimo sin tanto desborde de recursos. <br>
Finalmente con la experiencia programando en otros lenguajes de programación, se implementó el algoritmo como pseudocódigo dentro del programa PSeInt. <br>
Se encontraron dificultades a lo largo del desarrollo por la sintaxis un tanto limitante del pseudocódigo, además de un posible error lógico en el operador AND (&) y el operador OR (||), PSeINT teóricamente está. invirtiendo la lógica de estos dos operadores puesto que el AND realiza la acción del OR y viceversa.

* El problema plantea escribir 10 números uno por uno, y finalmente determinar el menor del conjunto ingresado. Ya que no se pueden usar arreglos para acomular los valores y despues realizar un algoritmo de búsqueda lineal, se optó por usar 2 variables, una que se rellene con el nuevo número en curso, y el otro que se le asigne al inicio del programa esta misma variable para después mediante una iteración ir comparando con la primer variable, y en caso de ser menor que rellene la segunda variable.

*  Se intentó optimizar el código al realizar un ciclo que lea las variables de las coordenadas, pero no se encontró ninguna manera, asi que finalmente se tuvo que pedir variable por variable y finalmente en una sola variable temp realizar las operaciones

* Se observa de primera instancia que no hay datos de entrada, así que se procede directamente al proceso, se encontró que hay 2 secuencias dentro de la serie, una que resta -1 siempre y otra que suma un número cada ocasión que se adiciona al número a imprimir, se decidió hacer un if que vaya intercalando entre restar -1 y usar el contador de n+1 usando un booleano para cambiar 1 y 1 hasta terminar los 7 espacios faltantes de la serie.

* Se decidió usar la misma técnica usada en el algoritmo 2, usar 2 variables una para ir leyendo los datos del usuario y en otra acomular los datos e irlos sumando, esto hasta que el usuario detenga con un 0, se reciclo una variable (contador textual) aprovechando también el contador que determina entre qué debe dividirse

## Anexos

* Todos los códigos pueden mejorarse implementando validaciones 
* El algoritmo 3 en específico puede reducir su repetición de lectura de variables usando una iteración, pero por falta de tiempo no se logró reducir el código.
* Los códigos fuente están documentados, pero las capturas no, a excepción del código 3.
* Solo se consultó información para el primer algoritmo, la bibliografía de esta información se encuentra en la sección de conclusiones como pie de página.
* Como dato curioso, el algoritmo 2 primero se desarrollo en C++, y este no funcionó, pero copiando el algoritmo tal cual pero traducido a pseudocodigo en PSeInt, este funciono sin problemas.
