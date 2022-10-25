#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

unsigned int microsegundos = 1000;

void gotoxy(int x,int y){
   printf("%c[%d;%df",0x1B,y,x);
 }

int main() {
    //Tamaño del canvas
    int columnas, filas;

    columnas = 60;
    filas = 20;


	// Ciclo principal
	int n = 0;
	int x_off = 0;
	int y_off = 0;

	int x_dir = 1;
	int y_dir = 0;

	bool skip_check = false;

	int xx = 0;
	int yy = 0;

  system("clear");

	while (n < 1292) {
		n++;

		gotoxy(xx, yy);
    printf("#");

		xx += x_dir;
		yy += y_dir;

		// Cambio horizonal de direccion
		if (!skip_check) {
			if (xx >= columnas-1 && y_dir == 0) {
				x_dir = 0;
				y_dir = 1;
				columnas--;
				y_off++;

				skip_check = true;
			} else if (xx <= x_off && y_dir == 0) {
				x_dir = 0;
				y_dir = -1;
				x_off++;

				skip_check = true;
			}else if (yy >= filas-1 && x_dir == 0) {
				x_dir = -1;
				y_dir = 0;
				filas--;

				skip_check = true;
			} else if (yy <= y_off && x_dir == 0) {
				x_dir = 1;
				y_dir = 0;

				skip_check = true;
			}
		} else {
			skip_check = false;
		}

		usleep(microsegundos);
	}
}
