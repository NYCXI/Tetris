#include <iostream>
#include <windows.h>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <conio.h>

#define random(x) (rand()%x)

using namespace std;

void setcolor();
void setcolorback();
bool printA(int x,int y,int x_last,int num,bool screen[51][70],bool ifprint,bool remove);
bool printB(int x,int y,int x_last,int num,bool screen[51][70],bool ifprint,bool remove);
bool printC(int x,int y,int x_last,int num,bool screen[51][70],bool ifprint,bool remove);
bool printD(int x,int y,int x_last,int num,bool screen[51][70],bool ifprint,bool remove);
bool printE(int x,int y,int x_last,int num,bool screen[51][70],bool ifprint,bool remove);
bool printF(int x,int y,int x_last,int num,bool screen[51][70],bool ifprint,bool remove);
bool printG(int x,int y,int x_last,int num,bool screen[51][70],bool ifprint,bool remove);
bool card_print_now(int now[],int x,int y,int x_last,bool screen[51][70],bool ifprint);
void gotoxy(int x,int y);
void control(int *x,int *y,int x_last,bool *accelerate,int now[],bool screen[51][70]);
void screen_update(int x,int y,int now[],bool screen[51][70]);
void screen_print(bool screen[51][70],int cols,int lines);
void screen_remove(bool screen[51][70],int cols,int lines);
void card_remove_lastframe(int x,int x_last,int y_last,int last[2],bool screen[51][70]);
void setback();
void setinit();
void setrecover();
void gamesetting_select(int *cols,int *lines,int *sec);
void gamesetting_size(int cur,int *cols,int *lines);
void first_page(int *cols,int*lines,int *sec);
void gamesetting_difficulty(int cur,int *sec);
bool gameover_check(bool screen[51][70],int cols,int lines);
void print_next(int next[2],int now[2],int cols,int lines);
void print_score(int cols,int lines);
void pause();

int score=0;

void setcolor(){
	int n;
	n=random(7)+1;
	switch(n){
		case 1:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
			break;
		case 2:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
			break;
		case 3:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
			break;
		case 4:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);
			break;
		case 5:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
			break;
		case 6:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
			break;
		case 7:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);
			break;
	}
}

void setcolorback(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
}

	//■■■
	// ■
bool printA(int x,int y,int x_last,int num,bool screen[51][70],bool ifprint,bool remove){
	bool area[3][3]={false};
	switch(num){
		case 1:
			area[0][1]=true;
			area[1][0]=true;
			area[1][1]=true;
			area[1][2]=true;
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
					if(area[i][j]&&screen[y+i][x+j*2])
						return false;								//	3*3方格，用来判断是否可以移动以及是否碰撞

			if(ifprint)
			{
				if(remove)											//	清除上一帧
				{
					setcolorback();
					gotoxy(x_last+2,y-1);
					cout<<"  ";
					gotoxy(x_last,y);
					cout<<"      ";
				}
				else												//	打印当前
				{
					setcolor();
					gotoxy(x+2,y);
					cout<<"■";
					gotoxy(x,y+1);
					cout<<"■■■";
					gotoxy(0,0);
				}
			}
			return true;
		case 2:
			area[0][0]=true;
			area[1][0]=true;
			area[1][1]=true;
			area[2][0]=true;
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
					if(area[i][j]&&screen[y+i][x+j*2])
						return false;

			if(ifprint)
			{
				if(remove)
				{
					setcolorback();
					gotoxy(x_last,y-1);
					cout<<"  ";
					gotoxy(x_last,y);
					cout<<"    ";
					gotoxy(x_last,y+1);
					cout<<"  ";
				}
				else
				{
					setcolor();
					gotoxy(x,y);
					cout<<"■";
					gotoxy(x,y+1);
					cout<<"■■";
					gotoxy(x,y+2);
					cout<<"■";
					gotoxy(0,0);
				}
			}
			return true;
		case 3:
			area[0][0]=true;
			area[0][1]=true;
			area[0][2]=true;
			area[1][1]=true;
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
					if(area[i][j]&&screen[y+i][x+j*2])
						return false;

			if(ifprint)
			{
				if(remove)
				{
					setcolorback();
					gotoxy(x_last,y-1);
					cout<<"      ";
					gotoxy(x_last+2,y);
					cout<<"  ";
				}
				else
				{
					setcolor();
					gotoxy(x,y);
					cout<<"■■■";
					gotoxy(x+2,y+1);
					cout<<"■";
					gotoxy(0,0);
				}
			}
			return true;
		case 4:
			area[0][1]=true;
			area[1][0]=true;
			area[1][1]=true;
			area[2][1]=true;
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
					if(area[i][j]&&screen[y+i][x+j*2])
						return false;

			if(ifprint)
			{
				if(remove)
				{
					setcolorback();
					gotoxy(x_last+2,y-1);
					cout<<"  ";
					gotoxy(x_last,y);
					cout<<"    ";
					gotoxy(x_last+2,y+1);
					cout<<"  ";
				}
				else
				{
					setcolor();
					gotoxy(x+2,y);
					cout<<"■";
					gotoxy(x,y+1);
					cout<<"■■";
					gotoxy(x+2,y+2);
					cout<<"■";
					gotoxy(0,0);
				}
			}
			return true;
	}
}

	//■
	//■■■
