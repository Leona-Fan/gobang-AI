#include <stdio.h>
#include "all.h"

int winjudge(int color,int w,int v){
	int x,y,z;
	int i,j,k1,k2;//i为横向，j为竖向，k1为左斜，k2为右斜 
	i=j=k1=k2=1;//依据下子位置向外延伸判断是否有五子 
	for(x=1;Board[w-x][v]==color&&(w-x)>=0;x++){
		i++;
	}
	for(x=1;Board[w+x][v]==color&&(w+x)<15;x++){
		i++;
	}
	
	for(y=1;Board[w][v-y]==color&&(v-y)>=0;y++){
		j++;
	}
	for(y=1;Board[w][v+y]==color&&(v+y)<15;y++){
		j++;
	}
	
	for(z=1;Board[w-z][v+z]==color&&(w-z)>=0&&(v+z)<15;z++){
		k1++;
	}
	for(z=1;Board[w+z][v-z]==color&&(w+z)<15&&(v-z)>=0;z++){
		k1++;
	}
	
	for(z=1;Board[w+z][v+z]==color&&(w+z)<15&&(v+z)<15;z++){
		k2++;
	}
	for(z=1;Board[w-z][v-z]==color&&(w-z)>=0&&(v-z)>=0;z++){
		k2++;
	}
	if((i>=5||j>=5||k1>=5||k2>=5)&&(color==WHITE)){
			printf("WHITE WIN");
			return 1;
		}
	if(color==BLACK){
		if(i==5||j==5||k1==5||k2==5){
			printf("BLACK WIN");  
			return 1; 
		}
		else if(i>5||j>5||k1>5||k2>5){
			printf("黑子违反禁手，WHITE WIN"); //形成长连 
			return 1;
		}
	}//先判赢再判禁手，满足五连与禁手同时形成黑子胜 
	if(count==224) {
		printf("游戏已结束，平局"); //用count记放子数，棋盘已经放满 	
		return 1;
	}
	return 0;//已有输赢返回1，其余情况返回0 
		
}

