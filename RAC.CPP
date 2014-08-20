#include<dos.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<iostream.h>
  int y=0,cp=0,flag=0;
 void fixed()         //2 fixed lines on either side
 {
    line(19,0,19,479);
line(600,0,600,479);
line(19,479,19,0);
line(600,479,600,0);
 }

 void li()          //2 dotted runnimg lines
 {
  for(int i=0,k=1;i<20;i++,k++,i++,k++)
  {
 line(219,y+i*25,219,y+k*25);
  line(419,y+i*25,419,y+k*25);
 if(y>=45)
 y=1;
 }
 }

 void car(int t,int cp)
 {
 if(t==1)                   //midle position
 {
 rectangle(259,cp,379,cp+110);
 }
 else
 if(t==0)                   //left
 {
 rectangle(59,cp,179,cp+110);
 }
 else
 if(t==2)                   //right
 {
 rectangle(459,cp,579,cp+110);
  }
 }

 void obs(int t)
 {
 car(t,cp);
 cp=cp+3;
 }

 int crash(int x,int t)
 {
 if(t==x && cp>=249)
 return 1;
 else
 return 0;
 }


void main()
{
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "C://TC//BGI");
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }
   setcolor(getmaxcolor());

 //  setviewport(21,20,602,479,0);
	int count=0,t=1,co=0,x;
	char ch;
 //---------------------------------------------------------------
       while(count<8000)
     {
      //	outtextxy(0,0,"score"+count);
       fixed();
       li();
       car(t,359);
 //-----------------------------------------------------
      ch=getch();           //detecting arrow keys
       if(ch==75)
       {
	 if(t==1)
	 t=0;
	 else
	 t=1;
       }
       else
       if(ch==77)
       {
	 if(t==1)
	 t=2;
	 else
	 t=1;
       }
 //----------------------------------------------------
       if(co>250)            //obstacle call
       {
       x=rand()%3;
       cp=0;
       obs(x);
       flag=1;
       co=0;
       }
       else
       co++;

     //  if(co>485 && flag==1);
     //  flag=0;
       if(flag==1)
       obs(x);

 //----------------------------------------------------------------

      if(crash(x,t))
      break;
      // clearviewport();
      delay(20);
      cleardevice();
       count++;
       y++;
      }
      delay(60);
       cout<<"score="+count;

   getch();
   closegraph();
}