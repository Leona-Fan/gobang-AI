#define SIZE 15
#define BLACKtem 10
#define WHITEtem 11
#define BLACK 20
#define WHITE 21

int Board[SIZE][SIZE];
int init[8];//����תһ�ܹ�8������ÿ������һ����Ŀ,��������ͬɫ���� 
int initBlank[8];//����Ŀհ׸����� 
int next[8];//init���ͬɫ���� 
int nextBlank[8];//next��Ŀհ׸����� 
int third[8]; //nextBlank���ͬɫ���� 
int state[4];//״̬ 
int count;//�ڼ�����

void InitBoardArray();  //��ʼ��������
void DisplayBoard();	//��ʾ����
int winjudge(int color,int w, int v);	//��Ӯ�ж� 
int number(int color,int w,int v);//�жϰ˸������ϵ������������Ͽ�ʼ 
int banhand(int w,int v);//�����жϣ�����˫����˫�ĵ���� 
int evaluateboard1(int color);//��������λ�����֣����� 
int evaluateboard2(int color);//��������λ�����֣��Է� 
void getMaxEvaluate(int leftstep,int color,int s[]);//����Сֵ���� 
void input1();//��ȡ�˹����� 
void input2(int color);//�������� 
void removechess();//���AI����ʱģ������ 
void move(int color,int i,int j);//AI����ʱģ������ 
void Max(int color,int s[]);//�������������ظ�����ʱ�ı��� 
void record(void);//��¼����״̬������AI����ʱ�ı����� 
void showback(void);//��ԭ���� 