bool printB(int x,int y,int x_last,int num,bool screen[51][70],bool ifprint,bool remove){
	bool area[3][3]={false};
	switch(num){
		case 1:
			area[0][0]=true;
			area[1][0]=true;
			area[1][1]=true;
			area[1][2]=true;
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
					if(area[i][j]&&screen[y+i][x+j*2])
						return false;

			if(ifprint)
			{
				if(remove)
				{
					setcolorback();
					gotoxy(x_last,y-1);
					cout<<"  ";
					gotoxy(x_last,y);
					cout<<"      ";
				}
				else
				{
					setcolor();
					gotoxy(x,y);
					cout<<"■";
					gotoxy(x,y+1);
					cout<<"■■■";
					gotoxy(0,0);
				}
			}
			return true;
		case 2:
			area[0][0]=true;
			area[0][1]=true;
			area[1][0]=true;
			area[2][0]=true;
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
					if(area[i][j]&&screen[y+i][x+j*2])
						return false;

			if(ifprint)
			{
				if(remove)
				{
					setcolorback();
					gotoxy(x_last,y-1);
					cout<<"    ";
					gotoxy(x_last,y);
					cout<<"  ";
					gotoxy(x_last,y+1);
					cout<<"  ";
				}
				else
				{
					setcolor();
					gotoxy(x,y);
					cout<<"■■";
					gotoxy(x,y+1);
					cout<<"■";
					gotoxy(x,y+2);
					cout<<"■";
					gotoxy(0,0);
				}
			}
			return true;
		case 3:
			area[0][0]=true;
			area[0][1]=true;
			area[0][2]=true;
			area[1][2]=true;
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
					if(area[i][j]&&screen[y+i][x+j*2])
						return false;

			if(ifprint)
			{
				if(remove)
				{
					setcolorback();
					gotoxy(x_last,y-1);
					cout<<"      ";
					gotoxy(x_last+4,y);
					cout<<"  ";
				}
				else
				{
					setcolor();
					gotoxy(x,y);
					cout<<"■■■";
					gotoxy(x+4,y+1);
					cout<<"■";
					gotoxy(0,0);
				}
			}
			return true;
		case 4:
			area[0][1]=true;
			area[1][1]=true;
			area[2][0]=true;
			area[2][1]=true;
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
					if(area[i][j]&&screen[y+i][x+j*2])
						return false;

			if(ifprint)
			{
				if(remove)
				{
					setcolorback();
					gotoxy(x_last+2,y-1);
					cout<<"  ";
					gotoxy(x_last+2,y);
					cout<<"  ";
					gotoxy(x_last,y+1);
					cout<<"    ";
				}
				else
				{
					setcolor();
					gotoxy(x+2,y);
					cout<<"■";
					gotoxy(x+2,y+1);
					cout<<"■";
					gotoxy(x,y+2);
					cout<<"■■";
					gotoxy(0,0);
				}
			}
			return true;
	}
}		

	//■■■■■
bool printC(int x,int y,int x_last,int num,bool screen[51][70],bool ifprint,bool remove){
	bool area[5][5]={false};
	switch(num){
		case 1:
			area[0][0]=true;
			area[0][1]=true;
			area[0][2]=true;
			area[0][3]=true;
			area[0][4]=true;
			for(int i=0;i<5;i++)
				for(int j=0;j<5;j++)
					if(area[i][j]&&screen[y+i][x+j*2])
						return false;

			if(ifprint)
			{
				if(remove)
				{
					setcolorback();
					gotoxy(x_last,y-1);
					cout<<"          ";
				}
				else
				{
					setcolor();
					gotoxy(x,y);
					cout<<"■■■■■";
					gotoxy(0,0);
				}
			}
			return true;
		case 2:
			area[0][0]=true;
			area[1][0]=true;
			area[2][0]=true;
			area[3][0]=true;
			area[4][0]=true;
			for(int i=0;i<5;i++)
				for(int j=0;j<5;j++)
					if(area[i][j]&&screen[y+i][x+j*2])
						return false;

			if(ifprint)
			{
				if(remove)
				{
					setcolorback();
					gotoxy(x_last,y-1);
					cout<<"  ";
					gotoxy(x_last,y);
					cout<<"  ";
					gotoxy(x_last,y+1);
					cout<<"  ";
					gotoxy(x_last,y+2);
					cout<<"  ";
					gotoxy(x_last,y+3);
					cout<<"  ";
				}
				else
				{
					setcolor();
					gotoxy(x,y);
					cout<<"■";
					gotoxy(x,y+1);
					cout<<"■";
					gotoxy(x,y+2);
					cout<<"■";
					gotoxy(x,y+3);
					cout<<"■";
					gotoxy(x,y+4);
					cout<<"■";
					gotoxy(0,0);
				}
			}
			return true;
		case 3:
			area[0][0]=true;
			area[0][1]=true;
			area[0][2]=true;
			area[0][3]=true;
			area[0][4]=true;
			for(int i=0;i<5;i++)
				for(int j=0;j<5;j++)
					if(area[i][j]&&screen[y+i][x+j*2])
						return false;

			if(ifprint)
			{
				if(remove)
				{
					setcolorback();
					gotoxy(x_last,y-1);
					cout<<"          ";
				}
				else
				{
					setcolor();
					gotoxy(x,y);
					cout<<"■■■■■";
					gotoxy(0,0);
				}
			}
			return true;
		case 4:
			area[0][0]=true;
			area[1][0]=true;
			area[2][0]=true;
			area[3][0]=true;
			area[4][0]=true;
			for(int i=0;i<5;i++)
				for(int j=0;j<5;j++)
					if(area[i][j]&&screen[y+i][x+j*2])
						return false;

			if(ifprint)
			{
				if(remove)
				{	
					setcolorback();
					gotoxy(x_last,y-1);
					cout<<"  ";
					gotoxy(x_last,y);
					cout<<"  ";
					gotoxy(x_last,y+1);
					cout<<"  ";
					gotoxy(x_last,y+2);
					cout<<"  ";
					gotoxy(x_last,y+3);
					cout<<"  ";
				}
				else
				{
					setcolor();
					gotoxy(x,y);
					cout<<"■";
					gotoxy(x,y+1);
					cout<<"■";
					gotoxy(x,y+2);
					cout<<"■";
					gotoxy(x,y+3);
					cout<<"■";
					gotoxy(x,y+4);
					cout<<"■";
					gotoxy(0,0);
				}
			}
			return true;	
	}
}

	//  ■
	//■■■
