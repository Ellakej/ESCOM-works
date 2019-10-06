#include "H1.h"
int main (void)
{
	printf ("Introduce la cantidad de cambio que se realizara: ");
	scanf ("%d",&c);
	di=c/10;
	c=c-(di*10);
	ci=c/5;
	c=c-(ci*5);
	dos=c/2;
	c=c-(dos*2);
	un=c/1;
	printf("El cambio se devolvera en %d monedas de 10, %d monedas de 5, %d monedas de 2 y %d monedas de 1\n",di, ci, dos, un);
}
