#include "algs.h"
int main (){
    //Definicion de variables
    float metros, temp;
    int dec;
    
    //Lectruda de metros
    printf("Introduce la cantidad de metros\n");
    scanf("%f", &metros);
    //Lectura de variable decisiva
    printf("\nElige una opcion para convertir\n(1) Pies\n(2)Yardas\n(3)Millas\nRespuesta: ");
    scanf("%d",&dec);
    //Decision para conversion
    switch (dec)
    {
    //Caso para Pies
    case 1:
        printf("EL valor de %f metros en Pies es %f\n", metros, metros * 3.281);
        break;
    //Caso para Yardas
    case 2:
        printf("El valor de %f metros en Yardas es %f\n", metros, metros * 1.094);
        break;
    //Caso para Millas
    case 3:
        printf("El valor de %f metros en Millas es %f\n", metros, metros / 1609.344);
    default:
        break;
    }
    return 0;
}