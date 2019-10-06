#include "algs.h"
int main (){
    //Declaracion de variables
    int a, b, c;
    

    printf("Introduce el numero 1\n");
    scanf("%d", &a);

    printf("Introduce el numero 2\n");
    scanf("%d", &b);

    printf("Introduce el numero 3\n");
    scanf("%d", &c);

    if(a >= b && a >= c){
        printf("El numero mayor es %d\n", a);
    }else if( b >= a && b >= c){
        printf("El numeor mayor es %d\n", b);
    }else if( c >= a && c >= b){
        printf("El numero mayo es %d\n", &c);
    }
    
    


    return 0;
}