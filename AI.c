#include <stdio.h>
#include "all.h"
static int chess[10000]={0};//记录模拟下子的位置及棋子颜色 
static int chessp=0;//指向栈内空余空间的第一位 
static int maxvalue=0;//最大值 
static int a[3];
static int s1[3];

void getMaxEvaluate(int leftstep,int color,int s[]){//搜索树 
	int i,j,type;
	int val=0;
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			if(Board[i][j]==BLACK||Board[i][j]==WHITE||Board[i][j]==BLACKtem||Board[i][j]==WHITEtem){
				continue;
			}
			move(color,i,j); 
			
			int val= evaluateboard1(color)-evaluateboard2(41-color);
			if(val>80000){//如果可以赢则直接下子 
				s[0]=i;
				s[1]=j;
				s[2]=val;
				removechess();
				return;
			}
			if(leftstep>1){
				getMaxEvaluate(leftstep-1,41-color,a);//递归 
				val=-a[2];
			}
			if(val>maxvalue){//找到评分最大的位置 
				maxvalue=val;
				s1[0]=i;
				s1[1]=j;
			}
			removechess();
		}
	s1[2]=maxvalue;
	s[0]=s1[0];
	s[1]=s1[1];
	s[2]=s1[2];
}
}

void Max(int color,int s[]){//直接棋盘评估，找到棋盘上评分最大位置 
	int i,j,type;
	int maxvalue=0;
	int val=0;
	int a[3];
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			if(Board[i][j]==20||Board[i][j]==21||Board[i][j]==10||Board[i][j]==11){
				continue;
			}
				
			move(color,i,j);
			val= evaluateboard1(color)-evaluateboard2(41-color);
			if(color==BLACK&&banhand(i,j)==1){//若为禁手，则使禁手位置分数极低，从而避免下子 
				val-=800000;
			}
			if(val>maxvalue){
				a[0]=i;
				a[1]=j;
				maxvalue=val;
			}
			if(val>80000){
				a[0]=i;
				a[1]=j;
				a[2]=val;
				removechess();
				break;
			}
			removechess();
			}
		}
		move(color,a[0],a[1]);
		a[2]=maxvalue;
		s[0]=a[0];
		s[1]=a[1];
		s[2]=a[2];
}

void move(int color,int i,int j){//模拟下子入栈 
	int type;
	type=Board[i][j];
	Board[i][j]=color;
	chess[chessp++]=i;
	chess[chessp++]=j;
	chess[chessp++]=type;
}

void removechess(){//模拟下子出栈 
	chessp--;
	while(chessp>1){
		Board[chess[chessp-2]][chess[chessp-1]]=chess[chessp];
		chessp-=3;
	}
	chessp=0;
	int i;
	for(i=0;i++;i<10000){
		chess[i]=0;
	}		
}
