#include <stdio.h>
#include "all.h"

int winjudge(int color,int w,int v){
	int x,y,z;
	int i,j,k1,k2;//iΪ����jΪ����k1Ϊ��б��k2Ϊ��б 
	i=j=k1=k2=1;//��������λ�����������ж��Ƿ������� 
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
			printf("����Υ�����֣�WHITE WIN"); //�γɳ��� 
			return 1;
		}
	}//����Ӯ���н��֣��������������ͬʱ�γɺ���ʤ 
	if(count==224) {
		printf("��Ϸ�ѽ�����ƽ��"); //��count�Ƿ������������Ѿ����� 	
		return 1;
	}
	return 0;//������Ӯ����1�������������0 
		
}

