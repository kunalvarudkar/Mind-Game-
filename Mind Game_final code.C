#include<stdio.h>
#include<graphics.h>
#include<conio.h>
    /*usable function*/
void mn(); /*      */
void layout();
void logical();
void lowerbx();
void indicator();
void cpuind();
void tempcal();

 int c1,c2,c3,c4;
 int w1,w2,w3,w4;
 int s=0;
 int g1,g2,g3,g4;
 int rn[4];
 int ch,cc[4];
 int val1,val2,val3,val4;
 int i,j,a,b;
 int nc1,nc2,nc3,nc4;//for those colours which are not same as guessing colour

	int main()
		{

			int ch;
			int gd=DETECT,gm;
			initgraph(&gd,&gm,"");
			clrscr();
			settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
			outtextxy(300,20,"MINDGAME!!!");

	printf("\nPress 1 : Play as Guesser\nPress 2 : Play as Maker\n Enter Your Choice:");
	scanf("%d",&ch);
		if(ch==1)  //for playing as player
		   {
			clrscr();
			layout();
			logical();
		   }

		else if(ch==2)  //CPU play
		   {
			clrscr();
			gotoxy(30,10);
			layout();
			gotoxy(40,10);

		   printf("Enter the color code to fill=");
		     for(i=0;i<4;i++)
			{
			   gotoxy(50,11);
			   scanf("%d",&cc[i]);
			}
    //for filling the lower boxes as player
		  setfillstyle(SOLID_FILL,cc[0]);
		  floodfill(45,420,WHITE);

		  setfillstyle(SOLID_FILL,cc[1]);
		  floodfill(75,420,WHITE);

		  setfillstyle(SOLID_FILL,cc[2]);

		  floodfill(100,420,WHITE);
		  setfillstyle(SOLID_FILL,cc[3]);
		  floodfill(140,420,WHITE);
    //layout of upper boxes
		  rectangle(35,35,55,55);
		  rectangle(65,35,85,55);
		  rectangle(95,35,115,55);
		  rectangle(125,35,145,55);
   //layout of lower boxes
		  rectangle(155,50,165,40);
		  rectangle(170,50,180,40);
		  rectangle(185,50,195,40);
		  rectangle(200,50,210,40);
   //AT initial level randim selection of color for CPU at upper boxes
		 setfillstyle(SOLID_FILL,0);
		 floodfill(45,45,WHITE);

		 setfillstyle(SOLID_FILL,4);
		 floodfill(75,45,WHITE);

		 setfillstyle(SOLID_FILL,9);
		 floodfill(105,45,WHITE);

		 setfillstyle(SOLID_FILL,12);
		 floodfill(135,45,WHITE);
     //function call for cpu indicator!!
		 cpuind();
     //condition if the all indicator boxes becomes RED!!!
		if((getpixel(160,45)==4)&&(getpixel(190,45)==4)&&(getpixel(205,45)==4)&&(getpixel(175,45)==4))
			 {
				 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
				 outtextxy(350,30,"Cngrats!!");
				 outtextxy(370,60,"C.P.U Won");
				 exit(0);
			 }


		  tempcal();
		  for(a=30,b=0;a<=360,b<=330;a=a+30,b=b+30)
			{
			   if(a>=360)
			     {

			       settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
			       outtextxy(350,30,"Ooops");
			       outtextxy(370,60,"C.P.U Lost..!!");
			       getch();
			       exit(0);
			     }

   //to generate the lower main upper boxes
		rectangle(35,35+a,55,55+a);
		rectangle(65,35+a,85,55+a);
		rectangle(95,35+a,115,55+a);
		rectangle(125,35+a,145,55+a);

   //to generate the Indicaton Boxes!!!
		rectangle(155,50+a,165,40+a);
		rectangle(170,50+a,180,40+a);
		rectangle(185,50+a,195,40+a);
		rectangle(200,50+a,210,40+a);
    //to fill second boxes
		cpuind();
   //to swap colour which is white in order 1st160 box 2nd175 3rd190 4th205
		if(getpixel(160,45+b)==WHITE)
		  {
		   if(val1==1)
		      {
			setfillstyle(SOLID_FILL, getpixel(40,40+b));
			floodfill(75,40+a,WHITE);
		      }
		   else if(val1==2)
		      {
			setfillstyle(SOLID_FILL, getpixel(40,40+b));
			floodfill(105,40+a,WHITE);
		      }
		   else if(val1==3)
		      {
			setfillstyle(SOLID_FILL, getpixel(40,40+b));
			floodfill(135,40+a,WHITE);
		      }
		   else
		     {
		       continue;
		     }
	       }
	    if(getpixel(175,45+b)==WHITE)   //second white box
	    {
		  if(val4==1)
		    {
		      setfillstyle(SOLID_FILL, getpixel(135,40+b));
		      floodfill(40,40+a,WHITE);
		    }
		  else if(val4==2)
		    {
		      setfillstyle(SOLID_FILL, getpixel(135,40+b));
		      floodfill(75,40+a,WHITE);
		    }
		  else if(val4==3)
		    {
		      setfillstyle(SOLID_FILL,getpixel(135,40+b));
		      floodfill(105,40+a,WHITE);
		    }
		  else
		    {
		      continue;
		    }
	       }
	      if(getpixel(190,45+b)==WHITE) //third white
		   {
		     if(val2==1)
		       {
			 setfillstyle(SOLID_FILL, getpixel(75,40+b));
			 floodfill(40,40+a,WHITE);
		       }
		     else if(val2==2)
		       {
			 setfillstyle(SOLID_FILL, getpixel(75,40+b));
			 floodfill(105,40+a,WHITE);

		       }
		     else if(val2==3)
		       {
			 setfillstyle(SOLID_FILL, getpixel(75,40+b));
			 floodfill(135,40+a,WHITE);
		       }
		     else
		       {
			 continue;
		       }

		   }
		if(getpixel(205,45+b)==WHITE)          //forth white box
		      {
			 if(val3==1)
			     {
				setfillstyle(SOLID_FILL, getpixel(105,40+b));
				floodfill(40,40+a,WHITE);
			     }
			 else if(val3==2)
			     {
				setfillstyle(SOLID_FILL, getpixel(105,40+b));
				floodfill(75,40+a,WHITE);
			     }
			 else if(val3==3)
			     {
				setfillstyle(SOLID_FILL, getpixel(105,40+b));
				floodfill(135,40+a,WHITE);
			     }
			 else
			     {
			       continue;
			     }
		}
		  cpuind();
		   if(getpixel(160,45+b)==4)
		      {
			if((c1==0)||(c1==1)||(c1==2)||(c1==3)||(c1==4)||(c1==5)||(c1==6)||(c1==7)||(c1==8)||(c1==9)||(c1==10)||(c1==11)||(c1==12)||(c1==13)||(c1==14)||(c1==15))
			  {
				setfillstyle(SOLID_FILL,c1);
				floodfill(40,40+a,WHITE);
   // cpuind();
			 }
		    }

		   if(getpixel(190,45+b)==4)
		      {
			if((c2==0)||(c2==1)||(c2==2)||(c2==3)||(c2==4)||(c2==5)||(c2==6)||(c2==7)||(c2==8)||(c2==9)||(c2==10)||(c2==11)||(c2==12)||(c2==13)||(c2==14)||(c2==15))
			    {
			       setfillstyle(SOLID_FILL,c2);
			       floodfill(75,40+a,WHITE);
			    }
		      }
		   if(getpixel(205,45+b)==4)
		      {
			if((c3==0)||(c3==1)||(c3==2)||(c3==3)||(c3==4)||(c3==5)||(c3==6)||(c3==7)||(c3==8)||(c3==9)||(c3==10)||(c3==11)||(c3==12)||(c3==13)||(c3==14)||(c3==15))
			    {
			       setfillstyle(SOLID_FILL,c3);
			       floodfill(105,40+a,WHITE);
			    }
		      }
		   if(getpixel(175,45+b)==4)
		      {
			if((c4==0)||(c4==1)||(c4==2)||(c4==3)||(c4==4)||(c4==5)||(c4==6)||(c4==7)||(c4==8)||(c4==9)||(c4==10)||(c4==11)||(c4==12)||(c4==13)||(c4==14)||(c4==15))
			    {
			       setfillstyle(SOLID_FILL,c4);
			       floodfill(135,40+a,WHITE);
			    }
		      }
//calling cpuindication for blinking indication boxes.
		 cpuind();
 //code for generating next color according  to color's no
		if(getpixel(160,45+a)!=4)
		    {         //for 1 ind
		       c1=(nc1+1)%16;
		       setfillstyle(SOLID_FILL,c1);
		       floodfill(45,45+a,WHITE);
		       nc1=c1;
		    }
		 if(getpixel(190,45+a)!=4)
		    {                    //for 3rd ind
		       c2=((nc2+1)%16);
		       setfillstyle(SOLID_FILL,c2);
		       floodfill(75,45+a,WHITE);
		       nc2=c2;
		    }
		 if(getpixel(205,45+a)!=4)
		    {                 //forth ind
		       c3=((nc3+1)%16);
		       setfillstyle(SOLID_FILL,c3);
		       floodfill(105,45+a,WHITE);
		       nc3=c3;
		    }
		 if(getpixel(175,45+a)!=4)
		    {                 //second ind
		       c4=((nc4+1)%16);
		       setfillstyle(SOLID_FILL,c4);
		       floodfill(135,45+a,WHITE);
		       nc4=c4;
		    }

		cpuind();
	      //code for storing pixel in temp variable for white ind calculation
		if(getpixel(160,45+a)==4)
		     {      //for 1 ind
			c1=getpixel(40,40+a);
		     }
		if(getpixel(175,45+a)==4)
		     {     //3rd
			c2=getpixel(75,40+a);
		     }
		if(getpixel(190,45+a)==4)
		     {     //4th
			c3=getpixel(105,40+a);
		     }

		if(getpixel(205,45+a)==4)
		     {     //2nd
			c4=getpixel(135,40+a);
		     }
	      }
	 }//else if
		else
		   {
			printf("\nWrong choice");
		   }
		getch();
		return 0;
      }

