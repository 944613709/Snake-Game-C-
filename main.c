#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <mmsystem.h>

#define up 'w'
#define down 's'
#define left 'a'
#define right 'd'
#define stop 'p'

void welcome();				   //55开始界面
void Finish();	               //291结束界面
int color(int c);
void menu();
void creatgraph();			   //69围墙打印
void gotoxy(int x, int y);	   //111光标跳转，横为X 0,1,2..
void gotoprint(int x, int y);  //121跳转打印
void gotodelete(int x, int y); //127跳转删除
void creatfood();			   //133食物产生
int ClickControl();			   //157获取键盘信号
int Judge();				   //270游戏结束判断
void MovingBody();			   //172蛇的移动
void Eating();				   //223蛇吃到东西后的操作（伸长）
void ChangeBody(int a, int b); //245蛇的坐标变换,后一个复制前一个STRUCT,a,b为head之前坐标

/*全局变量 + 预处理：*/
typedef struct Snakes
{
	int x;
	int y;
	struct Snakes *next;
} snake;

snake *head, *tail;

struct Food
{
	int x;
	int y;
} food;
char name[20];
int score = 0;
char click = 'w';
int speed;
int n;
char sel;

/************************************************************/
int main()
{
	welcome();
	//mciSendString("open C:\\snake\\2.mp3", NULL, 0, NULL);
    //mciSendString("play C:\\snake\\2.mp3", NULL, 0, NULL);
	lable:
    menu();
	creatgraph();
	creatfood();
	if (ClickControl() == 0)
	{
		if(sel=='y'||sel=='Y')
		{
		    system("cls");
			sel ='n';
			goto lable;
		}
        gotoxy(18, 22);
        color(10);
        printf("thanks for playing!\n");
        gotoxy(18, 28);
        system("pause");
		return 0;
	}

}

/**********************************************************/
void welcome()
{
	gotoxy(10, 1);
    color(2);
	printf(" /**************************************************************/");
    printf("                                                                                         \n");
	printf("                       __________       ___                                              \n");
	printf("                      /          \\     / \\ \\    |____      __\\__                     \n");
	printf("                     /  ________  \\   / ___ \\  _/ __     | |   /                       \n");
	printf("                     |  |      |__|     _/_   |_|  /    [|] |/                           \n");
	printf("                     |  |              | | |      /     _|_ \\__/                        \n");
	printf("                     \\  \\_______        / \\      |___/        ____                    \n");
	printf("                      \\         \\    ____ ____      ____   __ |  |  ___   ______       \n");
	printf("                       \\_______  \\   |  |/    \\    /    \\_/ / |  | /  /  /      \\   \n");
	printf("                               \\  \\  |    ___  \\  / ____   /  |  |/  /  /  ____  \\   \n");
	printf("                     __        |  |  |   /   \\  \\ | |  |  /   |     /  |  /____\\  |   \n");
	printf("                    \\  \\_______|  |  |  |    |  | | |__|  |   |     \\  |  ________/   \n");
	printf("                     \\            /  |  |    |  |  \\       \\  |  |\\  \\  \\  \\____  \n");
	printf("                      \\__________/   |__|    |__|   \\___/\\__\\ |__| \\__\\  \\______/ \n");
	gotoxy(10, 25);
	printf("/**************************************************************/");
	gotoxy(20, 18);
	printf("欢迎来到贪吃蛇游戏:)");
	gotoxy(20, 20);
	printf("请在英文输入法中操作，反向移动等同于吃到自己，wasd控制p暂停");
    color(10);
	gotoxy(20, 22);
	printf("请输入你的姓名:");
	scanf("%s", name);
	system("cls");
}

