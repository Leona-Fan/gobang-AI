#include <stdio.h>
#include "all.h"

int number(int color,int w,int v){
	int i;
	for(i=0;i<4;i++){
		state[i]=0;
	}
	for(i=0;i<8;i++){
		init[i]=initBlank[i]=next[i]=nextBlank[i]=third[i]=0;//初始化八个方向上的数目 
	}
	
	for(i=1;i<7;i++){
		if(Board[w][v+i]==color&&initBlank[0]==0){
			init[0]++;
		}
		else if(Board[w][v+i]<10&&Board[w][v+i]>0&&next[0]==0){
			initBlank[0]++;
		}
		else if(Board[w][v+i]==color&&nextBlank[0]==0){
			next[0]++;
		}
		else if(Board[w][v+i]<10&&Board[w][v+i]>0&&third[0]==0){
			nextBlank[0]++;
		}
		else if(Board[w][v+i]==color){
			third[0]++;
		}
		else{
			break;
		}
		//向上 
	}
	for(i=1;i<7;i++){
		if(Board[w+i][v+i]==color&&initBlank[1]==0){
			init[1]++;
		}
		else if(Board[w+i][v+i]<10&&Board[w+i][v+i]>0&&next[1]==0){
			initBlank[1]++;
		}
		else if(Board[w+i][v+i]==color&&nextBlank[1]==0){
			next[1]++;
		}
		else if(Board[w+i][v+i]<10&&Board[w+i][v+i]>0&&third[1]==0){
			nextBlank[1]++;
		}
		else if(Board[w+i][v+i]==color){
			third[1]++;
		}
		else{
			break;
		}
		//向右上 
	}
	for(i=1;i<7;i++){
		if(Board[w+i][v]==color&&initBlank[2]==0){
			init[2]++;
		}
		else if(Board[w+i][v]<10&&Board[w+i][v]>0&&next[2]==0){
			initBlank[2]++;
		}
		else if(Board[w+i][v]==color&&nextBlank[2]==0){
			next[2]++;
		}
		else if(Board[w+i][v]<10&&Board[w+i][v]>0&&third[2]==0){
			nextBlank[2]++;
		}
		else if(Board[w+i][v]==color){
			third[2]++;
		}
		else{
			break;
		}
		//向右 
	}
	for(i=1;i<7;i++){
		if(Board[w+i][v-i]==color&&initBlank[3]==0){
			init[3]++;
		}
		else if(Board[w+i][v-i]<10&&Board[w+i][v-i]>0&&next[3]==0){
			initBlank[3]++;
		}
		else if(Board[w+i][v-i]==color&&nextBlank[3]==0){
			next[3]++;
		}
		else if(Board[w+i][v-i]<10&&Board[w+i][v-i]>0&&third[3]==0){
			nextBlank[3]++;
		}
		else if(Board[w+i][v-i]==color){
			third[3]++;
		}
		else{
			break;
		}
		//向右下 
	}
	for(i=1;i<7;i++){
		if(Board[w][v-i]==color&&initBlank[4]==0){
			init[4]++;
		}
		else if(Board[w][v-i]<10&&Board[w][v-i]>0&&next[4]==0){
			initBlank[4]++;
		}
		else if(Board[w][v-i]==color&&nextBlank[4]==0){
			next[4]++;
		}
		else if(Board[w][v-i]<10&&Board[w][v-i]>0&&third[4]==0){
			nextBlank[4]++;
		}
		else if(Board[w][v-i]==color){
			third[4]++;
		}
		else{
			break;
		}
		//向下 
	}
	for(i=1;i<7;i++){
		if(Board[w-i][v-i]==color&&initBlank[5]==0){
			init[5]++;
		}
		else if(Board[w-i][v-i]<10&&Board[w-i][v-i]>0&&next[5]==0){
			initBlank[5]++;
		}
		else if(Board[w-i][v-i]==color&&nextBlank[5]==0){
			next[5]++;
		}
		else if(Board[w-i][v-i]<10&&Board[w-i][v-i]>0&&third[5]==0){
			nextBlank[5]++;
		}
		else if(Board[w-i][v-i]==color){
			third[5]++;
		}
		else{
			break;
		}
		//向左下 
	}
	for(i=1;i<6;i++){
		if(Board[w-i][v]==color&&initBlank[6]==0){
			init[6]++;
		}
		else if(Board[w-i][v]<10&&Board[w-i][v]>0&&next[6]==0){
			initBlank[6]++;
		}
		else if(Board[w-i][v]==color&&nextBlank[6]==0){
			next[6]++;
		}
		else if(Board[w-i][v]<10&&Board[w-i][v]>0&&third[6]==0){
			nextBlank[6]++;
		}
		else if(Board[w-i][v]==color){
			third[6]++;
		}
		else{
			break;
		}
		//向左 
	}
	for(i=1;i<6;i++){
		if(Board[w-i][v+i]==color&&initBlank[7]==0){
			init[7]++;
		}
		else if(Board[w-i][v+i]<10&&Board[w-i][v+i]>0&&next[7]==0){
			initBlank[7]++;
		}
		else if(Board[w-i][v+i]==color&&nextBlank[7]==0){
			next[7]++;
		}
		else if(Board[w-i][v+i]<10&&Board[w-i][v+i]>0&&third[7]==0){
			nextBlank[7]++;
		}
		else if(Board[w-i][v+i]==color){
			third[7]++;
		}
		else{
			break;
		}
		//向左上 
	}
	
	for(i=0;i<4;i++){//四个方向，若该方向满足活三则对该方向的state赋1 
		if(((init[i]+init[i+4])==2)&&initBlank[i]>=1&&initBlank[i+4]>=1&&initBlank[i]+initBlank[i+4]>2){
			state[i]=1;//++000+ +000++
		}
		else if(((init[i]+init[i+4]+next[i])==2&&initBlank[i]==1)||((init[i]+init[i+4]+next[i+4])==2&&initBlank[i+4]==1)&&nextBlank[i]>0&&nextBlank[i+4]>0){
			state[i]=1;//+0+00+ +00+0+
		}
		else{
			continue;
		}
	} 
	for(i=0;i<4;i++){//若该方向满足活四或冲四则对该方向的state赋-1 
		if(((init[i]+init[i+4])==3)&&(initBlank[i]>=1||initBlank[i+4]>=1)){
			state[i]=-1;//0000
		}
		else if(((init[i]+init[i+4]+next[i])==3&&initBlank[i]==1)||((init[i]+init[i+4]+next[i+4])==3&&initBlank[i+4]==1)){
			state[i]=-1;//0+000 000+0
		}
		else{
			continue;
		}
	}
}
	
int banhand(int w,int v){
	number(BLACK,w,v);
	int i,j;
	for(i=0;i<4&&initBlank[i]==1&&initBlank[i+4]==1;i++){
		if(init[i]==1&&init[i+4]==1&&next[i]>0&&next[i+4]>0){//0+000+0
			return 1;
		}
		else if((init[i]==1||init[i+4]==1)&&next[i]>=2&&next[i+4]>=2){//00+00+00
			return 1;
		}
		else if(next[i]>=3&&next[i+4]>=3){//000+0+000
			return 1;
		}
		else{
			continue;
		}
	}
	for(i=0;i<4;i++){
		for(j=0;j<i;j++){
			if((state[i]+state[j]==2)||(state[i]+state[j]==-2)){//两个活三或者两个四就为禁手 
				return 1;
			}
		}
	}
	
	return 0;//若违反禁手返回1，其余情况返回1 
}