bool printD(int x,int y,int x_last,int num,bool screen[51][70],bool ifprint,bool remove){
	bool area[3][3]={false};
	switch(num){
		case 1:
			area[0][2]=true;
			area[1][0]=true;
			area[1][1]=true;
			area[1][2]=true;
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
					if(area[i][j]&&screen[y+i][x+j*2])
						return false;

			if(ifprint)
			{
				if(remove)
				{
					setcolorback();
					gotoxy(x_last+4,y-1);
					cout<<"  ";
					gotoxy(x_last,y);
					cout<<"      ";
				}
				else
				{
					setcolor();
					gotoxy(x+4,y);
					cout<<"■";
					gotoxy(x,y+1);
					cout<<"■■■";
					gotoxy(0,0);
				}
			}
			return true;
		case 2:
			area[0][0]=true;
			area[1][0]=true;
			area[2][0]=true;
			area[2][1]=true;
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
					if(area[i][j]&&screen[y+i][x+j*2])
						return false;

			if(ifprint)
			{
				if(remove)
				{
					setcolorback();
					gotoxy(x_last,y-1);
					cout<<"  ";
					gotoxy(x_last,y);
					cout<<"  ";
					gotoxy(x_last,y+1);
					cout<<"    ";
				}
				else
				{
					setcolor();
					gotoxy(x,y);
					cout<<"■";
					gotoxy(x,y+1);
					cout<<"■";
					gotoxy(x,y+2);
					cout<<"■■";
					gotoxy(0,0);
				}
			}
			return true;
		case 3:
			area[0][0]=true;
			area[0][1]=true;
			area[0][2]=true;
			area[1][0]=true;
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
					if(area[i][j]&&screen[y+i][x+j*2])
						return false;

			if(ifprint)
			{
				if(remove)
				{
					setcolorback();
					gotoxy(x_last,y-1);
					cout<<"      ";
					gotoxy(x_last,y);
					cout<<"  ";
				}
				else
				{
					setcolor();
					gotoxy(x,y);
					cout<<"■■■";
					gotoxy(x,y+1);
					cout<<"■";
					gotoxy(0,0);
				}
			}
			return true;
		case 4:
			area[0][0]=true;
			area[0][1]=true;
			area[1][1]=true;
			area[2][1]=true;
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
					if(area[i][j]&&screen[y+i][x+j*2])
						return false;

			if(ifprint)
			{
				if(remove)
				{
					setcolorback();
					gotoxy(x_last,y-1);
					cout<<"    ";
					gotoxy(x_last+2,y);
					cout<<"  ";
					gotoxy(x_last+2,y+1);
					cout<<"  ";
				}
				else
				{
					setcolor();
					gotoxy(x,y);
					cout<<"■■";
					gotoxy(x+2,y+1);
					cout<<"■";
					gotoxy(x+2,y+2);
					cout<<"■";
					gotoxy(0,0);
				}
			}
			return true;
	}
}			

	// ■■
	//■■
bool printE(int x,int y,int x_last,int num,bool screen[51][70],bool ifprint,bool remove){
	bool area[3][3]={false};
	switch(num){
		case 1:
			area[0][1]=true;
			area[0][2]=true;
			area[1][0]=true;
			area[1][1]=true;
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
					if(area[i][j]&&screen[y+i][x+j*2])
						return false;

			if(ifprint)
			{
				if(remove)
				{
					setcolorback();
					gotoxy(x_last+2,y-1);
					cout<<"    ";
					gotoxy(x_last,y);
					cout<<"    ";
				}
				else
				{
					setcolor();
					gotoxy(x+2,y);
					cout<<"■■";
					gotoxy(x,y+1);
					cout<<"■■";
					gotoxy(0,0);
				}
			}
			return true;
		case 2:
			area[0][0]=true;
			area[1][0]=true;
			area[1][1]=true;
			area[2][1]=true;
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
					if(area[i][j]&&screen[y+i][x+j*2])
						return false;

			if(ifprint)
			{
				if(remove)
				{
					setcolorback();
					gotoxy(x_last,y-1);
					cout<<"  ";
					gotoxy(x_last,y);
					cout<<"    ";
					gotoxy(x_last+2,y+1);
					cout<<"  ";
				}
				else
				{
					setcolor();
					gotoxy(x,y);
					cout<<"■";
					gotoxy(x,y+1);
					cout<<"■■";
					gotoxy(x+2,y+2);
					cout<<"■";
					gotoxy(0,0);
				}
			}
			return true;
		case 3:
			area[0][1]=true;
			area[0][2]=true;
			area[1][0]=true;
			area[1][1]=true;
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
					if(area[i][j]&&screen[y+i][x+j*2])
						return false;

			if(ifprint)
			{
				if(remove)
				{
					setcolorback();
					gotoxy(x_last+2,y-1);
					cout<<"    ";
					gotoxy(x_last,y);
					cout<<"    ";
				}
				else
				{
					setcolor();
					gotoxy(x+2,y);
					cout<<"■■";
					gotoxy(x,y+1);
					cout<<"■■";
					gotoxy(0,0);
				}
			}
			return true;
		case 4:
			area[0][0]=true;
			area[1][0]=true;
			area[1][1]=true;
			area[2][1]=true;
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
					if(area[i][j]&&screen[y+i][x+j*2])
						return false;

			if(ifprint)
			{
				if(remove)
				{
					setcolorback();
					gotoxy(x_last,y-1);
					cout<<"  ";
					gotoxy(x_last,y);
					cout<<"    ";
					gotoxy(x_last+2,y+1);
					cout<<"  ";
				}
				else
				{
					setcolor();
					gotoxy(x,y);
					cout<<"■";
					gotoxy(x,y+1);
					cout<<"■■";
					gotoxy(x+2,y+2);
					cout<<"■";
					gotoxy(0,0);
				}
			}
			return true;
	}
}

	//■■
	// ■■
