#include "head.h"               // Cabecera head.h con las variables ya declaradas

int numMayor(){
    int temp = 0;

    for (int i = 0; i < 100; i++){              //Ciclo que recorre todo el arreglo para encontrar el numero mayor
        if (num[i] >= temp){    //Condicional que reescribe el valor maximo en temp
            temp = num[i];
        }
    }// Cierre del 1er ciclo

    for (int i = 0; i < 100; i++){              //Ciclo que elimina el maximo valor del arreglo
        if(num[i] == temp){
            num[i] = 0;
            break;
        }
    }// Cierre del 2do ciclo

    return temp;
}

int main(){                     // Funcion main

    int key = 1;

    // Lectura de datos
    for(int i = 0; i <= 100; i++){              // Ciclo que recorra cada uno de los datos hasta el 100
        printf("\nIntroduce un numero: ");      // Escaneo de datos en la posicion i
        scanf("%d", &num[i]);

        if(num[i] == 0){        // Condicional que rompe el ciclo en caso de que el digito introducido sea 0
            break;
        }
    }

    for (int i = 1; i <= 3; i++)                //Ciclo para multiplicar los 3 primeros numeros
    {
        key *= numMayor();      //Multiplicador
    }
                                //Escritura de resultado;
    printf("El resultado de la multiplicacion es: %d\n", key);
    return 0;
}