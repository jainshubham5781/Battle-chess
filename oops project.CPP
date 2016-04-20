#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<malloc.h>
#include<string.h>
void grid();
int c2;

class piececlass
{
	public:
		int x,y,player;
		piececlass(int xtemp,int ytemp,int ptemp)
		{
			x=xtemp;
			y=ytemp;
			player=ptemp;
		}
		void location(int xtemp,int ytemp)
		{
			x=xtemp;
			y=ytemp;
		}
		void move();
		void shoot();
		int check(int x1,int y1)
		{
			if(x==x1&&y==y1)
				return 1;
			else
				return 0;
		}

		virtual void display()=0;
		void put(int x1,int y1)
		{
			x=x1;y=y1;
		}
};
class kingclass:public piececlass
{
	public:
		kingclass(int xtemp,int ytemp,int ptemp):piececlass(xtemp,ytemp,ptemp)
		{

		}
		void display()
		{
			if(player==1)
			{
				//int x=100+(8*25),y=50+(14*25);
				setcolor(BLUE);
				setfillstyle(1,BLUE);
				circle(x,y,17);
				floodfill(x+1,y+1,BLUE);
				setcolor(RED);
				setfillstyle(1,RED);
				line(x-14,y+8,x+14,y+8);
				line(x-14,y+8,x-11,y-8);
				line(x-11,y-8,x-6,y+2);
				line(x-6,y+2,x,y-10);
				line(x,y-10,x+6,y+1);
				line(x+6,y+1,x+11,y-8);
				line(x+11,y-8,x+14,y+8);
				floodfill(x-12,y+6,RED);
			}
			else
			{
				//int x=100+(6*25),y=50;
				setcolor(RED);
				setfillstyle(1,RED);
				circle(x,y,17);
				floodfill(x+1,y+1,RED);
				setcolor(BLUE);
				setfillstyle(1,BLUE);
				line(x-14,y+8,x+14,y+8);
				line(x-14,y+8,x-11,y-8);
				line(x-11,y-8,x-6,y+2);
				line(x-6,y+2,x,y-10);
				line(x,y-10,x+6,y+1);
				line(x+6,y+1,x+11,y-8);
				line(x+11,y-8,x+14,y+8);
				floodfill(x-12,y+6,BLUE);
			}
		}
};
class queenclass:public piececlass
{
	public:
		queenclass(int xtemp,int ytemp,int ptemp):piececlass(xtemp,ytemp,ptemp)
		{

		}
		void display()
		{
			if(player==1)
			{
				//int x=100+(6*25),y=50+(14*25);
				setcolor(BLUE);
				setfillstyle(1,BLUE);
				circle(x,y,17);
				floodfill(x+1,y+1,BLUE);
				setcolor(RED);
				settextstyle(1,0,2);
				outtextxy(x-6,y-11,"Q");
				setcolor(WHITE);
				setbkcolor(BLACK);
			}
			else
			{
				//int x=100+(8*25),y=50;
				setcolor(RED);
				setfillstyle(1,RED);
				circle(x,y,17);
				floodfill(x+1,y+1,RED);
				setcolor(BLUE);
				settextstyle(1,0,2);
				outtextxy(x-6,y-11,"Q");
			}
		}
};
class pawnclass:public piececlass
{
	public:
		pawnclass(int xtemp,int ytemp,int ptemp):piececlass(xtemp,ytemp,ptemp)
		{

		}
		void display()
		{
			if(player==1)
			{
				//int x=100,y=50+(12*25);
				setcolor(BLUE);
				setfillstyle(1,BLUE);
				circle(x,y,17);
				floodfill(x+1,y+1,BLUE);
				setcolor(RED);
				settextstyle(1,0,2);
				outtextxy(x-6,y-11,"P");
			}
			else
			{
				//int x=100,y=50+(2*25);
				setcolor(RED);
				setfillstyle(1,RED);
				circle(x,y,17);
				floodfill(x+1,y+1,RED);
				setcolor(BLUE);
				settextstyle(1,0,2);
				outtextxy(x-6,y-11,"P");
			}
		}
};
class bishopclass:public piececlass
{
	public:
		bishopclass(int xtemp,int ytemp,int ptemp):piececlass(xtemp,ytemp,ptemp)
		{

		}
		void display()
		{
			if(player==1)
			{
				//int x=100+(4*25),y=50+(14*25);
				setcolor(BLUE);
				setfillstyle(1,BLUE);
				circle(x,y,17);
				floodfill(x+1,y+1,BLUE);
				setcolor(RED);
				settextstyle(1,0,2);
				outtextxy(x-6,y-11,"B");
			}
			else
			{
				//int x=100+(4*25),y=50;
				setcolor(RED);
				setfillstyle(1,RED);
				circle(x,y,17);
				floodfill(x+1,y+1,RED);
				setcolor(BLUE);
				settextstyle(1,0,2);
				outtextxy(x-6,y-11,"B");
			}
		}
};
class rookclass:public piececlass
{
	public:
		rookclass(int xtemp,int ytemp,int ptemp):piececlass(xtemp,ytemp,ptemp)
		{

		}
		void display()
		{
			if(player==1)
			{
				//int x=100,y=50+(14*25);
				setcolor(BLUE);
				setfillstyle(1,BLUE);
				circle(x,y,17);
				floodfill(x+1,y+1,BLUE);
				setcolor(RED);
				settextstyle(1,0,2);
				outtextxy(x-6,y-11,"R");
			}
			else
			{
				//int x=100,y=50;
				setcolor(RED);
				setfillstyle(1,RED);
				circle(x,y,17);
				floodfill(x+1,y+1,RED);
				setcolor(BLUE);
				settextstyle(1,0,2);
				outtextxy(x-6,y-11,"R");
			}
		}
};
class knightclass:public piececlass
{
	public:
		knightclass(int xtemp,int ytemp,int ptemp):piececlass(xtemp,ytemp,ptemp)
		{

		}
		void display()
		{
			if(player==1)
			{
				//int x=100+(2*25),y=50+(14*25);
				setcolor(BLUE);
				setfillstyle(1,BLUE);
				circle(x,y,17);
				floodfill(x+1,y+1,BLUE);
				setcolor(RED);
				settextstyle(1,0,2);
				outtextxy(x-6,y-11,"K");
			}
			else
			{
				//int x=100+(2*25),y=50;
				setcolor(RED);
				setfillstyle(1,RED);
				circle(x,y,17);
				floodfill(x+1,y+1,RED);
				setcolor(BLUE);
				settextstyle(1,0,2);
				outtextxy(x-6,y-11,"K");
			}
		}
};
class playerclass
{
	public:
		char name[10];
		/*pawnclass *pawn[8];
		rookclass *rook[2];
		bishopclass *bishop[2];
		knightclass *knight[2];
		queenclass *queen;
		kingclass *king;*/
		piececlass *piece[16];
		playerclass(char nametemp[],int ptemp);
		void turn();
		void display();
		void move(char ch,playerclass &play);
};
playerclass::playerclass(char nametemp[],int ptemp)
	{
			strcpy(name,nametemp);
			if(ptemp==2)		//ptemp=2 for red(black)
			{
				for(int i=8;i<16;i++)
					piece[i]=new pawnclass(100+(50*(i-8)),100,2);
				for(i=0;i<8;i++)
				{
					if(i==0||i==7)
					piece[i]=new rookclass(100+(50*i),50,2);
					if(i==2||i==5)
					piece[i]=new bishopclass(100+(50*i),50,2);
					if(i==1||i==6)
					piece[i]=new knightclass(100+(50*i),50,2);
					if(i==3)
					piece[i]=new queenclass(250,50,2);
					if(i==4)
					piece[i]=new kingclass(300,50,2);
				}
			}
			else
			{
				for(int i=8;i<16;i++)
				piece[i]=new pawnclass(100+(50*(i-8)),100+(5*50),1);
				for(i=0;i<8;i++)
				{
					if(i==0||i==7)
					piece[i]=new rookclass(100+(50*i),50+(7*50),1);
					if(i==2||i==5)
					piece[i]=new bishopclass(100+(50*i),50+(7*50),1);
					if(i==1||i==6)
					piece[i]=new knightclass(100+(50*i),50+(7*50),1);
					if(i==3)
					piece[i]=new queenclass(250,50+(7*50),1);
					if(i==4)
					piece[i]=new kingclass(300,50+(7*50),1);

				}
			}
}

