#include <stdio.h>
#include "all.h"

int evaluateboard1(int color){//�����ӵ��������� 
	int value=0;
	int i,m,n;
	for(m=0;m<SIZE;m++){
		for(n=0;n<SIZE;n++){//0��ǰ��ɫ�� -�Է���ɫ�� +�ո� 
		if(Board[m][n]==color||Board[m][n]==color-10){		
			number(color,m,n);
		for(i=0;i<4;i++){
		if(init[i]+init[i+4]>=4)
			value+=1000000;
		
		if(init[i]+init[i+4]==3){
			if(initBlank[i]>0&&initBlank[i+4]>0)//���� 
				value+=50000;
			else if(initBlank[i]>=1||initBlank[i+4]>=1)//���� 
				value+=125;
			else{
				value-=1;
			} 
		}
				
		if(((init[i]+init[i+4]+next[i])==3&&initBlank[i]==1)||((init[i]+init[i+4]+next[i+4])==3&&initBlank[i+4]==1)){//���� 
				value+=80;
		}
		
		if(state[i]==1)//���� 
			value+=66;
			
		if(((init[i]+init[i+4])==2)&&(initBlank[i]>=1||initBlank[i+4]>=1))//���� 
			value+=17;
		
		if((init[i]==1&&(initBlank[i]>0||initBlank[i+4]>1))||(init[i+4]==1&&(initBlank[i+4]>0&&initBlank[i+4]>1))){//��2 
			value+=1.5;
		}
		
		if((init[i]==1&&init[i+4]==0&&init[i+4]==1&&nextBlank[i+4]>=1)||(init[i+4]==1&&init[i]==0&&init[i]==1&&nextBlank[i]>=1)){//���� +0+00- 
			value+=17;
		}
		
		if((initBlank[i]==1&&next[i]==2&&initBlank[i+4]>=1)||(initBlank[i+4]==1&&next[i+4]==2&&initBlank[i]>=1)){//���� +0+00- 
			value+=17;
		}
		
		if((init[i+4]==1&&initBlank[i]==2&&next[i]==1&&init[i]==0)||(init[i]==1&&initBlank[i+4]==2&&next[i+4]==1&&init[i+4]==0)){//���� 0++00 
			value+=17;
		}
		
		if(initBlank[i]==1&&initBlank[i+4]==1&&next[i]==1&&next[i+4]==1){//���� 0+0+0
			value+=17;
		}
		
		if((init[i]==2||init[i+4]==2)&&initBlank[i]==1&&initBlank[i+4]==1){//���� -+000+- 
			value+=17;
		}
		
		if(initBlank[i+4]>=1&&init[i]==0&&initBlank[i]==1&&next[i]==1&&nextBlank[i]>=1){//��� +0+0+ 
			value+=2; 
		}
		
		if(initBlank[i]>=1&&init[i+4]==0&&initBlank[i+4]==1&&next[i+4]==1&&nextBlank[i+4]>=1){//��� +0+0+ 
			value+=2; 
		}
		
		if(init[i]==1&&init[i+4]==0&&initBlank[i+4]==0&&initBlank[i]>=3){//�߶� +++00-
			value+=1;
		}
		
		if(init[i+4]==1&&init[i]==0&&initBlank[i]==0&&initBlank[i+4]>=3){//�߶� +++00-
			value+=1;
		}
		
		if(init[i]==0&&init[i+4]==1&&initBlank[i]>=3){//�߶� +++00-
			value+=1;
		}
		
		if(init[i+4]==0&&init[i]==1&&initBlank[i+4]>=3){//�߶� +++00-
			value+=1;
		}
		
		if(initBlank[i]==1&&init[i+4]==0&&initBlank[i+4]==0&&next[i]==1&&nextBlank[i]>=2){//�߶�-0+0++ 
			value+=1;
		}
		
		if(initBlank[i+4]==1&&init[i]==0&&initBlank[i]==0&&next[i+4]==1&&nextBlank[i+4]>=2){//�߶�-0+0++ 
			value+=1;
		}
		
		if(initBlank[i+4]==0&&init[i+4]==0&&initBlank[i]==2&&next[i]==1&&nextBlank[i]>=1){//�߶� -0++0+ 
			value+=1;
		}
		
		if(initBlank[i]==0&&init[i]==0&&initBlank[i+4]==2&&next[i+4]==1&&nextBlank[i+4]>=1){//�߶� -0++0+ 
			value+=1;
		}
		if(initBlank[i]==0&&initBlank[i+4]==0&&init[i]+init[i+4]==3){//���� -0000- 
			value-=1;
		}
		
		if(initBlank[i]==0&&initBlank[i+4]==0&&init[i]+init[i+4]==2){//���� -000- 
			value-=1;
		}
		
		if(initBlank[i]==0&&initBlank[i+4]==0&&init[i]+init[i+4]==1){//���� -00- 
			value-=2;
		}
	}
	for(i=0;i++;i<8){
		if(init[i]==1&&initBlank[i]==1&&next[i]==1){//���� +0+00-
			if(nextBlank[i]>=1){
				
			}
			else{
				
			}
		}
		
		if(init[i]==1&&initBlank[i]==2&&next[i]==1){//���� 0++00 
			value+=17;
		}
		
		
		if(initBlank[i]==2&&next[i]==2){//���� 0++00 
			value+=17;
		}
		
		if(initBlank[i]==1&&nextBlank[i]==1&&next[i]==1&&third[i]==1){//���� 0+0+0 
			value+=17;
		}
		
		if(initBlank[i]==2&&next[i]==1){//��� 0++0 
			value+=2; 
		}
		
		if(initBlank[i]==3&&next[i]==1){//�߶� 0+++0 
			value+=1; 
		} 
		
	}
		}
	}}
	return value;
	
}
int evaluateboard2(int color){//�Է��ӵ��������� 
	int value=0;
	int i,m,n;
	for(m=0;m<SIZE;m++){
		for(n=0;n<SIZE;n++){//0��ǰ��ɫ�� -�Է���ɫ�� +�ո� 
		if(Board[m][n]==color||Board[m][n]==color-10){
		
			number(color,m,n);
			for(i=0;i<4;i++){
		if(init[i]+init[i+4]>=4)
			value+=1000000;
		
		if(init[i]+init[i+4]==3){
			if(initBlank[i]>0&&initBlank[i+4]>0)//���� 
				value+=50000;
			else if(initBlank[i]>=1||initBlank[i+4]>=1)//���� 
				value+=125;
			else{
				value-=1;
			} 
		}
				
		if(((init[i]+init[i+4]+next[i])==3&&initBlank[i]==1)||((init[i]+init[i+4]+next[i+4])==3&&initBlank[i+4]==1)){//���� 
				value+=80;
		}
		
		if(state[i]==1)//���� 
			value+=66;
			
		if(((init[i]+init[i+4])==2)&&(initBlank[i]>=1||initBlank[i+4]>=1))//���� 
			value+=17;
		
		if((init[i]==1&&(initBlank[i]>0||initBlank[i+4]>1))||(init[i+4]==1&&(initBlank[i+4]>0&&initBlank[i+4]>1))){//��2 
			value+=1.5;
		}
		
		if((init[i]==1&&init[i+4]==0&&init[i+4]==1&&nextBlank[i+4]>=1)||(init[i+4]==1&&init[i]==0&&init[i]==1&&nextBlank[i]>=1)){//���� +0+00- 
			value+=17;
		}
		
		if((initBlank[i]==1&&next[i]==2&&initBlank[i+4]>=1)||(initBlank[i+4]==1&&next[i+4]==2&&initBlank[i]>=1)){//���� +0+00- 
			value+=17;
		}
		
		if((init[i+4]==1&&initBlank[i]==2&&next[i]==1&&init[i]==0)||(init[i]==1&&initBlank[i+4]==2&&next[i+4]==1&&init[i+4]==0)){//���� 0++00 
			value+=17;
		}
		
		if(initBlank[i]==1&&initBlank[i+4]==1&&next[i]==1&&next[i+4]==1){//���� 0+0+0
			value+=17;
		}
		
		if((init[i]==2||init[i+4]==2)&&initBlank[i]==1&&initBlank[i+4]==1){//���� -+000+- 
			value+=17;
		}
		
		if(initBlank[i+4]>=1&&init[i]==0&&initBlank[i]==1&&next[i]==1&&nextBlank[i]>=1){//��� +0+0+ 
			value+=2; 
		}
		
		if(initBlank[i]>=1&&init[i+4]==0&&initBlank[i+4]==1&&next[i+4]==1&&nextBlank[i+4]>=1){//��� +0+0+ 
			value+=2; 
		}
		
		if(init[i]==1&&init[i+4]==0&&initBlank[i+4]==0&&initBlank[i]>=3){//�߶� +++00-
			value+=1;
		}
		
		if(init[i+4]==1&&init[i]==0&&initBlank[i]==0&&initBlank[i+4]>=3){//�߶� +++00-
			value+=1;
		}
		
		if(init[i]==0&&init[i+4]==1&&initBlank[i]>=3){//�߶� +++00-
			value+=1;
		}
		
		if(init[i+4]==0&&init[i]==1&&initBlank[i+4]>=3){//�߶� +++00-
			value+=1;
		}
		
		if(initBlank[i]==1&&init[i+4]==0&&initBlank[i+4]==0&&next[i]==1&&nextBlank[i]>=2){//�߶�-0+0++ 
			value+=1;
		}
		
		if(initBlank[i+4]==1&&init[i]==0&&initBlank[i]==0&&next[i+4]==1&&nextBlank[i+4]>=2){//�߶�-0+0++ 
			value+=1;
		}
		
		if(initBlank[i+4]==0&&init[i+4]==0&&initBlank[i]==2&&next[i]==1&&nextBlank[i]>=1){//�߶� -0++0+ 
			value+=1;
		}
		
		if(initBlank[i]==0&&init[i]==0&&initBlank[i+4]==2&&next[i+4]==1&&nextBlank[i+4]>=1){//�߶� -0++0+ 
			value+=1;
		}
		if(initBlank[i]==0&&initBlank[i+4]==0&&init[i]+init[i+4]==3){//���� -0000- 
			value-=1;
		}
		
		if(initBlank[i]==0&&initBlank[i+4]==0&&init[i]+init[i+4]==2){//���� -000- 
			value-=1;
		}
		
		if(initBlank[i]==0&&initBlank[i+4]==0&&init[i]+init[i+4]==1){//���� -00- 
			value-=2;
		}
	}
	for(i=0;i++;i<8){
		if(init[i]==1&&initBlank[i]==1&&next[i]==1){//���� +0+00-
			if(nextBlank[i]>=1){
				
			}
			else{
				
			}
		}
		
		if(init[i]==1&&initBlank[i]==2&&next[i]==1){//���� 0++00 
			value+=17;
		}
		
		
		if(initBlank[i]==2&&next[i]==2){//���� 0++00 
			value+=17;
		}
		
		if(initBlank[i]==1&&nextBlank[i]==1&&next[i]==1&&third[i]==1){//���� 0+0+0 
			value+=17;
		}
		
		if(initBlank[i]==2&&next[i]==1){//��� 0++0 
			value+=2; 
		}
		
		if(initBlank[i]==3&&next[i]==1){//�߶� 0+++0 
			value+=1; 
		} 
		
	}
		}
	}}
	value=(value*2)/3;//�����ӱȶԷ���Ȩ�ظ� 
	return value;
	
}
