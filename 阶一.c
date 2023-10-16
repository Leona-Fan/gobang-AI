#include <stdio.h>

#define SIZE 15
#define BLACKtem 10
#define WHITEtem 11
#define BLACK 20
#define WHITE 21

int Board[SIZE][SIZE];

void InitBoardArray();  //初始化空棋盘
void DisplayBoard();	//显示棋盘
int winjudge();	//输赢判断 

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
								Board[SIZE-xx-10+48][y-'a'] = BLACKtem;	//改变数组对应的数值
	    						DisplayBoard();	//显示棋盘
	    						w=SIZE-xx-10+48;
	    						v=y-'a';
	    						printf("最后落子%c%d\n",y,xx+10-48); 
	    				}
	    					else{
	    						printf("请勿重复落子\n");
								--i;
								continue;
							} 
						}
						if(i%2==1){
							if(Board[SIZE-xx-10+48][y-'a']<=9&&Board[SIZE-xx-10+48][y-'a']>=1){
								Board[w][v]=BLACK;
								Board[SIZE-xx-10+48][y-'a'] = WHITEtem;	//改变数组对应的数值
	    						DisplayBoard();	//显示棋盘
	    						w=SIZE-xx-10+48;
	    						v=y-'a';
	    						printf("最后落子%c%d\n",y,xx+10-48); 
							}
							else{
								printf("请勿重复落子\n");
								--i;
								continue;
							}
						}
					}
						else{
							while(getchar()!='\n'){;}
							printf("您的输入有误，请重新输入\n");
							--i;
						}
					}
					else if(xx=='\n') {
						if(i%2==0){
							if(Board[SIZE-x+48][y-'a']<=9&&Board[SIZE-x+48][y-'a']>=1){
								Board[w][v]=WHITE;
								Board[SIZE-x+48][y-'a'] = BLACKtem;	//改变数组对应的数值
	    						DisplayBoard();	//显示棋盘
	    						w=SIZE-x+48;
	    						v=y-'a';
	    						printf("最后落子%c%d\n",y,x-48); 
	    					}
	    					else{
								printf("请勿重复落子\n");
								--i;
								continue;
							} 
						}
						if(i%2==1){
							if(Board[SIZE-x+48][y-'a']<=9&&Board[SIZE-x+48][y-'a']>=1){
								Board[w][v]=BLACK;
								Board[SIZE-x+48][y-'a'] = WHITEtem;	//改变数组对应的数值
	    						DisplayBoard();	//显示棋盘
	    						w=SIZE-x+48;
	    						v=y-'a';
	    						printf("最后落子%c%d\n",y,x-48);
							}
							else{							
								printf("请勿重复落子\n");	
								--i;
								continue;
							}
						}
					}
					else{					
						while(getchar()!='\n'){;}
						printf("您的输入有误，请重新输入\n"); 
						--i;
					} 
				}
				else{				
				while(getchar()!='\n'){;}
				printf("您的输入有误，请重新输入\n");
				--i;
			}
			}
			else{
			while(getchar()!='\n'){;}
			printf("您的输入有误，请重新输入\n");
			--i;
			} 
}
	printf("游戏已结束，平局"); //用i记放子数，棋盘已经放满 

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
	
	system("cls");   //清屏

	for(j = 0,line = 15; j <= SIZE - 1; j++)
	{
		printf("%2d",line);
		line -= 1;
		for(i = 0; i <= SIZE - 1; i++)
		{
			switch(Board[j][i])
			{
			case 1:
				printf("┏");
				break;
				
			case 2:
				printf("┓");
				break;
				
			case 3:
				printf("┛");
				break;
				
			case 4:
				printf("┗");
				break;
				
			case 5:
				printf("┠");
				break;
				
			case 6:
				printf("┯");
				break;
				
			case 7:
				printf("┨");
				break;
				
			case 8:
				printf("┷");
				break;
				
			case 9:
				printf("┼");
				break;
				
			case BLACKtem:      // 黑子上一步
				printf("▲");
				break;
				
			case WHITEtem:      //白子上一步
				printf("△");
				break;
				
			case BLACK:      //黑子通常
				printf("●");
				break;
				
			case WHITE:
				printf("○");  //白子通常
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
				Board[SIZE-x][y-'a'] = BLACKtem;	//改变数组对应的数值
	    		DisplayBoard();	//显示棋盘
	    		
		}
			else{
				printf("您的落子有问题，请重新落子");
				while(getchar()!='\n'){;}
				getchar();
		}
			//while(getchar()=='\n'){;}
			/*printf("您的落子有问题，请重新落子");
			while(getchar()=='\n'){;};
		}
		while(getchar()!='\n'){
			printf("您的落子不合法，请重新落子");
			while(getchar()!='\n'){;} 
			getchar();
		}}
		if(i%2==1){
			//scanf("%c%d",&y,&x);  //获得屏幕输入的坐标
			/*if(x<48||x>57){
			printf("您的落子有问题，请重新落子");
			while(getchar()=='\n');
			}
		//	while(getchar()=='\n')
		scanf("%c%d",&y,&x);  //获得屏幕输入的坐标
		while(getchar()=='\n'){
			if(Board[SIZE-x][y-'a']<=9&&Board[SIZE-x][y-'a']>=1){
			Board[SIZE-x][y-'a'] = WHITEtem;	//改变数组对应的数值
	    	DisplayBoard();	//显示棋盘
			}
			else{
			printf("您的落子有问题，请重新落子");
			while(getchar()!='\n'){;}
			getchar();
			}
		}
		while(getchar()!='\n'){
			printf("您的落子不合法，请重新落子");
			while(getchar()!='\n'){;} 
			getchar();
		}
		while(getchar()!='\n'){
			printf("您的落子不合法，请重新落子");
			while(getchar()!='\n'){;} 
			getchar();
		}
		//printf("您的落子有问题，请重新落子");
		//while(getchar()=='\n');
		}*/
