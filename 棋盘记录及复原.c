#include <stdio.h>
#include "all.h"
static int Boardrecord[SIZE][SIZE];//���̼�¼���� 

void record(void){//��¼���� 
	int i,j;
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			Boardrecord[i][j]=Board[i][j];
		}
	}
}

void showback(void){//��ԭ���� 
	int i,j;
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			Board[i][j]=Boardrecord[i][j];
		}
	}
}