/************************FUCTION DEFINATION *****************************/
   void tempcal()
       {
	  if(getpixel(160,45)==4)
	     {
		c1=getpixel(40,40);
	     }
	  else
	     {
		nc1=getpixel(40,40);
	     }
	  if(getpixel(190,45)==4)
	     {        //3rd
		c2=getpixel(75,40);
	     }
	  else
	     {
		nc2=getpixel(75,40);
	     }
	  if(getpixel(205,45)==4)
	     {       //4th
		c3=getpixel(105,40);
	     }
	  else
	     {
		nc3=getpixel(105,40);
	     }
	  if(getpixel(175,45)==4)
	     {      //2nd
		c4=getpixel(135,40);
	     }
	  else
	    {
		nc4=getpixel(135,40);
	    }
   /*****************for white indicator *************************/

	  if(getpixel(160,45)==WHITE)
	    {                      //for 1 ind
		w1=getpixel(40,40);
	    }
	  if(getpixel(190,45)==WHITE)
	    {                      //3rd
		w2=getpixel(75,40);
	    }
	  if(getpixel(205,45)==WHITE)
	    {                      //4yh
	       w3=getpixel(105,40);
	    }
	  if(getpixel(175,45)==WHITE)
	    {                      //2nd
	       w4=getpixel(135,40);
	    }

	}

   void logical()
       {             /*******************random****************/
		for(i=0;i<4;i++)
		 {
		   rn[i]=rand()%14;
		 }
   /********************************************************/
		for(a=0;a<=330;a=a+30)
		   {
		      //main upper boxes
			rectangle(35,35+a,55,55+a);
			rectangle(65,35+a,85,55+a);
			rectangle(95,35+a,115,55+a);
			rectangle(125,35+a,145,55+a);
/**********************Indicaton Boxes******************************/
			rectangle(155,50+a,165,40+a);
			rectangle(170,50+a,180,40+a);
			rectangle(185,50+a,195,40+a);
			rectangle(200,50+a,210,40+a);

    i=1;
			   for(i=1;i<5;i++)
				{
				  if(i==1)
				    {
				       ch=0;
				       gotoxy(50,10);
				       printf("Enter:");
				       scanf("%d",&ch);

				       switch(ch)
					   {
					     case 0:
						setfillstyle(SOLID_FILL,0);
						floodfill(45,45+a,WHITE);
					     break;

					     case 1:
						setfillstyle(SOLID_FILL,1);
						floodfill(45,45+a,WHITE);
					     break;

					     case 2:
						setfillstyle(SOLID_FILL,2);
						floodfill(45,45+a,WHITE);
					     break;

					     case 3:
						setfillstyle(SOLID_FILL,3);
						floodfill(45,45+a,WHITE);
					     break;

					     case 4:
						setfillstyle(SOLID_FILL,4);
						floodfill(45,45+a,WHITE);
					     break;

					     case 5:
						setfillstyle(SOLID_FILL,5);
						floodfill(45,45+a,WHITE);
					     break;

					     case 6:
						setfillstyle(SOLID_FILL,6);
						floodfill(45,45+a,WHITE);
					     break;

					     case 7:
						setfillstyle(SOLID_FILL,7);
						floodfill(45,45+a,WHITE);
					     break;

					     case 8:
						setfillstyle(SOLID_FILL,8);
						floodfill(45,45+a,WHITE);
					     break;

					     case 9:
						setfillstyle(SOLID_FILL,9);
						floodfill(45,45+a,WHITE);
					     break;

					     case 10:
						setfillstyle(SOLID_FILL,10);
						floodfill(45,45+a,WHITE);
					     break;

					     case 11:
						setfillstyle(SOLID_FILL,11);
						floodfill(45,45+a,WHITE);
					     break;

					     case 12:
						setfillstyle(SOLID_FILL,12);
						floodfill(45,45+a,WHITE);
					     break;

					     case 13:
						setfillstyle(SOLID_FILL,13);
						floodfill(45,45+a,WHITE);
					     break;

					     case 14:
						setfillstyle(SOLID_FILL,14);
						floodfill(45,45+a,WHITE);
					     break;

					     case 15:
						setfillstyle(SOLID_FILL,15);
						floodfill(45,45+a,WHITE);
					     break;


		      }
		 }
		else if(i==2)
		   {
		     ch=0;
		     gotoxy(50,10);
		     printf("Enter:");
		     scanf("%d",&ch);

			switch(ch)
			    {
					     case 0:
						setfillstyle(SOLID_FILL,0);
						floodfill(75,45+a,WHITE);
					     break;

					     case 1:
						setfillstyle(SOLID_FILL,1);
						floodfill(75,45+a,WHITE);
					     break;

					     case 2:
						setfillstyle(SOLID_FILL,2);
						floodfill(75,45+a,WHITE);
					     break;

					     case 3:
						setfillstyle(SOLID_FILL,3);
						floodfill(75,45+a,WHITE);
					     break;

					     case 4:
						setfillstyle(SOLID_FILL,4);
						floodfill(75,45+a,WHITE);

						//fillpoly(5,mb2);
					     break;

					     case 5:
						setfillstyle(SOLID_FILL,5);
						floodfill(75,45+a,WHITE);
						//fillpoly(5,mb2);
					     break;

					     case 6:
						setfillstyle(SOLID_FILL,6);
						floodfill(75,45+a,WHITE);
						//fillpoly(5,mb2);
					     break;

					     case 7:
						setfillstyle(SOLID_FILL,7);
						floodfill(75,45+a,WHITE);
						//	fillpoly(5,mb1);
					     break;

					     case 8:
						setfillstyle(SOLID_FILL,8);
						floodfill(75,45+a,WHITE);
						//fillpoly(5,mb1);
					     break;

					     case 9:
						setfillstyle(SOLID_FILL,9);
						floodfill(75,45+a,WHITE);
						//fillpoly(5,mb1);
					     break;

					     case 10:
						setfillstyle(SOLID_FILL,10);
						floodfill(75,45+a,WHITE);
						//fillpoly(5,mb1);
					     break;

					     case 11:
						setfillstyle(SOLID_FILL,11);
						floodfill(75,45+a,WHITE);
						//fillpoly(5,mb1);
	break;

	case 12:
	setfillstyle(SOLID_FILL,12);
	floodfill(75,45+a,WHITE);
	//fillpoly(5,mb1);
	break;

	case 13:
	setfillstyle(SOLID_FILL,13);
	floodfill(75,45+a,WHITE);
	      //	fillpoly(5,mb1);
	break;

	case 14:
	setfillstyle(SOLID_FILL,14);
	floodfill(75,45+a,WHITE);
	break;

	case 15:
	setfillstyle(SOLID_FILL,15);
	floodfill(75,45+a,WHITE);
	break;

}

}
else if(i==3)
{ch=0;


gotoxy(50,10);
printf("Enter:");
scanf("%d",&ch);

switch(ch)
{
	case 0:
	setfillstyle(SOLID_FILL,0);
	floodfill(105,45+a,WHITE);
	      //	fillpoly(5,mb1);
	break;

	case 1:
	setfillstyle(SOLID_FILL,1);
	floodfill(105,45+a,WHITE);
	break;

	case 2:
	setfillstyle(SOLID_FILL,2);
	floodfill(105,45+a,WHITE);
	break;

	case 3:
	setfillstyle(SOLID_FILL,3);
	floodfill(105,45+a,WHITE);
	break;

	case 4:
	setfillstyle(SOLID_FILL,4);
	floodfill(105,45+a,WHITE);
	break;

	case 5:
	setfillstyle(SOLID_FILL,5);
	floodfill(105,45+a,WHITE);
	break;

	case 6:
	setfillstyle(SOLID_FILL,6);
	floodfill(105,45+a,WHITE);
	break;

	case 7:
	setfillstyle(SOLID_FILL,7);
	floodfill(105,45+a,WHITE);
	break;

	case 8:
	setfillstyle(SOLID_FILL,8);
	floodfill(105,45+a,WHITE);
	break;

	case 9:
	setfillstyle(SOLID_FILL,9);
	floodfill(105,45+a,WHITE);
	break;

	case 10:
	setfillstyle(SOLID_FILL,10);
	floodfill(105,45+a,WHITE);
	break;

	case 11:
	setfillstyle(SOLID_FILL,11);
	floodfill(105,45+a,WHITE);
	break;

	case 12:
	setfillstyle(SOLID_FILL,12);
	floodfill(105,45+a,WHITE);
	break;

	case 13:
	setfillstyle(SOLID_FILL,13);
	floodfill(105,45+a,WHITE);
	break;

	case 14:
	setfillstyle(SOLID_FILL,14);
	floodfill(105,45+a,WHITE);
	break;

	case 15:
	setfillstyle(SOLID_FILL,15);
	floodfill(105,45+a,WHITE);
	break;




}
}
else {
ch=0;
gotoxy(50,10);
printf("Enter:");
scanf("%d",&ch);

switch(ch)
{
	case 0:
	setfillstyle(SOLID_FILL,0);
	floodfill(135,45+a,WHITE);
	      //	fillpoly(5,mb1);
	break;


case 1:
setfillstyle(SOLID_FILL,1);
floodfill(135,45+a,WHITE);
//fillpoly(5,mb4);
break;
case 2:
setfillstyle(SOLID_FILL,2);
floodfill(135,45+a,WHITE);
//fillpoly(5,mb4);
 break;
   case 3:
	 setfillstyle(SOLID_FILL,3);
floodfill(135,45+a,WHITE);
//fillpoly(5,mb4);
	 break;
   case 4:
	 setfillstyle(SOLID_FILL,4);
floodfill(135,45+a,WHITE);
  //	 fillpoly(5,mb4);
	 break;

   case 5:
	 setfillstyle(SOLID_FILL,5);
	floodfill(135,45+a,WHITE);
	 //fillpoly(5,mb4);
	 break;
   case 6:
	 setfillstyle(SOLID_FILL,6);
	floodfill(135,45+a,WHITE);
	 //fillpoly(5,mb4);
	 break;



	case 7:
	setfillstyle(SOLID_FILL,7);
	floodfill(135,45+a,WHITE);
	      //	fillpoly(5,mb1);
	break;

	case 8:
	setfillstyle(SOLID_FILL,8);
	floodfill(135,45+a,WHITE);
	//fillpoly(5,mb1);
	break;

	case 9:
	setfillstyle(SOLID_FILL,9);
	floodfill(135,45+a,WHITE);
	//fillpoly(5,mb1);
	break;

	case 10:
	setfillstyle(SOLID_FILL,10);
	floodfill(135,45+a,WHITE);
	//fillpoly(5,mb1);
	break;

	case 11:
	setfillstyle(SOLID_FILL,11);
	floodfill(135,45+a,WHITE);
	//fillpoly(5,mb1);
	break;

	case 12:
	setfillstyle(SOLID_FILL,12);
	floodfill(135,45+a,WHITE);
	//fillpoly(5,mb1);
	break;

	case 13:
	setfillstyle(SOLID_FILL,13);
	floodfill(135,45+a,WHITE);
	      //	fillpoly(5,mb1);
	break;

	case 14:
	setfillstyle(SOLID_FILL,14);
	floodfill(135,45+a,WHITE);
	break;

	case 15:
	setfillstyle(SOLID_FILL,15);
	floodfill(135,45+a,WHITE);
	      //	fillpoly(5,mb1);
	break;




	}
	indicator();   //switch
      }  //else
   } // for





   // }//for
     }   //a
}//mn
//}  //j

