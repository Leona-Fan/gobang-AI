#include <stdio.h>
#include "all.h"
static int chess[10000]={0};//��¼ģ�����ӵ�λ�ü�������ɫ 
static int chessp=0;//ָ��ջ�ڿ���ռ�ĵ�һλ 
static int maxvalue=0;//���ֵ 
static int a[3];
static int s1[3];

void getMaxEvaluate(int leftstep,int color,int s[]){//������ 
	int i,j,type;
	int val=0;
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			if(Board[i][j]==BLACK||Board[i][j]==WHITE||Board[i][j]==BLACKtem||Board[i][j]==WHITEtem){
				continue;
			}
			move(color,i,j); 
			
			int val= evaluateboard1(color)-evaluateboard2(41-color);
			if(val>80000){//�������Ӯ��ֱ������ 
				s[0]=i;
				s[1]=j;
				s[2]=val;
				removechess();
				return;
			}
			if(leftstep>1){
				getMaxEvaluate(leftstep-1,41-color,a);//�ݹ� 
				val=-a[2];
			}
			if(val>maxvalue){//�ҵ���������λ�� 
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

void Max(int color,int s[]){//ֱ�������������ҵ��������������λ�� 
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
			if(color==BLACK&&banhand(i,j)==1){//��Ϊ���֣���ʹ����λ�÷������ͣ��Ӷ��������� 
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

void move(int color,int i,int j){//ģ��������ջ 
	int type;
	type=Board[i][j];
	Board[i][j]=color;
	chess[chessp++]=i;
	chess[chessp++]=j;
	chess[chessp++]=type;
}

void removechess(){//ģ�����ӳ�ջ 
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
