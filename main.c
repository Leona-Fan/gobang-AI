#include <stdio.h>
#include "all.h"
static int w,v;
int winornot=0;
int	banornot=0;


void main()
{
	InitBoardArray();
	DisplayBoard();
	count=0;
	w=v=15;
	printf("AIΪ����������1��AIΪ����������2�����˶�ս������3\n");
	int gettype;
	gettype=getchar();
	getchar();//��ѡ��ģʽ���������� 
	 
	while(gettype=='2'&&count<225&&winornot!=1&&banornot!=1){//AIΪ���ӣ�ʹ��winornot��banornot�ֱ��ж���Ӯ�ͽ��֣������Ӯ��������½����������� 
		if(count%2==0){
			printf("����������λ�ã�����Ϸ���ʽ��h8\n");
			input1();
		}	
		else
			input2(WHITE);	
	}
	while(gettype=='1'&&count<225&&winornot!=1&&banornot!=1){//AIΪ���� 
		if(count%2==1){
			printf("����������λ�ã�����Ϸ���ʽ��h8\n");
			input1();
		}
		else
			input2(BLACK);	
	}
	while(gettype=='3'&&count<225&&winornot!=1&&banornot!=1) {//���˶�ս 
			printf("����������λ�ã�����Ϸ���ʽ��h8\n");
			input1();
		}
	
	
}

void input1(){//�ֶ����� 
	int y,x,xx;
	int i;
		y=getchar();
			if(y>96&&y<112){
			x=getchar();
				if(x<58&&x>48) {
					xx=getchar();
					if(xx<54&&xx>47&&x==49){
						if(getchar()=='\n'){
						if(count%2==0){
							if(Board[SIZE-xx-10+48][y-'a']<=9&&Board[SIZE-xx-10+48][y-'a']>=1){
								Board[w][v]=WHITE;
								Board[SIZE-xx-10+48][y-'a'] = BLACKtem;	//�ı������Ӧ����ֵ
	    						DisplayBoard();	//��ʾ����
	    						w=SIZE-xx-10+48;
	    						v=y-'a';
	    						printf("�����������%c%d\n",y,xx+10-48); 
	    						banornot=banhand(w,v);//�ж��Ƿ�Υ������ 
	    						if(banornot==1){
									printf("����Υ�����֣�WHITE WIN");
								}
	    						winornot=winjudge(BLACK,w,v);//�ж��Ƿ�Ӯ 
	    						count++;
	    				}
	    					else{
	    						printf("�����ظ�����\n");
							} 
						}
						else if(count%2==1){
							if(Board[SIZE-xx-10+48][y-'a']<=9&&Board[SIZE-xx-10+48][y-'a']>=1){
								Board[w][v]=BLACK;
								Board[SIZE-xx-10+48][y-'a'] = WHITEtem;	//�ı������Ӧ����ֵ
	    						DisplayBoard();	//��ʾ����
	    						w=SIZE-xx-10+48;
	    						v=y-'a';
	    						printf("�����������%c%d\n",y,xx+10-48); 
	    						winornot=winjudge(WHITE,w,v);
	    						count++;
							}
							else{
								printf("�����ظ�����\n");
							}
						}
					}
						else{
							while(getchar()!='\n'){;}
							printf("����������������������\n");
						}
					}
					else if(xx=='\n') {
						if(count%2==0){
							if(Board[SIZE-x+48][y-'a']<=9&&Board[SIZE-x+48][y-'a']>=1){
								Board[w][v]=WHITE;
								Board[SIZE-x+48][y-'a'] = BLACKtem;	//�ı������Ӧ����ֵ
	    						DisplayBoard();	//��ʾ����
	    						w=SIZE-x+48;
	    						v=y-'a';
	    						printf("�����������%c%d\n",y,x-48); 
	    						banornot=banhand(w,v);
	    						if(banornot==1){
									printf("����Υ�����֣�WHITE WIN");
								}
	    						winornot=winjudge(BLACK,w,v);
	    						count++;
	    					}
	    					else{
								printf("�����ظ�����\n");
							} 
						}
						else if(count%2==1){
							if(Board[SIZE-x+48][y-'a']<=9&&Board[SIZE-x+48][y-'a']>=1){
								Board[w][v]=BLACK;
								Board[SIZE-x+48][y-'a'] = WHITEtem;	//�ı������Ӧ����ֵ
	    						DisplayBoard();	//��ʾ����
	    						w=SIZE-x+48;
	    						v=y-'a';
	    						printf("�����������%c%d\n",y,x-48);
	    						winornot=winjudge(WHITE,w,v);
	    						count++;
							}
							else{							
								printf("�����ظ�����\n");	
							}
						}
					}
					else{					
						while(getchar()!='\n'){;}
						printf("����������������������\n"); 
					} 
				}
				else{				
				while(getchar()!='\n'){;}
				printf("����������������������\n");
			}
			}
			else{
			while(getchar()!='\n'){;}
			printf("����������������������\n");
			} 
}