bool printF(int x,int y,int x_last,int num,bool screen[51][70],bool ifprint,bool remove){
	bool area[3][3]={false};
	switch(num){
		case 1:
			area[0][0]=true;
			area[0][1]=true;
			area[1][1]=true;
			area[1][2]=true;
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
					if(area[i][j]&&screen[y+i][x+j*2])
						return false;

			if(ifprint)
			{
				if(remove)
				{
					setcolorback();
					gotoxy(x_last,y-1);
					cout<<"    ";
					gotoxy(x_last+2,y);
					cout<<"    ";
				}
				else
				{
					setcolor();
					gotoxy(x,y);
					cout<<"■■";
					gotoxy(x+2,y+1);
					cout<<"■■";
					gotoxy(0,0);
				}
			}
			return true;
		case 2:
			area[0][1]=true;
			area[1][0]=true;
			area[1][1]=true;
			area[2][0]=true;
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
					if(area[i][j]&&screen[y+i][x+j*2])
						return false;

			if(ifprint)
			{
				if(remove)
				{
					setcolorback();
					gotoxy(x_last+2,y-1);
					cout<<"  ";
					gotoxy(x_last,y);
					cout<<"    ";
					gotoxy(x_last,y+1);
					cout<<"  ";
				}
				else
				{
					setcolor();
					gotoxy(x+2,y);
					cout<<"■";
					gotoxy(x,y+1);
					cout<<"■■";
					gotoxy(x,y+2);
					cout<<"■";
					gotoxy(0,0);
				}
			}
			return true;
		case 3:
			area[0][0]=true;
			area[0][1]=true;
			area[1][1]=true;
			area[1][2]=true;
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
					if(area[i][j]&&screen[y+i][x+j*2])
						return false;

			if(ifprint)
			{
				if(remove)
				{
					setcolorback();
					gotoxy(x_last,y-1);
					cout<<"    ";
					gotoxy(x_last+2,y);
					cout<<"    ";
				}
				else
				{
					setcolor();
					gotoxy(x,y);
					cout<<"■■";
					gotoxy(x+2,y+1);
					cout<<"■■";
					gotoxy(0,0);
				}
			}
			return true;
		case 4:
			area[0][1]=true;
			area[1][0]=true;
			area[1][1]=true;
			area[2][0]=true;
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
					if(area[i][j]&&screen[y+i][x+j*2])
						return false;

			if(ifprint)
			{
				if(remove)
				{
					setcolorback();
					gotoxy(x_last+2,y-1);
					cout<<"  ";
					gotoxy(x_last,y);
					cout<<"    ";
					gotoxy(x_last,y+1);
					cout<<"  ";
				}
				else
				{
					setcolor();
					gotoxy(x+2,y);
					cout<<"■";
					gotoxy(x,y+1);
					cout<<"■■";
					gotoxy(x,y+2);
					cout<<"■";
					gotoxy(0,0);
				}
			}
			return true;
	}
}

	//■■
	//■■
bool printG(int x,int y,int x_last,int num,bool screen[51][70],bool ifprint,bool remove){
	bool area[2][2];
	switch(num){
		case 1:
			area[0][0]=true;
			area[0][1]=true;
			area[1][0]=true;
			area[1][1]=true;
			for(int i=0;i<2;i++)
				for(int j=0;j<2;j++)
					if(area[i][j]&&screen[y+i][x+j*2])
						return false;

			if(ifprint)
			{
				if(remove)
				{
					setcolorback();
					gotoxy(x_last,y-1);
					cout<<"    ";
					gotoxy(x_last,y);
					cout<<"    ";
				}
				else
				{
					setcolor();
					gotoxy(x,y);
					cout<<"■■";
					gotoxy(x,y+1);
					cout<<"■■";
					gotoxy(0,0);
				}
			}
			return true;
		case 2:
			area[0][0]=true;
			area[0][1]=true;
			area[1][0]=true;
			area[1][1]=true;
			for(int i=0;i<2;i++)
				for(int j=0;j<2;j++)
					if(area[i][j]&&screen[y+i][x+j*2])
						return false;

			if(ifprint)
			{
				if(remove)
				{
					setcolorback();
					gotoxy(x_last,y-1);
					cout<<"    ";
					gotoxy(x_last,y);
					cout<<"    ";
				}
				else
				{
					setcolor();
					gotoxy(x,y);
					cout<<"■■";
					gotoxy(x,y+1);
					cout<<"■■";
					gotoxy(0,0);
				}
			}
			return true;
		case 3:
			area[0][0]=true;
			area[0][1]=true;
			area[1][0]=true;
			area[1][1]=true;
			for(int i=0;i<2;i++)
				for(int j=0;j<2;j++)
					if(area[i][j]&&screen[y+i][x+j*2])
						return false;

			if(ifprint)
			{
				if(remove)
				{
					setcolorback();
					gotoxy(x_last,y-1);
					cout<<"    ";
					gotoxy(x_last,y);
					cout<<"    ";
				}
				else
				{
					setcolor();
					gotoxy(x,y);
					cout<<"■■";
					gotoxy(x,y+1);
					cout<<"■■";
					gotoxy(0,0);
				}
			}
			return true;
		case 4:
			area[0][0]=true;
			area[0][1]=true;
			area[1][0]=true;
			area[1][1]=true;
			for(int i=0;i<2;i++)
				for(int j=0;j<2;j++)
					if(area[i][j]&&screen[y+i][x+j*2])
						return false;
			if(ifprint)
			{
				if(remove)
				{
					setcolorback();
					gotoxy(x_last,y-1);
					cout<<"    ";
					gotoxy(x_last,y);
					cout<<"    ";
				}
				else
				{
					setcolor();
					gotoxy(x,y);
					cout<<"■■";
					gotoxy(x,y+1);
					cout<<"■■";
					gotoxy(0,0);
				}
			}
			return true;
	}
}