void lowerbx()
 {
	setfillstyle(SOLID_FILL,rn[0]);// Yellow  14
	rectangle(35,410,55,430);
	floodfill(45,420,WHITE);


	setfillstyle(SOLID_FILL,rn[1]);     //RED    4
	rectangle(65,410,85,430);
	floodfill(75,420,WHITE);                  //random

	setfillstyle(SOLID_FILL,rn[2]); //blue    1  colour
	rectangle(95,410,115,430);
	floodfill(100,420,WHITE);

	setfillstyle(SOLID_FILL,rn[3]);       //cyan3
	rectangle(125,410,145,430);
	floodfill(140,420,WHITE);

 }

void layout()
 {
      lowerbx();
  /*************************************COLOR CODE*********************************/

   settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
   outtextxy(10,10,"WELCOME TO MINDGAME");
   settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   outtextxy(276,65,"0");
   outtextxy(276,85,"1");
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   outtextxy(276,105,"2");
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   outtextxy(276,125,"3");
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   outtextxy(276,145,"4");
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   outtextxy(276,165,"5");
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   outtextxy(276,185,"6");
   // settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
  // outtextxy(276,205,"7");
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   outtextxy(276,225,"8");
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   outtextxy(276,245,"9");
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   outtextxy(276,265,"10");
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   outtextxy(276,285,"11");
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   outtextxy(276,305,"12");
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
     outtextxy(276,325,"13");
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   outtextxy(276,345,"14");
   outtextxy(276,365,"15");


  /*****************lower boxes container *****************************/
      rectangle(30,400,220,450);

 /************************ main box container **********************/
   rectangle(30,30,220,400);

 /****************Right outer Container-Indication***********************/

   rectangle(220,400,300,30);

   /******************* dividing line*************************************/

 line(150,30,150,400);

  /************* color boxes below indication boxes*************************/

   setfillstyle(SOLID_FILL,0);
   rectangle(235,60,270,75);
   floodfill(250,70,WHITE);

   setfillstyle(SOLID_FILL,1);
   rectangle(235,80,270,95);
   floodfill(250,85,WHITE);

    setfillstyle(SOLID_FILL,2);
   rectangle(235,100,270,115);
   floodfill(250,110,WHITE);

   setfillstyle(SOLID_FILL,3);
   rectangle(235,120,270,135);
   floodfill(250,125,WHITE);

    setfillstyle(SOLID_FILL,4);
   rectangle(235,140,270,155);
    floodfill(250,145,WHITE);

    setfillstyle(SOLID_FILL,5);
   rectangle(235,160,270,175);
   floodfill(250,165,WHITE);

    setfillstyle(SOLID_FILL,6);
   rectangle(235,180,270,195);
   floodfill(250,185,WHITE);


    //setfillstyle(SOLID_FILL,7);
  // rectangle(235,200,270,215);
//   floodfill(250,210,WHITE);

    setfillstyle(SOLID_FILL,8);
   rectangle(235,220,270,235);
   floodfill(250,225,WHITE);

   setfillstyle(SOLID_FILL,9);
   rectangle(235,240,270,255);
   floodfill(250,245,WHITE);

    setfillstyle(SOLID_FILL,10);
   rectangle(235,260,270,275);
    floodfill(250,265,WHITE);

    setfillstyle(SOLID_FILL,11);
   rectangle(235,280,270,295);
   floodfill(250,285,WHITE);

    setfillstyle(SOLID_FILL,12);
   rectangle(235,300,270,315);
   floodfill(250,310,WHITE);

   setfillstyle(SOLID_FILL,13);
   rectangle(235,320,270,335);
   floodfill(250,325,WHITE);

    setfillstyle(SOLID_FILL,14);
   rectangle(235,340,270,355);
   floodfill(250,345,WHITE);

   setfillstyle(SOLID_FILL,15);
   rectangle(235,360,270,375);
   floodfill(250,370,WHITE);


  }

   void indicator()
	{
	//****************WHITE BOX INDICATOR*********************
   //   if((getpixel(40,40)==getpixel(75,415))||(getpixel(40,40)==getpixel(100,415))||(getpixel(40,40)==getpixel(140,415)))
     if((getpixel(40,40+a)==rn[1])||(getpixel(40,40+a)==rn[2])||(getpixel(40,40+a)==rn[3]))
     {
      setfillstyle(SOLID_FILL,WHITE);
    floodfill(160,45+a,WHITE);                //1st  40   0 -getpixel(40,415
					      //    75   1  -getpixel(75,415
     }                                        //   100   2  -getpixel(100,415))
					       //  140   3  -getpixel(140,415))
     //	if((getpixel(75,40)==getpixel(40,415))||(getpixel(75,40)==getpixel(100,415))||(getpixel(75,40)==getpixel(140,415)))
	if((getpixel(75,40+a)==rn[0])||(getpixel(75,40+a)==rn[2])||(getpixel(75,40+a)==rn[3]))
     {
      setfillstyle(SOLID_FILL,WHITE);
	floodfill(190,45+a,WHITE);               //3rd

     }
//	if((getpixel(105,40)==getpixel(75,415))||(getpixel(105,40)==getpixel(40,415))||(getpixel(105,40)==getpixel(140,415)))
	if((getpixel(105,40+a)==rn[1])||(getpixel(105,40+a)==rn[0])||(getpixel(105,40+a)==rn[3]))
     {
      setfillstyle(SOLID_FILL,WHITE);
      floodfill(205,45+a,WHITE);                 //4th

     }
//	if((getpixel(135,40)==getpixel(75,415))||(getpixel(135,40)==getpixel(100,415))||(getpixel(135,40)==getpixel(40,415)))
if((getpixel(135,40+a)==rn[1])||(getpixel(135,40+a)==rn[2])||(getpixel(135,40+a)==rn[0]))
     {
      setfillstyle(SOLID_FILL,WHITE);
	   floodfill(175,45+a,WHITE);                //2nd

     }
    //  return 0;
    if(a>=330)
{
     lowerbx();
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
   outtextxy(350,30,"SORRY..");
   outtextxy(370,60,"YOU LOSE..!!");
   getch();
   exit(0);

}



 //**************RED*****************
   g1=getpixel(40,40+a);
/* if(getpixel(40,40+a)*/if(g1==rn[0])//getpixel(40,415))  // color
   {
    setfillstyle(SOLID_FILL,RED);
  floodfill(160,45+a,WHITE);                         //1indicator

    }
     g2=getpixel(75,40+a);
   /*  if(getpixel(75,40+a)*/if(g2==rn[1])//getpixel(75,415))
   {
    setfillstyle(SOLID_FILL,RED);
    floodfill(190,45+a,WHITE);                       //third

    }
     g3=getpixel(105,40+a);
   /*  if(getpixel(105,40+a)*/if(g3==rn[2])//getpixel(100,415))
   {
    setfillstyle(SOLID_FILL,RED);
       floodfill(205,45+a,WHITE);                       //forth

    }
	g4=getpixel(135,40+a);
  /*   if(getpixel(135,40+a)*/if(g4==rn[3])//getpixel(140,415))
   {
    setfillstyle(SOLID_FILL,RED);
    floodfill(175,45+a,WHITE);                       //second

    }
   //use// if((getpixel(40,40+a)==getpixel(40,415))&&(getpixel(135,40+a)==getpixel(140,415))&&(getpixel(105,40+a)==getpixel(100,415))&&(getpixel(75,40+a)==getpixel(75,415)))
     if((getpixel(40,40+a)==rn[0])&&(getpixel(135,40+a)==rn[3])&&(getpixel(105,40+a)==rn[2])&&(getpixel(75,40+a)==rn[1]))
    {
       lowerbx();
       settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
       outtextxy(350,30,"Cngrats !!");
       outtextxy(370,60,"You Won");
	 getch();
   exit(0);

     }
}

 void cpuind()
 {
 //**************RED*****************
  // g1=getpixel(40,40+a);
///* if(getpixel(40,40+a)*/if(g1==rn[0])//getpixel(40,415))  // color
//delay(2000);
   if(getpixel(40,40+a)==getpixel(40,415))
   {
    setfillstyle(SOLID_FILL,RED);
  floodfill(160,45+a,WHITE);
	     //1indicator

    }
   //  g2=getpixel(75,40+a);
 //  /*  if(getpixel(75,40+a)*/if(g2==rn[1])//getpixel(75,415))
  // delay(2000);
   if(getpixel(75,40+a)==getpixel(75,415))
   {
    setfillstyle(SOLID_FILL,RED);
    floodfill(190,45+a,WHITE);                       //third

    }                delay(500);
    // g3=getpixel(105,40+a);
   //*  if(getpixel(105,40+a)*/if(g3==rn[2])//getpixel(100,415))
    if(getpixel(105,40+a)==getpixel(100,415))
   {
    setfillstyle(SOLID_FILL,RED);
       floodfill(205,45+a,WHITE);  //there was no a                     //forth

    }
   // delay(2000);
 //	g4=getpixel(135,40+a);
  //*   if(getpixel(135,40+a)*/if(g4==rn[3])//getpixel(140,415))
    if(getpixel(135,40+a)==getpixel(140,415))
   {
    setfillstyle(SOLID_FILL,RED);
    floodfill(175,45+a,WHITE);                       //second

    }
   // delay(2000);
    if((getpixel(40,40+a)==getpixel(40,415))&&(getpixel(135,40+a)==getpixel(140,415))&&(getpixel(105,40+a)==getpixel(100,415))&&(getpixel(75,40+a)==getpixel(75,415)))
    // if((getpixel(40,40+a)==rn[0])&&(getpixel(135,40+a)==rn[3])&&(getpixel(105,40+a)==rn[2])&&(getpixel(75,40+a)==rn[1]))
    {
     //  lowerbx();
       settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
       outtextxy(350,30,"Congratulation !!");
       outtextxy(370,60,"You Won");
	 getch();
   exit(0);

   }


	//****************WHITE BOX INDICATOR*********************
      delay(400);
      if(getpixel(40,40+a)==getpixel(75,415))
   //    if((getpixel(40,40+a)==rn[1])||(getpixel(40,40+a)==rn[2])||(getpixel(40,40+a)==rn[3]))
     {
      setfillstyle(SOLID_FILL,WHITE);
    floodfill(160,45+a,WHITE);                //1st  40   0 -getpixel(40,415
      val1=1;					      //    75   1  -getpixel(75,415
     }                                        //   100   2  -getpixel(100,415))
//  140   3  -getpixel(140,415))

    if(getpixel(40,40+a)==getpixel(100,415))
       {
      setfillstyle(SOLID_FILL,WHITE);
    floodfill(160,45+a,WHITE);                //1st  40   0 -getpixel(40,415
	val1=2;				      //    75   1  -getpixel(75,415
     }                                        //   100   2  -getpixel(100,415))


     if(getpixel(40,40+a)==getpixel(140,415))
	{
      setfillstyle(SOLID_FILL,WHITE);
    floodfill(160,45+a,WHITE);                //1st  40   0 -getpixel(40,415
       val1=3;					      //    75   1  -getpixel(75,415
     }                                        //   100   2  -getpixel(100,415))




     //	delay(2000);
	if(getpixel(75,40+a)==getpixel(40,415))
     //	if((getpixel(75,40+a)==rn[0])||(getpixel(75,40+a)==rn[2])||(getpixel(75,40+a)==rn[3]))
     {
      setfillstyle(SOLID_FILL,WHITE);
	floodfill(190,45+a,WHITE);               //3rd
	 val2=1;
     }
    // delay(2000);

    if(getpixel(75,40+a)==getpixel(100,415))
       {
      setfillstyle(SOLID_FILL,WHITE);
	floodfill(190,45+a,WHITE);               //3rd
	 val2=2;
     }


    if(getpixel(75,40+a)==getpixel(140,415))
	{
      setfillstyle(SOLID_FILL,WHITE);
	floodfill(190,45+a,WHITE);               //3rd
	 val2=3;
     }

	 if(getpixel(105,40+a)==getpixel(40,415))
     {
      setfillstyle(SOLID_FILL,WHITE);
      floodfill(205,45+a,WHITE);                 //4th
	val3=1;
     }
	if(getpixel(105,40+a)==getpixel(75,415))
//	if((getpixel(105,40+a)==rn[1])||(getpixel(105,40+a)==rn[0])||(getpixel(105,40+a)==rn[3]))
     {
      setfillstyle(SOLID_FILL,WHITE);
      floodfill(205,45+a,WHITE);                 //4th
	   val3=2;
     }

     if(getpixel(105,40+a)==getpixel(140,415))
     {
      setfillstyle(SOLID_FILL,WHITE);
      floodfill(205,45+a,WHITE);                 //4th
       val3=3;
     }


	   if(getpixel(135,40+a)==getpixel(40,415))
     {
      setfillstyle(SOLID_FILL,WHITE);
	   floodfill(175,45+a,WHITE);                //2nd
	 val4=1;
     }

    // delay(2000);
	if(getpixel(135,40+a)==getpixel(75,415))
//	if((getpixel(135,40+a)==rn[1])||(getpixel(135,40+a)==rn[2])||(getpixel(135,40+a)==rn[0]))
     {
      setfillstyle(SOLID_FILL,WHITE);
	   floodfill(175,45+a,WHITE);                //2nd
	    val4=2;
     }

     if(getpixel(135,40+a)==getpixel(100,415))
      {
      setfillstyle(SOLID_FILL,WHITE);
	   floodfill(175,45+a,WHITE);                //2nd
	 val4=3;
     }
    //  return 0;

   }