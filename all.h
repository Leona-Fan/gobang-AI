#define SIZE 15
#define BLACKtem 10
#define WHITEtem 11
#define BLACK 20
#define WHITE 21

int Board[SIZE][SIZE];
int init[8];//自上转一周共8个方向，每个方向一个数目,离得最近的同色子数 
int initBlank[8];//最近的空白格子数 
int next[8];//init后的同色子数 
int nextBlank[8];//next后的空白格子数 
int third[8]; //nextBlank后的同色子数 
int state[4];//状态 
int count;//第几步棋

void InitBoardArray();  //初始化空棋盘
void DisplayBoard();	//显示棋盘
int winjudge(int color,int w, int v);	//输赢判断 
int number(int color,int w,int v);//判断八个方向上的棋子数，自上开始 
int banhand(int w,int v);//禁手判断，包括双三和双四的情况 
int evaluateboard1(int color);//对于下棋位置评分，本方 
int evaluateboard2(int color);//对于下棋位置评分，对方 
void getMaxEvaluate(int leftstep,int color,int s[]);//极大极小值搜索 
void input1();//获取人工输入 
void input2(int color);//机器下子 
void removechess();//清除AI运算时模拟下子 
void move(int color,int i,int j);//AI运算时模拟下子 
void Max(int color,int s[]);//当搜索树出现重复下子时的备用 
void record(void);//记录棋盘状态，避免AI运算时改变棋盘 
void showback(void);//复原棋盘 