void gotoxy(int x,int y){
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo; 
	HANDLE hConsoleOut;
	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);
	csbiInfo.dwCursorPosition.X = x; 
	csbiInfo.dwCursorPosition.Y = y; 
	SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition); 
}	

bool card_print_now(int now[],int x,int y,int x_last,bool screen[51][70],bool ifprint){
	switch(now[0]){
		case 0:
			if(!printA(x,y,x_last,now[1],screen,ifprint,false))
				return false;
			break;
		case 1:
			if(!printB(x,y,x_last,now[1],screen,ifprint,false))
				return false;
			break;
		case 2:
			if(!printC(x,y,x_last,now[1],screen,ifprint,false))
				return false;
			break;
		case 3:
			if(!printD(x,y,x_last,now[1],screen,ifprint,false))
				return false;
			break;
		case 4:
			if(!printE(x,y,x_last,now[1],screen,ifprint,false))
				return false;
			break;
		case 5:
			if(!printF(x,y,x_last,now[1],screen,ifprint,false))
				return false;
			break;
		case 6:
			if(!printG(x,y,x_last,now[1],screen,ifprint,false))
				return false;
			break;
	}
	//screen_print(screen);
	return true;
}																			//输出当前方块

void control(int *x,int *y,int x_last,bool *accelerate,int now[],bool screen[51][70]){
	int ch;
	while(kbhit())
	{
		if((ch=getch())!=0x1B)
		{
			if(ch==' ')
			pause();
			switch(ch)
			{
				case 0xE0:
				switch(ch=getch())
				{
					case 72:
						if(now[1]==4)
							now[1]=1;
						else
							now[1]++;
						break;									//切换方块朝向
					case 80:
						*accelerate=true;
						break;									//加速
					case 75:
						if(card_print_now(now,*x-2,*y,x_last,screen,false))
						{
							card_remove_lastframe(*x,*x,*y,now,screen);
							*x-=2;
						}
						break;									//左移
					case 77:
						if(card_print_now(now,*x+2,*y,x_last,screen,false))
						{
							card_remove_lastframe(*x,*x,*y,now,screen);
							*x+=2;
						}
						break;									//右移
					default:
						break;
				}
				break;
			default:
				break;
			}
		}
	}
	return;
}																			//控制方块控制//上下左右

void screen_update(int x,int y,int now[],bool screen[51][70]){
	switch(now[0]){
		case 0:
			switch(now[1]){
				case 1:
					screen[y][x+2]=true;
					screen[y+1][x]=true;
					screen[y+1][x+2]=true;
					screen[y+1][x+4]=true;
					break;
				case 2:
					screen[y][x]=true;
					screen[y+1][x]=true;
					screen[y+1][x+2]=true;
					screen[y+2][x]=true;
					break;
				case 3:
					screen[y][x]=true;
					screen[y][x+2]=true;
					screen[y][x+4]=true;
					screen[y+1][x+2]=true;
					break;
				case 4:
					screen[y][x+2]=true;
					screen[y+1][x]=true;
					screen[y+1][x+2]=true;
					screen[y+2][x+2]=true;
					break;
			}break;
		case 1:
			switch(now[1]){
				case 1:
					screen[y][x]=true;
					screen[y+1][x]=true;
					screen[y+1][x+2]=true;
					screen[y+1][x+4]=true;
					break;
				case 2:
					screen[y][x]=true;
					screen[y][x+2]=true;
					screen[y+1][x]=true;
					screen[y+2][x]=true;
					break;
				case 3:
					screen[y][x]=true;
					screen[y][x+2]=true;
					screen[y][x+4]=true;
					screen[y+1][x+4]=true;
					break;
				case 4:
					screen[y][x+2]=true;
					screen[y+1][x+2]=true;
					screen[y+2][x]=true;
					screen[y+2][x+2]=true;
					break;
			}break;
		case 2:
			switch(now[1]){
				case 1:
					screen[y][x]=true;
					screen[y][x+2]=true;
					screen[y][x+4]=true;
					screen[y][x+6]=true;
					screen[y][x+8]=true;
					break;
				case 2:
					for(int i=0;i<5;i++)
						screen[y+i][x]=true;
					break;
				case 3:
					screen[y][x]=true;
					screen[y][x+2]=true;
					screen[y][x+4]=true;
					screen[y][x+6]=true;
					screen[y][x+8]=true;
					break;
				case 4:
					for(int i=0;i<5;i++)
						screen[y+i][x]=true;
					break;
			}break;
		case 3:
			switch(now[1]){
				case 1:
					screen[y][x+4]=true;
					screen[y+1][x]=true;
					screen[y+1][x+2]=true;
					screen[y+1][x+4]=true;
					break;
				case 2:
					screen[y][x]=true;
					screen[y+1][x]=true;
					screen[y+2][x]=true;
					screen[y+2][x+2]=true;
					break;
				case 3:
					screen[y][x]=true;
					screen[y][x+2]=true;
					screen[y][x+4]=true;
					screen[y+1][x]=true;
					break;
				case 4:
					screen[y][x]=true;
					screen[y][x+2]=true;
					screen[y+1][x+2]=true;
					screen[y+2][x+2]=true;
					break;
			}break;
		case 4:
			switch(now[1]){
				case 1:
					screen[y][x+2]=true;
					screen[y][x+4]=true;
					screen[y+1][x]=true;
					screen[y+1][x+2]=true;
					break;
				case 2:
					screen[y][x]=true;
					screen[y+1][x]=true;
					screen[y+1][x+2]=true;
					screen[y+2][x+2]=true;
					break;
				case 3:
					screen[y][x+2]=true;
					screen[y][x+4]=true;
					screen[y+1][x]=true;
					screen[y+1][x+2]=true;
					break;
				case 4:
					screen[y][x]=true;
					screen[y+1][x]=true;
					screen[y+1][x+2]=true;
					screen[y+2][x+2]=true;
					break;
			}break;
		case 5:
			switch(now[1]){
				case 1:
					screen[y][x]=true;
					screen[y][x+2]=true;
					screen[y+1][x+2]=true;
					screen[y+1][x+4]=true;
					break;
				case 2:
					screen[y][x+2]=true;
					screen[y+1][x]=true;
					screen[y+1][x+2]=true;
					screen[y+2][x]=true;
					break;
				case 3:
					screen[y][x]=true;
					screen[y][x+2]=true;
					screen[y+1][x+2]=true;
					screen[y+1][x+4]=true;
					break;
				case 4:
					screen[y][x+2]=true;
					screen[y+1][x]=true;
					screen[y+1][x+2]=true;
					screen[y+2][x]=true;
					break;
			}break;
		case 6:
			switch(now[1]){
				case 1:
					screen[y][x]=true;
					screen[y][x+2]=true;
					screen[y+1][x]=true;
					screen[y+1][x+2]=true;
					break;
				case 2:
					screen[y][x]=true;
					screen[y][x+2]=true;
					screen[y+1][x]=true;
					screen[y+1][x+2]=true;
					break;
				case 3:
					screen[y][x]=true;
					screen[y][x+2]=true;
					screen[y+1][x]=true;
					screen[y+1][x+2]=true;
					break;
				case 4:
					screen[y][x]=true;
					screen[y][x+2]=true;
					screen[y+1][x]=true;
					screen[y+1][x+2]=true;
					break;
			}break;
	}
}																			//屏幕更新，是否有方块

