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
	printf("AI为黑子请输入1，AI为白子请输入2，人人对战请输入3\n");
	int gettype;
	gettype=getchar();
	getchar();//将选择模式后的输入清空 
	 
	while(gettype=='2'&&count<225&&winornot!=1&&banornot!=1){//AI为白子，使用winornot和banornot分别判断输赢和禁手，如果有赢方或黑子下禁手则程序结束 
		if(count%2==0){
			printf("请输入落子位置，输入合法方式如h8\n");
			input1();
		}	
		else
			input2(WHITE);	
	}
	while(gettype=='1'&&count<225&&winornot!=1&&banornot!=1){//AI为黑子 
		if(count%2==1){
			printf("请输入落子位置，输入合法方式如h8\n");
			input1();
		}
		else
			input2(BLACK);	
	}
	while(gettype=='3'&&count<225&&winornot!=1&&banornot!=1) {//人人对战 
			printf("请输入落子位置，输入合法方式如h8\n");
			input1();
		}
	
	
}

void input1(){//手动输入 
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
								Board[SIZE-xx-10+48][y-'a'] = BLACKtem;	//改变数组对应的数值
	    						DisplayBoard();	//显示棋盘
	    						w=SIZE-xx-10+48;
	    						v=y-'a';
	    						printf("黑子最后落子%c%d\n",y,xx+10-48); 
	    						banornot=banhand(w,v);//判断是否违反禁手 
	    						if(banornot==1){
									printf("黑子违反禁手，WHITE WIN");
								}
	    						winornot=winjudge(BLACK,w,v);//判断是否赢 
	    						count++;
	    				}
	    					else{
	    						printf("请勿重复落子\n");
							} 
						}
						else if(count%2==1){
							if(Board[SIZE-xx-10+48][y-'a']<=9&&Board[SIZE-xx-10+48][y-'a']>=1){
								Board[w][v]=BLACK;
								Board[SIZE-xx-10+48][y-'a'] = WHITEtem;	//改变数组对应的数值
	    						DisplayBoard();	//显示棋盘
	    						w=SIZE-xx-10+48;
	    						v=y-'a';
	    						printf("白子最后落子%c%d\n",y,xx+10-48); 
	    						winornot=winjudge(WHITE,w,v);
	    						count++;
							}
							else{
								printf("请勿重复落子\n");
							}
						}
					}
						else{
							while(getchar()!='\n'){;}
							printf("您的输入有误，请重新输入\n");
						}
					}
					else if(xx=='\n') {
						if(count%2==0){
							if(Board[SIZE-x+48][y-'a']<=9&&Board[SIZE-x+48][y-'a']>=1){
								Board[w][v]=WHITE;
								Board[SIZE-x+48][y-'a'] = BLACKtem;	//改变数组对应的数值
	    						DisplayBoard();	//显示棋盘
	    						w=SIZE-x+48;
	    						v=y-'a';
	    						printf("黑子最后落子%c%d\n",y,x-48); 
	    						banornot=banhand(w,v);
	    						if(banornot==1){
									printf("黑子违反禁手，WHITE WIN");
								}
	    						winornot=winjudge(BLACK,w,v);
	    						count++;
	    					}
	    					else{
								printf("请勿重复落子\n");
							} 
						}
						else if(count%2==1){
							if(Board[SIZE-x+48][y-'a']<=9&&Board[SIZE-x+48][y-'a']>=1){
								Board[w][v]=BLACK;
								Board[SIZE-x+48][y-'a'] = WHITEtem;	//改变数组对应的数值
	    						DisplayBoard();	//显示棋盘
	    						w=SIZE-x+48;
	    						v=y-'a';
	    						printf("白子最后落子%c%d\n",y,x-48);
	    						winornot=winjudge(WHITE,w,v);
	    						count++;
							}
							else{							
								printf("请勿重复落子\n");	
							}
						}
					}
					else{					
						while(getchar()!='\n'){;}
						printf("您的输入有误，请重新输入\n"); 
					} 
				}
				else{				
				while(getchar()!='\n'){;}
				printf("您的输入有误，请重新输入\n");
			}
			}
			else{
			while(getchar()!='\n'){;}
			printf("您的输入有误，请重新输入\n");
			} 
}

void input2(int color){//AI输入 
	int m,n;
	int s[3];
	if(count==0){//第一个子下在h8 
		Board[7][7]=BLACKtem;
		DisplayBoard();
		w=7;
		v=7;
		printf("AI黑子最后落子%c%d\n",7+'a',7+1);
		count++;
	}
	else if(count==1&&Board[7][7]!=BLACKtem){//如果第一个子未下在h8则白子下在h8 
		Board[7][7]=WHITEtem;
		Board[w][v]=BLACK;
		w=7;
		v=7;
		DisplayBoard();
		printf("AI白子最后落子%c%d\n",7+'a',7+1);
		count++;
	}
	else if(count==1){//直接规定AI第一个白子下在h8右侧 
		Board[7][8]=WHITEtem;
		Board[w][v]=BLACK;
		w=7;
		v=8;
		DisplayBoard();
		printf("AI白子最后落子%c%d\n",7+'a',8+1);
		count++;
	}
	else{//AI正常下子 
		record();//记录棋盘 
		getMaxEvaluate(2,color,s);//两层搜索深度的搜索树 
		showback();//复原棋盘 
		m=s[0];
		n=s[1];
		if(Board[m][n]==BLACK||Board[m][n]==WHITE||Board[m][n]==BLACKtem||Board[m][n]==WHITEtem){
			Max(color,s);
			showback();
			m=s[0];
			n=s[1];
		}//如果搜索树出现问题重复下子，则使用评估棋盘来下子 
		
		if(count%2==0){
		if(banhand(m,n)==1){//若产生禁手，则使用评估棋盘下子 
			Max(color,s);
			showback();
			m=s[0];
			n=s[1];
		}
			Board[m][n]=BLACKtem;
			Board[w][v]=WHITE;
			DisplayBoard();
			printf("AI黑子最后落子%c%d\n",n+'a',15-m);
			banornot=banhand(m,n);
			if(banornot==1){
				printf("黑子违反禁手，WHITE WIN");
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
			printf("AI白子最后落子%c%d\n",n+'a',15-m);
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

