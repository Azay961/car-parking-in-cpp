#include<iostream>
#include<graphics.h>
#include<dos.h>
using namespace std;
int n,pr,j,i,num[10],ex[10];
class parking
{
	private:
		int y1,y2,m1,m2,d1,d2,hr1, hr2,min1,min2;
		long int t1_min,t2_min,t_min,t_hr;
	    float charge,hr;
		char number[108],c_md[15],driver[25];
		
	public:
		parking()
		{y1=0;y2=0;m1=0;m2=0;d1=0;d2=0;hr1=0;hr2=0;min1=0;min2=0;
			t1_min=0;t2_min=0;t_min=0;t_hr=0;
			charge=0;hr=0;
		}
        friend void show(parking);
        friend void getdata(int);
        friend void car();
	    friend void color(int,int);
	    friend void box();
	    friend void gotoxy(int x, int y);
	void entry()
	{       cout<<"Enter the Car model:";
	        cin>>c_md;
	        cout<<"Enter the driver of car.";
	        cin>>driver;
	        cout<<"Enter the car number.";
	        cin>>number;
	        cout<<"Enter the date of entry(YYYY:MM:DD)."<<endl;
			cin>>y1;
		    if(y1>=2070&&y1<=2080)
		    {cin>>m1;
		    	if(m1<13&&m1>0)
		    	{cin>>d1;
		    		if(d1<31&&d1>0)
		    		{cout<<"Time:(Hour:Minute:)"<<endl;
					cin>>hr1;
		    			if(hr1>=0&&hr1<24)
		    			{cin>>min1;
		    			  if(min1>60&&min1<0)
							  {cout<<"Invalid minute"<<endl;}
						}
						else
						{cout<<"Invalid hour"<<endl;}
					}
					else
					{cout<<"Invalid day"<<endl;}
				}
				else
				{cout<<"Invalid month"<<endl;}
			}
			else
			{cout<<"Invalid year"<<endl;}
	}
						
