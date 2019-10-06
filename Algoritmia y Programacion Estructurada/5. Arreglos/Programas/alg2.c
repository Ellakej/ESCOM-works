#include "head.h"
#define ciclo(arreglo) for(int i = 1; i <= (sizeof(arreglo)/4); i ++)   //Macro para relleno y consulta del arreglo
int n = 0, media = 0, sum = 0;              //Variables Globales
float desv = 0, var = 0;

int numeroArreglo(){    // Funcion que determina el tamaño del arreglo
    printf("Introduce la cantidad de datos a leer: "); 
    scanf("%d", &n);    //Escaneo de la cantidad de datos

    return n;
}
int main(){
    int datos[numeroArreglo()];

    // Ciclo de recoleccion de datos
    ciclo(datos){                          //Uso de la macro Ciclo para recoger datos en el arreglo semi-dinamico
        printf("Introduce el valor %d: ", i);
        scanf("%d", &datos[i]);            //Recoleccion de datos en la posicion i
    }
    
    // Obtenemos la media
    ciclo(datos){       //Uso de la macro Ciclo para sumar los datos de la media             
        sum += datos[i];
    }
    media = sum/n;      //Se reescribe el valor de la media dividiendola entre el numero total de elementos en el arreglo
   
   // Desviacion estandar
   ciclo(datos){        //Uso de la macro Ciclo para ir acomulando la diferencia del valor en i con la media
       desv += (datos[i] - media);
   }
   desv = desv * (1 / ((float)n-1));        //Sobreescripcion de la variable desv para su calculo final con la otra seccion del calculo 

   //Varianza
   var = sqrt((double)desv);                //Raiz cuadrada de la desviacion para sacar la varianza

   //Impresion de resultados
    system("clear");    //Limpieza de la consola
    printf("\n******\nLa media es: %d\n\nLa desviacion estandar es: %.4f\n\nLa varianza es: %.4f\n\n*******\n", media, desv, var);
    return 0;
}