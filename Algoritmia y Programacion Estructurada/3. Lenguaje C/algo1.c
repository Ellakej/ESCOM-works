#include "algs.h"

int main (){

    //Declaracion de variable
    int sueldoB;
    float sueldoN;

    //Entrada de archivos
    printf("Introduce tu sueldo base\n");
    scanf("%d", &sueldoB);

    //Comparativa de Rangos
    if(sueldoB >= 0 && sueldoB <= 1000){
        sueldoN = sueldoB - (sueldoB*.05);
    }else if(sueldoB >= 1001 && sueldoB <= 5000){
        sueldoN = sueldoB - (sueldoB*.15);
    }else if(sueldoB >= 5001){
        sueldoN = sueldoB - (sueldoB*.30);
    }

    //Salida de datos
    printf("\nEl sueldo neto %f\n", sueldoN);


    return 0;
}