	void exit()
	{    
	       cout<<"Enter the date of exit(YYYY:MM:DD)."<<endl;
			cin>>y2;
			if (y2<y1)
			{cout<<"Exit date should be greater or equql to entry date."<<endl;
			}
			else
			{
		    if(y2>=2070&&y2<=2080)
		    {cin>>m2;
		    	if(m2<13&&m2>0)
		    	{cin>>d2;
		    		if(d2<31&&d2>0)
		    		{cout<<"Time:(Hour:Minute:)"<<endl;
					cin>>hr2;
		    			if(hr2>=0&&hr2<24)
		    			{cin>>min2;
		    				if(min2>60&min2<0)
							  {cout<<"Invalid minute"<<endl;}
						}
						else
						{cout<<"Invalid hour"<<endl;}
					}
					else
					{cout<<"Invalid day"<<endl;}
				}
				else
				{cout<<"Invalid month"<<endl;}
			}
			else
			{cout<<"Invalid year"<<endl;}	
	}  
}
	  void calculation()
	  {	 t1_min=y1*365*24*60+m1*30*24*60+d1*24*60+hr1*60+min1;
	    t2_min=y2*365*24*60+m2*30*24*60+d2*24*60+hr2*60+min2;
		t_min=t2_min-t1_min;
		hr=static_cast<float>(t_min)/60;
		t_min=t_min%60;
		if (hr<=3)
		{
			charge=2;//charge for 3 hours
		}
		else if(hr>3&&hr<24)
		{
			charge+=2+((hr-3)*0.5);//charge more than 3 hours
		}
		else if(hr>=24)
		{
			charge+=(hr/24)*8;//for charges more than 24 hours
		}
		t_hr=static_cast<int>(hr);//to show parked hour
		
	  }
};
void show(parking p)
{
	cout<<"*************************************************************"<<endl;	    
		 	cout<<"Car model:"<<p.c_md<<endl;
		 	cout<<"Driver:"<<p.driver<<endl;
		 	cout<<"Car number:"<<p.number<<endl;
		 	cout<<"Entry date:"<<p.y1<<":"<<p.m1<<":"<<p.d1<<endl;
		 	cout<<"Entry time:"<<p.hr1<<":"<<p.min1<<endl;
		 	cout<<"Exit date:"<<p.y2<<":"<<p.m2<<":"<<p.d2<<endl;
		 	cout<<"Exit time:"<<p.hr2<<":"<<p.min2<<endl;
			cout<<"Total parked hour"<<p.t_hr<<" hours "<<p.t_min<<" minutes."<<endl;
			cout<<"Total charge:$."<<p.charge<<endl;	 	
	cout<<"*************************************************************"<<endl;
}
void gotoxy(int x, int y)
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void getdata(int i)
{	cout<<"######### Here is only "<<10-i<<" parking space left.########"<<endl<<endl;
                cout<<"Choose a option('1','2','3','4','5')"<<endl;
	            cout<<"1.Arrival of car."<<endl;
	            cout<<"2.Departure of car."<<endl;
	            cout<<"3.Details for particular car."<<endl;
	            cout<<"4.All details."<<endl;
				cout<<"5.End of a program."<<endl;
				cin>>n;
	cout<<"###############################################################"<<endl<<endl;
	   //if (i==0&&n!=1)
	   //{if(n!=5)}
}
void car(int flag)
{

/*for (int i=0;i<500;i++)
{  if(flag==0)
    {settextstyle(BOLD_FONT,4,4);
      outtextxy(300,200,"Entering....");
    }
   else if(flag==1)
    {
     settextstyle(BOLD_FONT,4,4);
      outtextxy(300,200,"Exiting....");	
    }
//CAR BODY 
line(50+i,370,90+i,370);
arc(110+i,370,0,180,20);
line(130+i,370,220+i,370);
arc(240+i,370,0,180,20);
line(260+i,370,300+i,370);
line(300+i,370,300+i,350);
line(300+i,350,240+i,330);
line(240+i,330,200+i,300);
line(200+i,300,110+i,300);
line(110+i,300,80+i,330);
line(80+i,330,50+i,340);
line(50+i,340,50+i,370);

//CAR Windows
line(165+i,305,165+i,330);
line(165+i,330,230+i,330);
line(230+i,330,195+i,305);
line(195+i,305,165+i,305);

line(160+i,305,160+i,330);
line(160+i,330,95+i,330);
line(95+i,330,120+i,305);
line(120+i,305,160+i,305);

//Wheels
circle(110+i,370,17);
circle(240+i,370,17);

delay(10);
cleardevice();
line(0,390,639,390);  //ROAD
}*/
}
void color()
{
	int col;
	for (int k=1;k<=11;k++)
	{

	   if(ex[k]==k)
		{
			col=4;
		}
	    else if(num[k]==k)
		{
			 col=2;
		}
	if (num[k]==k||ex[k]==k)
	{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),col);
	switch(k)
	{case 1:gotoxy(85,8);break;
	case 2:gotoxy(90,8);break;
	case 3 :gotoxy(95,8);break;
	case 4:gotoxy(85,10);break;
	case 5:gotoxy(90,10);break;
	case 6:gotoxy(95,10);break;
	case 7:gotoxy(85,12);break;
	case 8:gotoxy(90,12);break;
	case 9:gotoxy(95,12);break;
	case 10:gotoxy(90,14);break;	
    }
	cout<<k;
    }
}}
void box()
{
	for(int i=0;i<10;i++)
	{ 
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
		gotoxy(110,6+i);
		cout<<"|";
		gotoxy(80,6+i);
		cout<<"|";	
	
	}
	for(int i=0;i<29;i++)
	{ 
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
		gotoxy(81+i,5);
		cout<<"_";
		gotoxy(81+i,15);
		cout<<"_";
	}
	gotoxy(82,7);cout<<"Parking numbers:";
	gotoxy(85,8);cout<<"1";
	gotoxy(90,8);cout<<"2";
	gotoxy(95,8);cout<<"3";
	gotoxy(85,10);cout<<"4";
	gotoxy(90,10);cout<<"5";
	gotoxy(95,10);cout<<"6";
	gotoxy(85,12);cout<<"7";
	gotoxy(90,12);cout<<"8";
	gotoxy(95,12);cout<<"9";
	gotoxy(90,14);cout<<"10";
	gotoxy(100,9);cout<<"Index:";
	gotoxy(101,10);cout<<":Entered";
	gotoxy(101,11);cout<<":Exited";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
	gotoxy(100,10);cout<<"o";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
	gotoxy(100,11);cout<<"o";
}
int main()
{//initwindow(500,500);
  parking p[11];
  int m,parkspace=0;;
  cout<<"WELCOME TO OUR PARKING AREA. "<<endl;
  do
  {
  box();
  color();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);  	
     gotoxy(0,2);
	 getdata(parkspace); 
        if(n==1)
        {
		   cout<<"Enter the parking number:";cin>>i;
		    if(parkspace<11)
        	  {
        	  	num[i]=i;
        	   parkspace++;
        	   p[i].entry();
        	   car(0);
        	   color();
			  }
		}
	 	else if (n==2)
	 	{
			cout<<"Enter the parking number(1-10) of car to exit."<<endl;
			do
			{
				cin>>pr;
			    if(pr>11&&pr<0)
			    {cout<<"Re-enter(1 to 10):";}
			    else if(pr<11&&pr>0)
			    {break;}
			}while(1);
			do
			{     
			   if(num[j]==pr)
			   {
			   	ex[pr]=pr;
			     p[pr].exit();
			     p[pr].calculation();
			     car(1);			  	
			     color();
			     parkspace--;
			     break;
			   }
			   else if(j==11)
			   {
			   	cout<<"Not entered here yet"<<endl;
			   	Sleep(1000);
				   break;
			   }
			    j++;
			}while(j<12);
		 }
		 else if(n==3)//details for particular car
		 {
			cout<<"Enter the parking number to show detail(1 to 10)."<<endl;
			cin>>m;
			if(m>0&&m<11)
			{cout<<"Parking number is:"<<m<<endl;
			show(p[m]);}
		    else
		    {	cout<<"Re-enter(1-10):";
		    	cin>>m;
			}
			getch();
		 }

		 else if(n==4)//to show details upto now
		 {
		 	for(int j=1;j<=10;j++)
		 	{
		 		show(p[j]);
			 }	 
			 getch();
		 }
	    else if(n==5)//end of program
		 {
		 	exit(0);
		 }
		 else if(n<1||n>5)
		 {
		 	cout<<"invalid input."<<endl;getch();
		 }
		 if(parkspace==10)
		 {
		 	cout<<"Parking space is full.";getch();
		 }
		 system("cls");
  }while(1);
  return 0;
}

