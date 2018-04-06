#ifndef mine_Sweeper
#define mine_Sweeper
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int dificulty(ships){
	int dif,turnos,i;
	printf("Seleccione la dificultad de juego: \n");
	printf("Facil: 1\nMediano: 2\nDificil: 3\n");
	scanf("%d", &dif);
	if (dif!=1 || dif!=2 || dif!=3){
		printf("Opcion no valida, intente de nuevo.\n\n\n");
		dificulty(ships);
	}else{
		//regresa el numero de turnos 
		for(i=1;i<=3;i++){
			if(dif==i){
				turnos=ships*i*2;
			}
		}
	}
	return turnos;
}
#endif