void input2(int color){//AI���� 
	int m,n;
	int s[3];
	if(count==0){//��һ��������h8 
		Board[7][7]=BLACKtem;
		DisplayBoard();
		w=7;
		v=7;
		printf("AI�����������%c%d\n",7+'a',7+1);
		count++;
	}
	else if(count==1&&Board[7][7]!=BLACKtem){//�����һ����δ����h8���������h8 
		Board[7][7]=WHITEtem;
		Board[w][v]=BLACK;
		w=7;
		v=7;
		DisplayBoard();
		printf("AI�����������%c%d\n",7+'a',7+1);
		count++;
	}
	else if(count==1){//ֱ�ӹ涨AI��һ����������h8�Ҳ� 
		Board[7][8]=WHITEtem;
		Board[w][v]=BLACK;
		w=7;
		v=8;
		DisplayBoard();
		printf("AI�����������%c%d\n",7+'a',8+1);
		count++;
	}
	else{//AI�������� 
		record();//��¼���� 
		getMaxEvaluate(2,color,s);//����������ȵ������� 
		showback();//��ԭ���� 
		m=s[0];
		n=s[1];
		if(Board[m][n]==BLACK||Board[m][n]==WHITE||Board[m][n]==BLACKtem||Board[m][n]==WHITEtem){
			Max(color,s);
			showback();
			m=s[0];
			n=s[1];
		}//������������������ظ����ӣ���ʹ���������������� 
		
		if(count%2==0){
		if(banhand(m,n)==1){//���������֣���ʹ�������������� 
			Max(color,s);
			showback();
			m=s[0];
			n=s[1];
		}
			Board[m][n]=BLACKtem;
			Board[w][v]=WHITE;
			DisplayBoard();
			printf("AI�����������%c%d\n",n+'a',15-m);
			banornot=banhand(m,n);
			if(banornot==1){
				printf("����Υ�����֣�WHITE WIN");
			}
	    	winornot=winjudge(BLACK,m,n);
			w=m;
			v=n;
			count++;
		}
		else{
			Board[m][n]=WHITEtem;
			Board[w][v]=BLACK;
			DisplayBoard();
			printf("AI�����������%c%d\n",n+'a',15-m);
	    	winornot=winjudge(WHITE,m,n);
			w=m;
			v=n;
			count++;
		}
		}
}

void InitBoardArray()
{
	int j, i; 
	
	Board[0][0] = 1;
	Board[0][SIZE - 1] = 2;
	Board[SIZE - 1][SIZE - 1] = 3;
	Board[SIZE - 1][0] = 4;
	
	for (j = 1; j <= SIZE - 2; j++)
	{
		Board[j][0] = 5;
	}
	
	for (i = 1; i <= SIZE - 2; i++)
	{
		Board[0][i] = 6;
	}
	
	for (j = 1; j <= SIZE - 2; j++)
	{
		Board[j][SIZE - 1] = 7;
	}
	
	for (i = 1; i <= SIZE - 2; i++)
	{
		Board[SIZE - 1][i] = 8;
	}
	
	for (j = 1; j <= SIZE - 2; j++)
	{
		for (i = 1; i <= SIZE - 2; i++)
		{
			Board[j][i] = 9;
		}
	}
}

void DisplayBoard() 
{	
	int i, j;
	char line;
	char ary;
	
	system("cls");   //����

	for(j = 0,line = 15; j <= SIZE - 1; j++)
	{
		printf("%2d",line);
		line -= 1;
		for(i = 0; i <= SIZE - 1; i++)
		{
			switch(Board[j][i])
			{
			case 1:
				printf("��");
				break;
				
			case 2:
				printf("��");
				break;
				
			case 3:
				printf("��");
				break;
				
			case 4:
				printf("��");
				break;
				
			case 5:
				printf("��");
				break;
				
			case 6:
				printf("��");
				break;
				
			case 7:
				printf("��");
				break;
				
			case 8:
				printf("��");
				break;
				
			case 9:
				printf("��");
				break;
				
			case BLACKtem:      // ������һ��
				printf("��");
				break;
				
			case WHITEtem:      //������һ��
				printf("��");
				break;
				
			case BLACK:      //����ͨ��
				printf("��");
				break;
				
			case WHITE:
				printf("��");  //����ͨ��
				break;
			}
			if(i == SIZE - 1)
			{
				printf("\n");
			}
			
		}
	}
	
	printf("   ");
	for (ary = 'A'; ary < 'A' + SIZE ; ary++)
		printf("%c ",ary);
	
	printf("\n");
}

