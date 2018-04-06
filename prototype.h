#ifndef prototype
#define prototype
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SHIP 1
//start prepboard modules
void GenRandNum(int a, int b, int *c){

	*c=rand()%(b-a+1)+a;
}
void cleanBoard( int n, int array[n][n]){
	int i, j;
	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			array[i][j]=0;
		}
	}
}
void seedShips(int n,int array [n][n],int ships){//n is the board size
	int x,y,i;
	for (i=0; i<ships;i++){
		GenRandNum(0,n,&x);
		GenRandNum(0,n, &y);
		array[y][x]=SHIP;
	}
}
//deploy is both used in prepboard and play
void deploy(int n, int dev[n][n],int user[][n]){
    int i,j;
	for (i=0;i<n; ++i)
	{
		printf("%3d", i);
	}
	printf("\n");
	for (i=0; i<n; i++){
		printf("%2d", i);
		for (j=0; j<n; j++){
			if(user[i][j]==0){
				printf("[-]");
			}else{
			    if(dev[i][j]!=SHIP){
					printf("[*]");
			    }else{
			    	printf("[X]");
			    }
			}
		}
		printf("\n");
	}
}
//end prepboard modules
void prepBoard(int n,int dev[][n], int user[][n],int bombs){
    int y,x,isShip;
	cleanBoard(n,dev);
	cleanBoard(n,user);
    seedShips(n,dev,bombs);
	int i, j;
	//nos dice donde estan los submarinos
	/*for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			if(dev[i][j]!=SHIP){
				user[i][j]=0;
			}else{
				user[i][j]=1;
			}
		}
	} */
}
//play modules start

//dificulty returns the amount of turns that are going to be given to the player
int dificulty(int ships){
	int dif,turnos,i;
	int d[]={3,2,1};
	printf("Seleccione la dificultad de juego: \n");
	printf("Facil: 1\nMediano: 2\nDificil: 3\n");
	scanf("%d", &dif);
	if (dif!=1 && dif!=2 && dif!=3){
		printf("Opcion no valida, intente de nuevo.\n\n\n");
		dificulty(ships);
	}else{
		//regresa el numero de turnos
		for(i=1;i<=3;i++){
			if(dif==i){
				turnos=ships*d[i-1]*2;
			}
		}
	}
	return turnos;
}
//Verifies if an x,y cordinate is valid for a playspace
int isValid(int y,int x,int n){
    int	z=0;// is false
	if (y>=0 && y<n && x>=0 && x<n){
		z=1;//is true
	}
	return z;
}
//reads a valid try from user
void readValidTry(int n,int dev[][n],int user[][n]){
	int x,y;
	scanf("%d",&x);
	scanf("%d",&y);
	int z=isValid(x,y,n);
	if (!z){
		printf("Cordenadas no validas\nIntente de nuevo:\n");
		readValidTry(n,dev,user);
	}else{
		user[y][x]=1;
	}
	printf("[%d,%d]\n",x,y );
}
//uses sunk and tries to calculate the score
void score(){
//formula: 10000/(tries-sunk)
}
//counts the number of ships remaining
int shipCount(int n,int dev[][n],int user[][n],int ships){
	int numShips=0,i,j;
	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			if(dev[i][j]==SHIP && user[i][j]==1){
				numShips++;
			}
		}
	}
	int c=ships-numShips;
	return c;
}
//decide if its a win
void wins(int n,int dev[][n],int user[][n],int ships, int *cont){
	int remShips=shipCount(n,dev,user,ships);
	if (remShips==0){
		printf("Ganaste!!!!\n");
		*cont=0;
	}else{
		*cont=1;
	}
}

void play(int n,int user[][n], int dev[][n], int *cont, int ships){
	int turns=dificulty(ships);
	int x,y,i,j,destapadas;
	int win[n][n];
	deploy(n,dev,user);
	int remShips;
	while(*cont && turns>0){
		remShips=shipCount(n,dev,user,ships);
		printf("turnos: %d\n", turns);
		printf("submarinos: %d\n\n", remShips);
		printf("Ingrese las coordenadas (x,y): \n");
		readValidTry(n,dev,user);
		turns=turns-1;
		
		deploy(n,dev,user);
		wins(n,dev,user,ships,cont);
		
		if (turns==0){
			printf("Perdiste :'v \n");
		}
	}

}
int continues(){
	char co;
	printf("Continuar?(y,n): ");
	scanf("%s",&co);
	if(co==121){
		return 1;
	}else{
		if(co==110){
			return 0;
		}else{
			printf("Opcion no valida, intente de nuevo. \n\n");
			co=continues();
		}
	}
}

#endif
