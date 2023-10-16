#include <stdio.h>

#define SIZE 15
#define BLACKtem 10
#define WHITEtem 11
#define BLACK 20
#define WHITE 21

int Board[SIZE][SIZE];

void InitBoardArray();  //��ʼ��������
void DisplayBoard();	//��ʾ����
int winjudge();	//��Ӯ�ж� 

void main()
{
	int y,x,xx;
	int i;
	int w,v;
	w=v=15;
	int c;

	InitBoardArray();
	DisplayBoard();


	for(i=0;i<SIZE*SIZE;i++){
			y=getchar();
			if(y>96&&y<112){
			x=getchar();
				if(x<58&&x>48) {
					xx=getchar();
					if(xx<54&&xx>47&&x==49){
						if(getchar()=='\n'){
						if(i%2==0){
							if(Board[SIZE-xx-10+48][y-'a']<=9&&Board[SIZE-xx-10+48][y-'a']>=1){
								Board[w][v]=WHITE;
								Board[SIZE-xx-10+48][y-'a'] = BLACKtem;	//�ı������Ӧ����ֵ
	    						DisplayBoard();	//��ʾ����
	    						w=SIZE-xx-10+48;
	    						v=y-'a';
	    						printf("�������%c%d\n",y,xx+10-48); 
	    				}
	    					else{
	    						printf("�����ظ�����\n");
								--i;
								continue;
							} 
						}
						if(i%2==1){
							if(Board[SIZE-xx-10+48][y-'a']<=9&&Board[SIZE-xx-10+48][y-'a']>=1){
								Board[w][v]=BLACK;
								Board[SIZE-xx-10+48][y-'a'] = WHITEtem;	//�ı������Ӧ����ֵ
	    						DisplayBoard();	//��ʾ����
	    						w=SIZE-xx-10+48;
	    						v=y-'a';
	    						printf("�������%c%d\n",y,xx+10-48); 
							}
							else{
								printf("�����ظ�����\n");
								--i;
								continue;
							}
						}
					}
						else{
							while(getchar()!='\n'){;}
							printf("����������������������\n");
							--i;
						}
					}
					else if(xx=='\n') {
						if(i%2==0){
							if(Board[SIZE-x+48][y-'a']<=9&&Board[SIZE-x+48][y-'a']>=1){
								Board[w][v]=WHITE;
								Board[SIZE-x+48][y-'a'] = BLACKtem;	//�ı������Ӧ����ֵ
	    						DisplayBoard();	//��ʾ����
	    						w=SIZE-x+48;
	    						v=y-'a';
	    						printf("�������%c%d\n",y,x-48); 
	    					}
	    					else{
								printf("�����ظ�����\n");
								--i;
								continue;
							} 
						}
						if(i%2==1){
							if(Board[SIZE-x+48][y-'a']<=9&&Board[SIZE-x+48][y-'a']>=1){
								Board[w][v]=BLACK;
								Board[SIZE-x+48][y-'a'] = WHITEtem;	//�ı������Ӧ����ֵ
	    						DisplayBoard();	//��ʾ����
	    						w=SIZE-x+48;
	    						v=y-'a';
	    						printf("�������%c%d\n",y,x-48);
							}
							else{							
								printf("�����ظ�����\n");	
								--i;
								continue;
							}
						}
					}
					else{					
						while(getchar()!='\n'){;}
						printf("����������������������\n"); 
						--i;
					} 
				}
				else{				
				while(getchar()!='\n'){;}
				printf("����������������������\n");
				--i;
			}
			}
			else{
			while(getchar()!='\n'){;}
			printf("����������������������\n");
			--i;
			} 
}
	printf("��Ϸ�ѽ�����ƽ��"); //��i�Ƿ������������Ѿ����� 

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


	/*while(getchar()=='\n'){
			if(Board[SIZE-x][y-'a']<=9&&Board[SIZE-x][y-'a']>=1){
				Board[SIZE-x][y-'a'] = BLACKtem;	//�ı������Ӧ����ֵ
	    		DisplayBoard();	//��ʾ����
	    		
		}
			else{
				printf("�������������⣬����������");
				while(getchar()!='\n'){;}
				getchar();
		}
			//while(getchar()=='\n'){;}
			/*printf("�������������⣬����������");
			while(getchar()=='\n'){;};
		}
		while(getchar()!='\n'){
			printf("�������Ӳ��Ϸ�������������");
			while(getchar()!='\n'){;} 
			getchar();
		}}
		if(i%2==1){
			//scanf("%c%d",&y,&x);  //�����Ļ���������
			/*if(x<48||x>57){
			printf("�������������⣬����������");
			while(getchar()=='\n');
			}
		//	while(getchar()=='\n')
		scanf("%c%d",&y,&x);  //�����Ļ���������
		while(getchar()=='\n'){
			if(Board[SIZE-x][y-'a']<=9&&Board[SIZE-x][y-'a']>=1){
			Board[SIZE-x][y-'a'] = WHITEtem;	//�ı������Ӧ����ֵ
	    	DisplayBoard();	//��ʾ����
			}
			else{
			printf("�������������⣬����������");
			while(getchar()!='\n'){;}
			getchar();
			}
		}
		while(getchar()!='\n'){
			printf("�������Ӳ��Ϸ�������������");
			while(getchar()!='\n'){;} 
			getchar();
		}
		while(getchar()!='\n'){
			printf("�������Ӳ��Ϸ�������������");
			while(getchar()!='\n'){;} 
			getchar();
		}
		//printf("�������������⣬����������");
		//while(getchar()=='\n');
		}*/