void playerclass::display()
{
	for(int i=0;i<16;i++)
		piece[i]->display();
}

void playerclass::move(char ch,playerclass &play)
 {
	static int x1=100,y1=50,i;
	int z=0,c1=0;
	if(ch=='w'||ch=='W')
	{
		cleardevice();
		grid();
		display();
		play.display();
		y1=y1-(2*25);
		setcolor(3);
		setlinestyle(0,0,3);
		rectangle(x1-25,y1-25,x1+25,y1+25);
		putpixel(x1,y1,WHITE);
	}
	if(ch=='d'||ch=='D')
	{      	cleardevice();
		grid();
		display();
		play.display();
		x1=x1+(2*25);
		setcolor(3);
		setlinestyle(0,0,3);
		rectangle(x1-25,y1-25,x1+25,y1+25);
		putpixel(x1,y1,WHITE);
	 }
	if(ch=='a'||ch=='A')
	{
		cleardevice();
		grid();
		play.display();
		display();
		x1=x1-(2*25);
		setcolor(3);
		setlinestyle(0,0,3);
		rectangle(x1-25,y1-25,x1+25,y1+25);
		putpixel(x1,y1,WHITE);
	}
	if(ch=='s'||ch=='S')
	{
		cleardevice();
		grid();
		display();
		play.display();
		y1=y1+(2*25);
		setcolor(3);
		setlinestyle(0,0,3);
		rectangle(x1-25,y1-25,x1+25,y1+25);
		putpixel(x1,y1,WHITE);
	}
	setcolor(WHITE);
	ch=getche();
	if(ch=='p'||ch=='P')
	{
		for(i=0;i<16;i++)
		{
			z=piece[i]->check(x1,y1);
			if(z==1)
				break;
		}

		if(z==0)
			cout<<"NO piece is here";
		c2=z;
		ch=getche();
		move(ch,play);


	}
	else if(ch=='l'||ch=='L')
	{
		if(c2==1)
		{
			for(int j=0;j<16;j++)
			{
				c1=piece[j]->check(x1,y1);
				if(c1==1)
					break;
			}
			if(c1==0)
			{
				piece[i]->put(x1,y1);
				cleardevice();
				grid();
				play.display();
				display();
			}

			else{
				cout<<"already exist";
				ch=getche();
				move(ch,play);

			}
		}
		else{
			ch=getche();
			move(ch,play);
		}


	}
	else
		move(ch,play);


}
void turn(playerclass p1,playerclass p2);


