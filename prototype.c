#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "prototype.h"

#define SHIP 1
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
void deploy(int n, int dev[n][n],int user[][n],int * isShip){
    int i,j;
    *isShip=0;
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
			        *isShip=1;
			    }
			}
		}
		printf("\n");
	}
}
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
    deploy(n,dev,user,&isShip);
}


int main()
{

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
	//play(n,user,dev,&cont);
	return 0;
}
