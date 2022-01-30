//functions used are
//rand() :- to generate random value
//kbhit() :- keyboard hit function which returns true when non zero key is clicked
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


int width=60,height=20,gameover,x,y,fruitX,fruitY,score,flag=0,tailX[100],tailY[100],counttail=0;


void setup()
{
gameover=0;
x=width/2;
y=height/2;

label1:
fruitX=rand()%60;
if(fruitX==0)
	goto label1;

label2:
fruitY=rand()%20;
if(fruitY==0)
	goto label2;

score=0;
}


void draw()
{
	int i,j,k,ch;
	system("cls");
	for(i=0;i<width;i++)
	{
		printf("*");
	}
	printf("\n");
	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{
			if(j==0||j==width-1)
				printf("*");
			else
			{
				if(i==y && j==x )
					printf("O");
				else if(i==fruitY && j==fruitX)// fruitX =rand()%(width value),so friutX is assigned to j.because j is compared with width value in inner for loop.
					printf("F");
				else
				{
					ch=0;
					for(k=0;k<counttail;k++)
					{
						if(i==tailY[k] && j==tailX[k])
						{
							printf("o");
							ch=1;
						}

					}
					if(ch==0)
						printf(" ");

				}
			}
		}
	printf("\n");
	}

	for(i=0;i<width;i++)
	{
		printf("*");
	}
	printf("\n");
	printf("SCORE : %d\n",score);
}

void input()
{
	int m,n;
	 if(kbhit())
	{
		switch(getch())
		{
		case 'a':	//left going - key
			flag=1;
			break;
		case 's':	//right going - key
			flag=2;
			break;
		case 'w':	//top moving - key
			flag=3;
			break;
		case 'z':	//down moving - key
			flag=4;
			break;
		case 'x':	//exit from the game
			gameover=1;
			printf("you are exit from the game");
			for(m=0;m<100;m++)
			{
			for(n=0;n<5000;n++) {}
			}
			break;
		default:
			printf("enter correct key");
			break;
		}
	}
}

void makelogic()
{
	int i,m,n,prev2X,prev2Y,prevX,prevY;
	tailX[0]=x;
	tailY[0]=y;
	prevX=tailX[0];
	prevY=tailY[0];

	for(i=1;i<counttail;i++)
	{
		prev2X=tailX[i];
		prev2Y=tailY[i];
		tailX[i]=prevX;
		tailY[i]=prevY;
		prevX=prev2X;
		prevY=prev2Y;

	}



	switch(flag)
	{
	case 1:
		x--;
		break;
	case 2:
		x++;
		break;
	case 3:
		y--;
		break;
	case 4:
		y++;
		break;
	default:
		break;
	}
	if(x<0||x>width||y<0||y>height)
	{
		gameover=1;
		printf("GAME OVER");
		for(m=0;m<100;m++)
		{
		for(n=0;n<1000;n++) {}
		}
	}
	for(i=0;i<counttail;i++)
	{
		if(x==tailX[i] && y==tailY[i])
		{
			gameover=1;
			printf("GAME OVER");
			for(m=0;m<100;m++)
			{
			for(n=0;n<1000;n++) {}
			}
		}
	}
	if(x==fruitX && y==fruitY)
	{
	label3:
	fruitX=rand()%60;
	if(fruitX==0)
		goto label3;

	label4:
	fruitY=rand()%20;
	if(fruitY==0)
		goto label4;
	score+=10;
	counttail++;
	}

}

void main()
{
	int m,n;
	char c;
	label5:
		setup();
		while(gameover!=1)
		{
		draw();
		input();
		makelogic();

		for(m=0;m<100;m++)
			{
			for(n=0;n<1000;n++) {}
			}
		}
		printf("\npress Y to continue the game:");
		scanf("%c",&c);
		if(c=='y' || c=='Y')
		{
			gameover=0;
			goto label5;
		}
}
