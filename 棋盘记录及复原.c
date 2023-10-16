#include <stdio.h>
#include "all.h"
static int Boardrecord[SIZE][SIZE];//棋盘记录数组 

void record(void){//记录棋盘 
	int i,j;
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			Boardrecord[i][j]=Board[i][j];
		}
	}
}

void showback(void){//复原棋盘 
	int i,j;
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			Board[i][j]=Boardrecord[i][j];
		}
	}
}
