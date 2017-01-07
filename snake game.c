#include<iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;
const int height=40;
const int width=11;
bool gameover;
int x,y,fx,fy,score;
int i,j,k;
int tx[150],ty[150];
int tn;
enum D{stop=0,up,down,left,right};
D dir;
void start()
{
	gameover=false;
	score=0;
	dir=stop;
	y = width / 2;
	x = height / 2;
	fy = rand() % width;
	fx = rand() % height;
}

void draw()
{
	system("cls");
	for(i=0;i<height;i++)
		cout<<'#';
	cout<<endl;
	for(i=0;i<width;i++)
	{
		for(j=0;j<height;j++)
		{
			if(j==0||j==height-1)
				cout<<'#';
			else if(i==y&&j==x)
				cout<<'O';
			else if(i==fy&&j==fx)
				cout<<'*';
			else
			{
				bool check=false;
				for(k=0;k<tn;k++)
				{
					if(tx[k]==j&&ty[k]==i)
					{
						cout<<'o';
						check=true;
					}
				}
				if(!check)
					cout<<" ";
			}
		}
		cout<<endl;
	}
	for(i=0;i<height;i++)
		cout<<"#";
	cout<<endl;
	cout<<"Score : "<<score<<endl;
}

void input()
{
	if(kbhit())
	{
		switch (getch())
		{
			case 'a':
				dir=D::left;
				break;
			case 'd':
				dir=D::right;
				break;
			case 'w':
				dir=D::up;
				break;
			case 's':
				dir=D::down;
				break;
			case 'q':
				gameover=true;
				break;
		}
	}

}

void logic()
{
	int prex,prey,prex2,prey2;
	prex=tx[0];
	prey=ty[0];
	for(i=1;i<tn;i++)
	{
		prex2=tx[i];
		prey2=ty[i];
		tx[i]=prex;
		ty[i]=prey;
		prex=prex2;
		prey=prey2;
		tx[0]=x;
		ty[0]=y;
	}
	for(i=1;i<tn;i++)
		if(tx[i]==x&&ty[i]==y)
			gameover=true;
	switch (dir)
	{
		case up:
			y--;
			break;
		case down:
			y++;
			break;
		case D::left:
			x--;
			break;
		case D::right:
			x++;
			break;
	}
	if(x>height-2)x=0;else if(x<=0) x=height-2;
	if(y>=width)y=0;else if(y<0)y=width; 
	if(fx==x&&fy==y)
	{
		score+=5;
		fx=rand()%height;
		fy=rand()%width;
		tn++;
	}
}




int main ()
{
	system("Color 6");
	cout<<endl<<"              welcom in snack game !!  GO to play ........."<<endl<<endl<<endl<<endl;
	cout<<endl<<"    UP = W        DoWN = S   LEFT = A    Right = D        " <<endl<<endl<<endl<<endl;
	system("pause");
	system("cls");
	start();
	while(!gameover)
	{
		draw();
		input();
		logic();
		Sleep(20);
	}
	system("cls");
	system("Color 4");

	cout<<"                      |||||||||||||||||||||||"<<endl
		 <<"            |||||||||||||||||||||||||||||||||||||||||||"<<endl
		 <<"       ||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl
	     <<"    ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||  "<<endl;
	cout<<"|||||||||||||||||||||||||| GAMEOVER!  |||||||||||||||||||||||||||||||||"<<endl
		 <<"    ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||  "<<endl
		 <<"	  |||||||||||||||||||||||||||||||||||||||||||||||||||||||  "<<endl
		 <<"		   ||||||||||||||||||||||||||||||||||||||||||||"<<endl;
		 

	system("pause");
	return 0;
}
