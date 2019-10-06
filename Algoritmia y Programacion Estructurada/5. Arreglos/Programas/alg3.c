//Cabecera
#include "head.h"               // Acceso a la libreria head.h
#define ciclo(var, tamaño) for(int var = 0; var < tamaño; var++)    //Macro para arreglo
int m = 0, n = 0;               //Declaracion de variables globales m = columnas, n = filas

// Funcion para obtener las columnas
int getM(){
    printf("Introduce el tamaño de la matriz\nColumnas: ");
    scanf("%d", &m);            //Escaneo de numero de columnas
    
    return m;                   //Valor de retorno que rellena el arreglo directamente
}

//Funcion para obtener ls filas
int getN(){         
    printf("Filas: ");
    scanf("%d", &n);            //Escaneo de numero de filas

    return n;                   //Valor de retorno que rellena el arreglo directamente
}

// Funcion Principal
int main(){
    // Declaracion de la Matriz
    int matriz[getM()][getN()];

    //Relleno de la matriz
    printf("*************\nRELLENO DE DATOS\n*************");
    ciclo(i, m){                //Relleno de datos en m
        ciclo(j, n){            //Relleno de datos en n
            printf("\nDato %d, %d: ",i + 1, j + 1);
            scanf("%d", &matriz[i][j]);     //Escaneo de la matriz dado el tamaño m,n
        }
    }

    //Transposicion de matriz
    //system("clear");
    printf("\tMATRIZ ORIGINAL\n\n");        
                                //Impresion de la matriz original
    ciclo(i, m){                //Impresion de las columnas
        printf("\t");           //Impresion de las filas
        ciclo(j, n){
            printf("| %d ", matriz[i][j]);  //Impresion de la matriz dado en m,n
        }
        printf("|\n");
    }
                                //Impresion de la matriz traspuesta
    printf("\tMATRIZ TRANSPUESTA\n\n");

    ciclo(i, n){                //Impresion inversa de las columnas
        printf("\t");           //Impresion inversa de las filas
        ciclo(j, m){
            printf("| %d ", matriz[j][i]);  //Impresion de la matriz dado en n,m (Al revez)
        }
        printf("|\n");
    }
    return 0;
}