void screen_print(bool screen[51][70],int cols,int lines){
	for(int y=0;y<lines+1;y++)
	{
		for(int x=0;x<cols;x++)
			if(screen[y][x])
			{
				setcolorback();
				gotoxy(x,y);
				cout<<"■";
			}
	}
}																			//将屏幕中已有方块输出

void screen_remove(bool screen[51][70],int cols,int lines){
	bool flag=false,flag1=false;
	int rate=1;
	for(int i=0;i<lines;i++)
	{
		for(int j=0;j<cols;j+=2)
			if(screen[i][j])
				flag=true;
			else
			{
				flag=false;
				break;
			}
		if(flag)
		{
			system("cls");
			for(int j=0;j<cols;j++)
				screen[i][j]=false;
			for(int k=i;k>0;k--)
				for(int j=0;j<cols;j+=2)
					screen[k][j]=screen[k-1][j];
			score+=10*rate;
			rate++;
		}
		else
			rate=1;

	}
}																			//将一整行方块移除并将上面的方块向下移动一行

void card_remove_lastframe(int x,int x_last,int y_last,int last[2],bool screen[51][70]){
	switch(last[0]){
		case 0:printA(x,y_last,x_last,last[1],screen,true,true);break;
		case 1:printB(x,y_last,x_last,last[1],screen,true,true);break;
		case 2:printC(x,y_last,x_last,last[1],screen,true,true);break;
		case 3:printD(x,y_last,x_last,last[1],screen,true,true);break;
		case 4:printE(x,y_last,x_last,last[1],screen,true,true);break;
		case 5:printF(x,y_last,x_last,last[1],screen,true,true);break;
		case 6:printG(x,y_last,x_last,last[1],screen,true,true);break;
	}
}																			//清除上一个位置的方块

void setback(){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY);
}																			//字体背景

void setinit(){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY);
}																			//字体颜色

void setrecover(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
}																			//字体恢复

