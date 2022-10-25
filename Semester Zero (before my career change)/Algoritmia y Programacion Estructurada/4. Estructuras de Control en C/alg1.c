#include <stdio.h>

int main(){

    float x = 0;                                    //Declaracion de variables

    printf("Introduce el valor de x: ");            //Lectura de variable x
    scanf("%f",&x);

    x = ((2*x) - 100) * x;                          //Calculo de datos

    printf("\nEl area del rectangulo es: %.2f\n", x);   //Impresion de datos

    return 0;
}