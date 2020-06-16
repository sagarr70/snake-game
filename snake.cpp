#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
int width = 40, height = 40;
int x, y, gameover = 0, foodx, foody, flag, score = 0;
int tailx[100], taily[100];
int couyt = 0;
void input()
{
	if (kbhit())
	{
		switch (getch())
		{
		case 'w':
		{
			flag = 1;
			break;
		}
		case 'a':
		{
			flag = 2;
			break;
		}
		case 's':
		{
			flag = 3;
			break;
		}
		case 'd':
		{
			flag = 4;
			break;
		}
		case 'x':
		{
			gameover = 1;
			break;
		}
		}
	}
}
void setup()
{  clrscr();
   couyt=0;
   score=0;
	x = width / 2;
	y = height / 2;
label1:
	foodx = rand() % 40;
	if (foodx == 0)
	{
		goto label1;
	}
label2:
	foody = rand() % 40;
	if (foody == 0)
	{
		goto label2;
	}
}
void board()
{
	clrscr();
	int i, j, k;
	if (x == 0 || x == height - 1 || y == 0 || y == width - 1)
	{
		cout << "GAME OVER --> press Y to play again OR any other key to exit";
		char u;
		u=cin.get();
		if(u=='Y'||u=='y')
		{ setup();
		}
		else{
		gameover = 1;}
	}
	for(i=0;i<couyt;i++)
	{ 
	if(x==tailx[i]&&y==taily[i])
	{ cout << "GAME OVER --> press Y to play again OR any other key to exit";
		char u;
		u=cin.get();
		if(u=='Y'||u=='y')
		{ setup();
		}
		else{
		gameover = 1;}}
	}

	cout << "score : " << score << endl;
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
			{
				cout << "#";
			}
			else
			{
				if (i == x && j == y)
				{
					cout << "O";
				}
				else
				{
					if (i == foodx && j == foody)
					{
						cout << "F";
					}
					else
					{
						int m = 0;
						for (k = 0; k < couyt; k++)
						{
							if (i == tailx[k] && j == taily[k])
							{
								cout << "o";
								m = 1;
							}
						}
						if (m == 0)
						{
							cout << " ";
						}
					}
				}
			}
		}
		cout << endl;
	}
}
void logic()
{
	int prevx = tailx[0];
	int prevy = taily[0];
	int prev2x, prev2y;
	tailx[0] = x;
	taily[0] = y;
	for (int i = 1; i < couyt; i++)
	{
		prev2x = tailx[i];
		prev2y = taily[i];
		tailx[i] = prevx;
		taily[i] = prevy;
		prevx = prev2x;
		prevy = prev2y;
	}
	switch (flag)
	{
	case 1:
	{
		x--;
		break;
	}
	case 2:
	{
		y--;
		break;
	}
	case 3:
	{
		x++;
		break;
	}
	case 4:
	{
		y++;
		break;
	}
	default:
	{
		break;
	}
	}
	if (x == foodx && y == foody)
	{
	label3:
		foodx = rand() % 40;
		if (foodx == 0)
		{
			goto label3;
		}
	label4:
		foody = rand() % 40;
		if (foody == 0)
		{
			goto label4;
		}
		score += 10;
		couyt++;
	}
}
int main()
{
	setup();
	while (!gameover)
	{
		board();
		input();
		logic();
		for (int i = 0; i < 10000; i++)
		{
			for (int j = 0; j < 10000; j++)
			{
			}
		}
	}

	return 0;
}