void first_page(int *cols,int*lines,int *sec){
	gotoxy(4,10);
	cout<<"TTTTTTTT";
	gotoxy(4,11);
	cout<<"   TT";
	gotoxy(4,12);
	cout<<"   TT";
	gotoxy(4,13);
	cout<<"   TT";
	gotoxy(4,14);
	cout<<"   TT";
	Sleep(70);

	gotoxy(14,10);
	cout<<"EEEEEEEE";
	gotoxy(14,11);
	cout<<"EE";
	gotoxy(14,12);
	cout<<"EEEEEEEE";
	gotoxy(14,13);
	cout<<"EE";
	gotoxy(14,14);
	cout<<"EEEEEEEE";
	Sleep(70);

	gotoxy(24,10);
	cout<<"TTTTTTTT";
	gotoxy(24,11);
	cout<<"   TT";
	gotoxy(24,12);
	cout<<"   TT";
	gotoxy(24,13);
	cout<<"   TT";
	gotoxy(24,14);
	cout<<"   TT";
	Sleep(70);

	gotoxy(34,10);
	cout<<"RRRRRRR";
	gotoxy(34,11);
	cout<<"RR    RR";
	gotoxy(34,12);
	cout<<"RRRRRRR";
	gotoxy(34,13);
	cout<<"RR RR";
	gotoxy(34,14);
	cout<<"RR   RR";
	Sleep(70);

	gotoxy(44,10);
	cout<<"  IIII";
	gotoxy(44,11);
	cout<<"   II";
	gotoxy(44,12);
	cout<<"   II";
	gotoxy(44,13);
	cout<<"   II";
	gotoxy(44,14);
	cout<<"  IIII";
	Sleep(70);

	gotoxy(54,10);
	cout<<"SSSSSSSS";
	gotoxy(54,11);
	cout<<"SS";
	gotoxy(54,12);
	cout<<"SSSSSSSS";
	gotoxy(54,13);
	cout<<"      SS";
	gotoxy(54,14);
	cout<<"SSSSSSSS";

	HANDLE client=GetStdHandle(STD_OUTPUT_HANDLE);
	setback();
	COORD now={30,35};
	SetConsoleCursorPosition(client,now);
	cout<<"开始游戏";
	setinit();
	gotoxy(30,38);
	cout<<"游戏设置";
	char ch;
	int cur=1;
	while(ch=getch())
	{
		if(ch==13)
			break;
		if(ch==-32)
		{
			ch=getch();
			switch(ch)
			{
				case 72:
				{
					if(cur==2)
					{
						cur=1;
						setback();
						gotoxy(30,35);
						cout<<"开始游戏";
						setinit();
						gotoxy(30,38);
						cout<<"游戏设置";
					}
					break;	
				}
				case 80:
				{
					if(cur==1)
					{
						cur=2;
						setinit();
						gotoxy(30,35);
						cout<<"开始游戏";
						setback();
						gotoxy(30,38);
						cout<<"游戏设置";
					}
					break;
				}
			}
		}
	}
	setrecover();
	if(cur==1)
	{
		system("cls");
		system("mode con cols=70 lines=41");
		return;
	}
	if(cur==2)
	{
		system("cls");
		system("mode con cols=50 lines=41");
		gamesetting_select(cols,lines,sec);
	}
}																			//第一个页面，包括设置选择

void gamesetting_select(int *cols,int *lines,int *sec){
	system("cls");
	gotoxy(4,4);
	cout<<"游戏设置:";
	HANDLE client=GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(6,6);
	setback();
	cout<<"窗口大小设置>";
	gotoxy(6,8);
	setinit();
	cout<<"游戏难度设置>";
	char ch;
	int cur=1;
	while(ch=getch())
	{
		if(ch==13)
			break;
		if(ch==-32)
		{
			ch=getch();
			switch(ch){
				case 72:
					if(cur==2)
					{
						cur=1;
						gotoxy(6,6);
						setback();
						cout<<"窗口大小设置>";
						gotoxy(6,8);
						setinit();
						cout<<"游戏难度设置>";
					}
					break;
				case 80:
					if(cur==1)
					{
						cur=2;
						gotoxy(6,6);
						setinit();
						cout<<"窗口大小设置>";
						gotoxy(6,8);
						setback();
						cout<<"游戏难度设置>";
					}
					break;
				default:break;
			}
		}
	}
	setrecover();
	if(cur==1)						//窗口大小设置
	{
		system("cls");
		gotoxy(4,4);
		cout<<"游戏设置:";
		gotoxy(6,6);
		setback();
		cout<<"窗口大小设置>";
		gotoxy(10,8);
		setback();
		cout<<"small(20*30)";
		gotoxy(10,10);
		setinit();
		cout<<"middle(25*40)";
		gotoxy(10,12);
		setinit();
		cout<<"large(35*50)";
		gotoxy(6,15);
		setinit();
		cout<<"游戏难度设置>";
		char ch;
		int cur1=1;
		while(ch=getch())
		{
			if(ch==13)
				break;
			if(ch==-32)
			{
				ch=getch();
				switch(ch){
					case 72:
						if(cur1==2)
						{
							cur1=1;
							gotoxy(10,8);
							setback();
							cout<<"small(20*30)";
							gotoxy(10,10);
							setinit();
							cout<<"middle(25*40)";
							gotoxy(10,12);
							setinit();
							cout<<"large(35*50)";
						}
						if(cur1==3)
						{
							cur1=2;
							gotoxy(10,8);
							setinit();
							cout<<"small(20*30)";
							gotoxy(10,10);
							setback();
							cout<<"middle(25*40)";
							gotoxy(10,12);
							setinit();
							cout<<"large(35*50)";
						}
						break;
					case 80:
						if(cur1==2)
						{
							cur1=3;
							gotoxy(10,8);
							setinit();
							cout<<"small(20*30)";
							gotoxy(10,10);
							setinit();
							cout<<"middle(25*40)";
							gotoxy(10,12);
							setback();
							cout<<"large(35*50)";
						}
						if(cur1==1)
						{
							cur1=2;
							gotoxy(10,8);
							setinit();
							cout<<"small(20*30)";
							gotoxy(10,10);
							setback();
							cout<<"middle(25*40)";
							gotoxy(10,12);
							setinit();
							cout<<"large(35*50)";
						}
						break;
					case 75:
						gamesetting_select(cols,lines,sec);
						return;
						break;
					default:break;
				}
			}
		}
		setrecover();
		gamesetting_size(cur1,cols,lines);
	}
	if(cur==2)						//游戏难度设置 下落速度
	{
		system("cls");
		gotoxy(4,4);
		cout<<"游戏设置:";
		gotoxy(6,6);
		setinit();
		cout<<"窗口大小设置>";
		gotoxy(6,8);
		setback();
		cout<<"游戏难度设置>";
		gotoxy(10,10);
		setback();
		cout<<"easy";
		gotoxy(10,12);
		setinit();
		cout<<"medium";
		gotoxy(10,14);
		setinit();
		cout<<"hard";

		char ch;
		int cur1=1;
		while(ch=getch())
		{
			if(ch==13)
				break;
			if(ch==-32)
			{
				ch=getch();
				switch(ch){
					case 72:
						if(cur1==2)
						{
							cur1=1;
							gotoxy(10,10);
							setback();
							cout<<"easy";
							gotoxy(10,12);
							setinit();
							cout<<"medium";
							gotoxy(10,14);
							setinit();
							cout<<"hard";
						}
						if(cur1==3)
						{
							cur1=2;
							gotoxy(10,10);
							setinit();
							cout<<"easy";
							gotoxy(10,12);
							setback();
							cout<<"medium";
							gotoxy(10,14);
							setinit();
							cout<<"hard";
						}
						break;
					case 80:
						if(cur1==2)
						{
							cur1=3;
							gotoxy(10,10);
							setinit();
							cout<<"easy";
							gotoxy(10,12);
							setinit();
							cout<<"medium";
							gotoxy(10,14);
							setback();
							cout<<"hard";
						}
						if(cur1==1)
						{
							cur1=2;
							gotoxy(10,10);
							setinit();
							cout<<"easy";
							gotoxy(10,12);
							setback();
							cout<<"medium";
							gotoxy(10,14);
							setinit();
							cout<<"hard";
						}
						break;
					case 75:
						gamesetting_select(cols,lines,sec);
						return;
						break;
					default: break;
				}
			}
		}
		setrecover();
		gamesetting_difficulty(cur1,sec);
	}
}																			//设置选择