void main()
{
	int gdriver=0,gmode,a,c;
	int x=100,y=50;
	initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
	cleardevice();
	grid();
	playerclass p1("Sanchit",1);
	playerclass p2("Shubhu",2);
	p1.display();
	p2.display();
	setcolor(3);
	setlinestyle(0,0,3);
	rectangle(x-25,y-25,x+25,y+25);
	turn(p1,p2);
	getch();
	clrscr();

}


void grid()
{
	int i=0,j=0,k=0,m=100;
	cleardevice();
	setbkcolor(BLACK);
	setcolor(WHITE);
	setfillstyle(1,WHITE);
	setlinestyle(0,0,1);

	for(i=100;i<=450;i+=50)
	{
		k=0; m++;
		for(j=50;j<=400;j+=50)
		{
			k++;
			rectangle(i-23,j-23,i+23,j+23);
			if(k%2!=0&&m%2!=0)
			     floodfill(i+2,j+2,WHITE);
			if(k%2==0&&m%2==0)
			   floodfill(i+2,j+2,WHITE);
		}

	}

}


void turn(playerclass p1,playerclass p2)
{
	char n,ch;
	int k=1;
	 ch=getche();
	while(ch!='n')
	{
	     if(k%2==0)
	     {	c2=0;
		p1.move(ch,p2);
	     }
	     else {
		c2=0;
		p2.move(ch,p1);
	     }
		k++;
	      ch=getche();


	}
}
