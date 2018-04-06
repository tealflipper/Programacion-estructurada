#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "prototype.h"



int main()
{
	int again;
	while (again){
		int n, i, j, xp,yp,temp;
		int semilla=time(NULL);
		srand(semilla);
		printf("Ingrese el numero de casillas: ");
		scanf("%d",&n);
		int ships,cont=1;
		printf("Ingrese el numero de barcos: ");
		scanf("%d",&ships);
		int dev[n][n], user[n][n];
		prepBoard(n,dev,user,ships );
		play(n,user,dev,&cont,ships);
		again=continues();
	}
	return 0;
}