void gamesetting_size(int cur,int *cols,int *lines){
	switch(cur){
		case 1:
			*cols=40;
			*lines=30;
			system("mode con cols=60 lines=31");
			return;
		case 2:
			*cols=50;
			*lines=40;
			system("mode con cols=70 lines=41");
			return;
		case 3:
			*cols=70;
			*lines=50;
			system("mode con cols=90 lines=51");
			return;
	}
}																			//窗口尺寸设置

void gamesetting_difficulty(int cur,int *sec){
	switch(cur){
		case 1:
			*sec=400;
			system("mode con cols=70 lines=41");
			break;
		case 2:
			*sec=200;
			system("mode con cols=70 lines=41");
			break;
		case 3:
			*sec=100;
			system("mode con cols=70 lines=41");
			break;
	}
}																			//设置难度 下落速度

bool gameover_check(bool screen[51][70],int cols,int lines){
	for(int i=2;i<cols-4;i+=2)
		if(screen[0][i])
			return true;
	return false;
}

void print_next(int next[2],int now[2],int cols,int lines){
	bool fake[51][70]={false};
	gotoxy(cols+5,lines/4);
	cout<<"下一个:";
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
		{
			gotoxy(cols+7+i,lines/4+j+2);
			cout<<' ';
		}
	switch(next[0]){
		case 0:
			printA(cols+7,lines/4+2,0,next[1],fake,true,false);
			break;
		case 1:
			printB(cols+7,lines/4+2,0,next[1],fake,true,false);
			break;
		case 2:
			printC(cols+7,lines/4+2,0,next[1],fake,true,false);
			break;
		case 3:
			printD(cols+7,lines/4+2,0,next[1],fake,true,false);
			break;
		case 4:
			printE(cols+7,lines/4+2,0,next[1],fake,true,false);
			break;
		case 5:
			printF(cols+7,lines/4+2,0,next[1],fake,true,false);
			break;
		case 6:
			printG(cols+7,lines/4+2,0,next[1],fake,true,false);
			break;
	}												
}

void print_score(int cols,int lines){
	gotoxy(cols+5,lines-lines/4);
	cout<<"SCORE:"<<score;
}

void pause(){
	int ch;
	int flag;
	for(int i=1;i>0;i++)
	{
		flag=0;
		while(kbhit())
		{
			ch=getch();
			if(ch==' ')
			{
				flag=1;
				break;
			}
			else
				break;
		}
		if(flag==1)
			break;
	}
}

int main(){
	int now[2],next[2],last[2];
	int cols=50,lines=40;
	int sec=400;
	bool screen[51][70]={false};

	system("mode con cols=70 lines=51");
	first_page(&cols,&lines,&sec);
	system("cls");
	setrecover();

	for(int i=0;i<cols;i+=2)
		screen[lines][i]=true;
	for(int i=0;i<lines;i++)
		screen[i][0]=true;
	for(int i=0;i<lines;i++)
		screen[i][cols-2]=true;					//边框

	srand((unsigned)time(NULL));
		now[0]=random(7);
		next[0]=random(7);
		now[1]=random(4)+1;
		next[1]=random(4)+1;					//初始化当前方块和下一次的方块		
		
	score=0;

	while(true){
		print_score(cols,lines);
		print_next(next,now,cols,lines);
		int x,x_last;
		x=cols/2;
		if(x%2)
			x++;
		bool accelerate=false;

		screen_print(screen,cols,lines);
		for(int y=0;y<lines+1;y++)
		{
			accelerate=false;
			x_last=x;
			for(int i=0;i<2;i++)
				last[i]=now[i];
			if(card_print_now(now,x,y,x_last,screen,false))
				control(&x,&y,x_last,&accelerate,now,screen);
			if(y)
				card_remove_lastframe(x,x_last,y,last,screen);
			if(!card_print_now(now,x,y,x_last,screen,true))
			{
				screen_update(x,y-1,now,screen);
				break;
			}
			if(accelerate)
				Sleep(40);
			else
				Sleep(sec);
		}
		if(gameover_check(screen,cols,lines))
		{
			system("cls");
			gotoxy(cols/2-10,lines/2);
			cout<<"YOUR TOTAL SCORE IS:";
			gotoxy(cols/2,lines/2+2);
			cout<<score;
			break;
		}
		score+=2;
		screen_remove(screen,cols,lines);
		for(int i=0;i<2;i++)
			now[i]=next[i];
		next[0]=random(7);
		next[1]=random(4)+1;
		//testmode(now);
	}
	return 0;
}