void menu()
{
    lable :
    gotoxy(10, 1);
    color(2);
	printf("/**************************************************************/");
    printf("                                                                                         \n");
	printf("                       __________       ___                                              \n");
	printf("                      /          \\     / \\ \\    |____      __\\__                     \n");
	printf("                     /  ________  \\   / ___ \\  _/ __     | |   /                       \n");
	printf("                     |  |      |__|     _/_   |_|  /    [|] |/                           \n");
	printf("                     |  |              | | |      /     _|_ \\__/                        \n");
	printf("                     \\  \\_______        / \\      |___/        ____                    \n");
	printf("                      \\         \\    ____ ____      ____   __ |  |  ___   ______       \n");
	printf("                       \\_______  \\   |  |/    \\    /    \\_/ / |  | /  /  /      \\   \n");
	printf("                               \\  \\  |    ___  \\  / ____   /  |  |/  /  /  ____  \\   \n");
	printf("                     __        |  |  |   /   \\  \\ | |  |  /   |     /  |  /____\\  |   \n");
	printf("                    \\  \\_______|  |  |  |    |  | | |__|  |   |     \\  |  ________/   \n");
	printf("                     \\            /  |  |    |  |  \\       \\  |  |\\  \\  \\  \\____  \n");
	printf("                      \\__________/   |__|    |__|   \\___/\\__\\ |__| \\__\\  \\______/ \n");
	gotoxy(10, 31);
	printf("/**************************************************************/");
    color(10);
    gotoxy(35, 20);
	printf("┌-------------------------------┐\n");
	int i; 
    for(i=21;i<26;i++)
    {
        gotoxy(35, i);
        printf("│                               │\n");
    }
	gotoxy(35, 26);
	printf("└-------------------------------┘\n");
	gotoxy(42, 22);
	color(13);
	printf("1.开始游戏");
    color(11);
	gotoxy(42, 24);
	printf("2.退出游戏");
	gotoxy(42,27);
	color(3);
	printf("请选择[1 2]:[ ]\b\b");        //\b为退格，使得光标处于[]中间
	color(14);
    scanf("%d", &n); 					//输入选项
    switch (n)
    {
    	case 1:					//选择开始游戏
    		system("cls");
        	break;
    	case 2:
        	color(6);
            gotoxy(42, 29);
            printf("高考加油!╰(●’?’●)╮\n");
			color(1);
            system("pause");
            exit(0);
        	break;
		default:				//输入非1~3之间的选项
			color(12);
			gotoxy(42,29);
			printf("请输入1~2之间的数!");
			getch();			//输入任意键
			system("cls");		//清屏
            goto lable ;
    }
}

