#include <iostream>
#include <stdlib.h>
#include <math.h>
#define _USE_MATH_DEFINES


using namespace std;

int main(){
    // Variables
    int num;
    // Input

    cout << "Tamano n: ";
    cin >> num;

    // Creacion del grid
    float gauss[num][num];
    int offset = (num - 1) / 2;
    printf("%d\n", offset);
    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            gauss[i][j] = ( 1 / (2*M_PI)) * exp( -((pow(i-offset, 2)+pow(j-offset, 2)) / (2*M_PI)));
            printf("%f, ", gauss[i][j]);
        }
        printf("\n");
    }



    return 0;
}