/**********************************************************/
void creatgraph()
{
	int i;
	srand((int)time(NULL));
	color(rand()%12+1);
	for (i = 0; i < 58; i += 2) //打印上下边框
	{
		gotoprint(i, 0);
		gotoprint(i, 26);
	}
	for (i = 1; i < 26; i++)
	{
		gotoprint(0, i);
		gotoprint(56, i);
	}
	gotoxy(63, 10);
	printf("你好 %s ,欢迎游玩", name);
	gotoxy(63, 15);
	printf("你当前的分数是 %d    =￣ω￣= ，奥利给！！", score);
	head = (snake *)malloc(sizeof(snake));
	head->x = 16;
	head->y = 15;
	tail = (snake *)malloc(sizeof(snake));
	snake *p = (snake *)malloc(sizeof(snake));
	snake *q = (snake *)malloc(sizeof(snake));
	p->x = 16;
	p->y = 16;
	q->x = 16;
	q->y = 17;
	head->next = p;
	p->next = q;
	q->next = tail;
	tail->next = NULL;
	tail->x = 4;
	tail->y = 2;
}
/**********************************************************/
void gotoxy(int x, int y)
{
	COORD pos;
	HANDLE hOutput;
	pos.X = x;
	pos.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, pos);
}
/**********************************************************/
void gotoprint(int x, int y)
{
	gotoxy(x, y);
	printf("■");
}
/**********************************************************/
void gotodelete(int x, int y)
{
	gotoxy(x, y);
	printf("  ");
}
/**********************************************************/
void creatfood()
{
	srand((int)time(NULL));
    lable:
	food.y = rand() % (25 - 1 + 1) + 1;
	food.x = rand() % (54 - 2 + 1) + 2;
	if (food.x % 2 != 0)
	{
		food.x = food.x + 1;
	}
	snake *judge = head;
	while (1) //遍历排除蛇身重复
	{
		if (judge->next == NULL)
			break;
		if (food.x == judge->x && food.y == judge->y)
		{
			goto lable;
		}
		judge = judge->next;
	}
	gotoxy(food.x, food.y);
	printf("⊙");
}
/**********************************************************/
int ClickControl()
{
	while (1)
	{
		if (Judge() == 0 )
			return 0;
		if (_kbhit())
		{
			click = _getch();
		}
		MovingBody();
		Eating();
	}
	return 1;
}
/**********************************************************/
void MovingBody()
{
	int count = 0;
	int a = head->x, b = head->y;
	snake *p = head;
	//通过先清空后打印实现动画效果
	while (1)
	{
		if (p->next == NULL)
			break;
		gotodelete(p->x, p->y);
		count++;
		p = p->next;
	}
	switch (click)
	{
	case up:
		head->y -= 1;
		ChangeBody(a, b);
		break;
	case down:
		head->y += 1;
		ChangeBody(a, b);
		break;
	case left:
		head->x -= 2;
		ChangeBody(a, b);
		break;
	case right:
		head->x += 2;
		ChangeBody(a, b);
		break;
	case stop:
		_getch();
		break;
	}
	p = head;
	while (1)
	{
		if (p->next == NULL)
			break;
		gotoprint(p->x, p->y);
		p = p->next;
	}
	p = head;
	gotoxy(0, 28);
	if (count <= 10)
		speed = 150;
	else if (count > 10 && count <= 20)
		speed = 100;
	else if (count > 20 && count <= 40)
		speed = 50;
	else
		speed = 25;
	Sleep(speed);
}
/**********************************************************/
void Eating()
{
	if (head->x == food.x && head->y == food.y)
	{
		creatfood();
		snake *_new = (snake *)malloc(sizeof(snake));
		snake *p;
		p = head;
		while (1)
		{
			if (p->next->next == NULL)
				break;
			p = p->next;
		}
		p->next = _new;
		_new->next = tail;
		score += 10;
		gotoxy(77, 15);

		if(score<=290)
			printf("%d", score);
	}
}
/**********************************************************/
void ChangeBody(int a, int b)
{
	snake *p = head->next;
	int mid1, mid2, _mid1, _mid2;
	mid1 = p->x;
	mid2 = p->y;
	while (1)
	{
		if (p->next->next == NULL)
			break;
		_mid1 = p->next->x;
		_mid2 = p->next->y;
		p->next->x = mid1;
		p->next->y = mid2;
		mid1 = _mid1;
		mid2 = _mid2;
		p = p->next;
	}
	p = head->next;
	//if (p->next!= NULL)
	{
		p->x = a;
		p->y = b;
	}
}
/**********************************************************/
int Judge()
{
	if (head->x == 0 || head->x == 56 || head->y == 0 || head->y == 26)
	{
		Finish();
		return 0;
	}
	snake *p = head->next;
	while (1)
	{
		if (p->next == NULL)
			break;
		if (head->x == p->x && head->y == p->y)
		{
			click='w';
			Finish();
			return 0;
		}
		p = p->next;
	}
	return 1;
}
/**********************************************************/
void Finish()
{
	system("cls");
	gotoxy(10, 1);
	printf("/**************************************************************/");
			gotoxy(18, 2);
		    printf("\n                                                               \n");
            printf("            ****          ****    ******************    ******************  \n");
            printf("            ****          ****    ******************    ******************  \n");
            printf("            ****          ****           ****                  ****  \n");
            printf("            ****          ****           ****                  **** \n");
            printf("            ******************           ****                  ****      \n");
            printf("            ******************           ****                  ****   \n");
            printf("            ****          ****           ****                  ****   \n");
            printf("            ****          ****           ****                  ****   \n");
            printf("            ****          ****    ******************           ****   \n");
            printf("            ****          ****    ******************           ****   \n"); 
	gotoxy(10, 25);
	printf("/**************************************************************/");
	gotoxy(18, 14);
	color(2);
	printf("过程   淘汰      o(*￣▽￣*)o");
	gotoxy(20, 16);
	color(3);
	printf("你的最终分数是 %d    hiahiahia", score);
	gotoxy(18, 18);
	color(4);
	printf("还不错哦，     继续努力O(∩_∩)O\n");
	gotoxy(18, 20);
	color(8);
	printf("规格严格，功夫到家\n");
	gotoxy(18, 22);
	color(9);
	printf("重修？（Y/N）");
	getchar();
	sel=getchar();
}

int color(int c)
{
	//SetConsoleTextAttribute是API设置控制台窗口字体颜色和背景色的函数
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);        //更改文字颜色
	return 0;
}

