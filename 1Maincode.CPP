#include <conio.h>
#include <dos.h>
#include <fstream.h>
#include <graphics.h>
#include <iostream.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "TITLE.h"

#define PTS 10

int i,j,n,qno[11],randnum,pn,found,lines,tn,copt,eopt,sopt,c,available,pg,g,chctr,len;
float value;
int tnum,qnum;
long int pos=0;
ofstream fout;
fstream file;
ifstream fin;
char str[500];
char mainh[]="*************ONLINE QUIZ**************";
char topich[2][10]={"SPORTS","GK"};

//initialized qno with 11 random nos from 65 to 84 in main()
//out of the 11, 1st 10 are part of the normal game, last one is needed if swap() is used

//USER DEFINED FUNCTIONS

void drawbox(int x,int y)//length and breadth
{
    textcolor(WHITE);
    int i,j;
    char v=179,h=196;
	char tl=218,tr=191,bl=192,br=217;
	int xgap=(80-x)/2;
	int ygap=(25-y)/2;

	gotoxy(xgap,ygap);
	cprintf("%c",tl);
	for(i=0;i<x;++i)
	cprintf("%c",h);
	cprintf("%c",tr);
	gotoxy(xgap,ygap+1);
    for(j=0;j<y;++j)
       {
	cprintf("%c",v);
	for(i=0;i<x;++i)
	cprintf(" ");
	cprintf("%c",v);
	cprintf("\n");
	gotoxy(xgap,ygap+(j+1));
       }
    gotoxy(xgap,ygap+y);
    cprintf("%c",bl);
    for(i=0;i<x;++i)
	cprintf("%c",h);
	cprintf("%c",br);
}

void drawline_x(int y,int a,int b)//y is line number, a and b are starting and ending positions of line's x coordinates
{
    textcolor(GREEN);
    char h=196;
    char l=195,r=180;
    gotoxy(a,y);
    cprintf("%c",l);
    for(int i=0;i<b-a+1;++i)
	cprintf("%c",h);
    cprintf("%c",r);
}

void drawline_y(int x,int a,int b)//x is distance from leftmost vertical, a and b are starting and ending positions of line's y coordinates
{
    textcolor(GREEN);
    char v=179;
    char t=194,d=193;
    gotoxy(x,a);
    cprintf("%c",t);
    for(int i=0;i<b-a;++i)
	{
	    gotoxy(x,a+i+1);
	    cprintf("%c",v);
	}
    gotoxy(x,b);
    cprintf("%c",d);
}

void center_text(char *str,int y,int col=0)//y is line number (1 to 22)
{
    if(col==1)
    textcolor(LIGHTBLUE);
    else if(col==2)
     textcolor(GREEN+BLINK);
    else if(col==3)
     textcolor(BLUE);
    else textcolor(GREEN);

    int len=strlen(str);
    int space=(80-len)/2;
    gotoxy(space+1,y);                                                        //textmode(3);
    cprintf(str);
}

void place_text(char *str,int x,int y,int l=80)//x and y are starting positions, l is the end coordinate of each line(by default it is the max value 80)
{
    textcolor(GREEN);
    int len=strlen(str),ctr=0,e;

    gotoxy(x,y);
    for(chctr=0;chctr<len;++chctr)
    {
	e=wherex(); // returns value of cursor's x coordinate
	if(e==l)
	{
	    ctr++;
	    gotoxy(x,y+ctr);
	}
	cprintf("%c",(str[chctr]));
    }
}

void game_screen(int, int);//declaration of prototype

//CLASS PROFILE

class profile
{
    char name[20];
    int no;
    static int ctr;

public:
    float points;
    friend void profile_ctr();
    void newprofile();

    void modify()
    {
	center_text((char*)"Enter your new profile name: ",10);
	gotoxy(35,12);

	gets(name);
    }
    void showprofile()
    {
	gotoxy(38,lines);
	cout<<no;
	place_text(name,43,lines);
	lines++;
    }
    void showpoints()
    {
	gotoxy(20,lines);
	cout<<lines-7<<".";
	place_text(name,24,lines);
	gotoxy(44,lines);
	cout<<points;
	lines++;
    }
    int getno()
    {
	return no;
    }
    char *getname()
    {
	return name;
    }
}p,psort[20],pTemp;//needed while sorting points

int profile::ctr=0;

void profile_ctr()
    {
	p.ctr=0;
	fin.open("Profiles.txt",ios::in|ios::binary);
	if(fin)
	{
	    while(!fin.eof())
	    {
		fin.read((char*)&p,sizeof(p));
		if(fin.eof()) break;
		p.ctr++;
	    }
	    n=p.ctr;
	}
	fin.close();
    }

void profile::newprofile()
{
	profile_ctr();
	if (ctr<10)
	{
	    center_text((char*)"Enter your profile name: ",6);
	    gotoxy(35,8);

	    gets(name);
	    no=++ctr;
	    center_text((char*)"Profile created successfully!",10);
	    center_text((char*)"Your profile number is   ",12);
	    gotoxy(52,12);
	    cprintf("%i",no);
	}
	else
	{
	    center_text((char*)"No more profiles can be created!",10);
	    return;
	}
}

//CLASS QUIZ

class quiz
{
public:
    struct question
    {
	int num;//serial no. of question as stored in file
	char ques[100];
	char ans[4][50];
	char clue[100];
	int key;
    }q;

    int userAns;
    float score;

    //lifeline flags (static since each lifeline can be used only once for one game)
    static int cFlag;
    static int eFlag;
    static int sFlag;
    static int correct;

    void getQuestion(int,int);
    void calcScore();
    void readuserAns();
    void dispQues();

    quiz()//constructor
    {
	userAns=0;
	score=0;
    }

    //Lifelines:
    void clueless();
    void eliminate();
    void Swap();


}obj; // an object of class quiz

int quiz::cFlag=0;
int quiz::eFlag=0;
int quiz::sFlag=0;
int quiz::correct=0;

void quiz::getQuestion(int tnum,int qnum)
    {
	if(tnum==1)
	{
	    fin.open("SPORTS.TXT",ios::in);//open file that contains Sports questions
	    while(!fin.eof())
	    {
	       fin.read((char*)&q,sizeof(q));
	       if(q.num==qnum) break;
	    }
	    fin.close();
	}
	else if(tnum==2)
	{
	    fin.open("GK.txt",ios::in);//open file that contains GK questions
	    while(!fin.eof())
	    {
		fin.read((char*)&q,sizeof(q));
		if(q.num==qnum) break;
	    }
	    fin.close();
	}
    }

void quiz::calcScore()
    {
	float P=PTS;
	//FLAGS:
	//1 denotes that particular lifeline has been invoked by user
	//-1 denotes 'not available for rest of the questions in the quiz'
	if(cFlag==1)
	{
	    P*=0.75;
	    cFlag=-1;
	}
	else if(eFlag==1)
	{
	    P*=0.5;
	    eFlag=-1;
	}
	else if(sFlag==1)
	{
	    P*=0.75;
	    sFlag=-1;
	}

	//resetting the flag (if lifeline has not been used, it will be available for next question)
	//-2 denotes 'not available for current question'
	if(cFlag==-2) cFlag=0;
	if(eFlag==-2) eFlag=0;
	if(sFlag==-2) sFlag=0;

	if(userAns==q.key)
    {
	score=P;
	correct++;
    }
	else    // if wrong no points scored
	{
	    score=0;
	    value=0;
	}
	p.points+=score;
	if(!score)
	    {
		gotoxy(2,23);
		cout<<"        ";
		gotoxy(2,23);
		cout<<value<<" pts";
		center_text((char*)"Wrong answer!",22);
		center_text((char*)"The right answer is   ",23);
		gotoxy(51,23);
		cout<<q.key;
	    }
	else
	    {
		center_text((char*)"Well done!",22);
		center_text((char*)"You have scored     points!",23);
		gotoxy(43,23);
		cout<<score;
	    }

	gotoxy(74,23);
	cout<<"     ";
	gotoxy(74,23);
	cout<<p.points;
    }


void quiz::readuserAns()
    {
	cin.clear();// to reset the state of cin
	cin.ignore(INT_MAX,'\n');// to clear the buffer
	//Above statements required for input validation

	center_text((char*)"Enter your answer: ",19);
	center_text((char*)"(If you want to use an available lifeline, enter the corresponding code)",20);
	gotoxy(51,19);
	cout<<"   ";
	gotoxy(51,19);
	cin>>userAns;

	if(cin) // if the value given is int
	switch(userAns)
	{
	case 10: if(copt) clueless();
		 else goto wrong;
		 break;
	case 11: if(eopt) eliminate();
		 else goto wrong;
		 break;
	case 12: if(sopt) Swap();
		 else goto wrong;
		 break;
	case 1:
	case 2:
	case 3:
	case 4: calcScore();
		getch();
		break;
	default:
	    wrong:
	      center_text((char*)"Invalid input! Press enter to retry...",22);
	      gotoxy(40,23);
	      getch();
	      center_text((char*)"                                      ",22);
	      readuserAns();
	    break;
	}
  else goto wrong;

    }

void quiz::dispQues()
{
	gotoxy(2,6);
	cout<<g+1<<")";
	place_text(q.ques,6,6,75);
	for (j=0;j<4;++j)
	{
	    gotoxy((j%2==0?2:42),(j<2?13:15));   //to determine position based on option number
	    cout<<j+1<<")";
	    place_text(q.ans[j],(j%2==0?5:45),(j<2?13:15));
	}

	place_text((char*)"                                                                     ",3,17);
	gotoxy(2,17);
	//copt,eopt and sopt are needed while checking if user is trying to access a lifeline that is not available
	copt=eopt=sopt=1;
	//if lifeline flag=0 that implies it is available
	cprintf("Lifelines: ");
	if((strcmp(q.clue,"!")!=0)&&cFlag==0)
	    cout<<"Clueless!(10) ";
	else copt=0;
	if(eFlag==0)
	    cout<<"Eliminate(11) ";
	else eopt=0;
	if(sFlag==0)
	    cout<<"Swap(12)";
	else sopt=0;

	if(!(sFlag==1||eFlag==1||cFlag==1)) value=PTS;
	place_text((char*)"VALUE",3,22);
	gotoxy(2,23);
	cout<<"        ";
	gotoxy(2,23);
	cout<<value<<" pts";
    }


//QUIZ LIFELINES

void quiz::clueless()
{
    if(strcmp(q.clue,"!")!=0&&cFlag==0)//if q.clue stores "!" then no clue is available for that question
    {
	cFlag=1;
	if(sFlag!=-1) sFlag=-2;
	if(eFlag!=-1) eFlag=-2;
	value=PTS*0.75;
	dispQues();
	place_text(q.clue,3,10);
	readuserAns();
    }
}

void quiz::eliminate()
{
    eFlag=1;
    if(sFlag!=-1) sFlag=-2;
    if(cFlag!=-1) cFlag=-2;
    value=PTS*0.5;
    int elim_options[2];
    time_t t;
    e1:
    srand(time(&t));
    randnum=rand()%4;
    if((randnum+1)!=q.key)
	elim_options[0]=randnum;
    else goto e1;
    e2:
    srand(time(&t));
    randnum=rand()%4;
    if((randnum+1)!=q.key&&randnum!=elim_options[0])
	elim_options[1]=randnum;
    else goto e2;
    dispQues();
    int k;
    for(k=0;k<2;++k)
    switch(elim_options[k])
    {
    case 0:
	place_text((char*)"                                    ",2,13); break;
    case 1:
	place_text((char*)"                                    ",42,13); break;
    case 2:
	place_text((char*)"                                    ",2,15); break;
    case 3:
	place_text((char*)"                                    ",42,15); break;
    }
    readuserAns();
}

void quiz::Swap()
{
    sFlag=1;
    if(cFlag!=-1) cFlag=-2;
    if(eFlag!=-1) eFlag=-2;
    value=PTS*0.75;
    game_screen(tn,qno[10]); // q[10] is the extra question needed for Swap

}

//MORE USER DEFINED FUNCTIONS

void basic_screen(char *subh) //give subheading as argument
{
    clrscr();
    setbkcolor(BLACK);
    drawbox(78,23);
    drawline_x(3,1,78);
    drawline_x(5,1,78);
    drawline_x(20,1,78);
    center_text(mainh,2,2);
    center_text(subh,4,1);

}

void game_screen(int tnum,int qnum)
{
    clrscr();
    setbkcolor(BLACK);
    drawbox(78,23);

    drawline_x(3,1,78);
    drawline_x(5,1,78);
    drawline_x(12,1,78);
    drawline_x(14,1,78);
    drawline_x(16,1,78);
    drawline_x(18,1,78);
    drawline_x(21,1,78);

    drawline_y(40,12,16);
    drawline_y(10,21,24);
    drawline_y(70,21,24);

    center_text(mainh,2,2);
    center_text(topich[tnum-1],4,1);

    place_text((char*)"TOTAL",73,22);
    gotoxy(74,23);
    cout<<"      ";
    gotoxy(74,23);
    cout<<p.points;

    obj.getQuestion(tnum,qnum);
    obj.dispQues();
    obj.readuserAns();
}

//MAIN()

int main()
{
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "C:\\TC\\BGI");

    title();//Tiltle page function in TITLE.h

    cleardevice();

    int main_ch,play_ch,profile_ch;
    ///Subheadings
    char menu[]="MAIN MENU";
    char profiles[]="PROFILES";

    setbkcolor(BLACK);
    settextstyle(GOTHIC_FONT,0,7);
    setcolor(RED);
    delay(1500);

start:
    textmode(3);
    basic_screen(menu);
    center_text((char*)" 1. PLAY          ",6);//all string arguments have been casted as character pointers
    center_text((char*)" 2. PROFILES      ",8);
    center_text((char*)" 3. POINTS HISTORY",10);
    center_text((char*)" 4. INSTRUCTIONS  ",12);
    center_text((char*)" 5. EXIT          ",14);

    place_text((char*)"If you are a new player, go to PROFILES and add your name. After creating yourprofile, go to PLAY and enter your profile no. to start the quiz. For the restof the rules about the quiz, go to INSTRUCTIONS.",2,16);
    center_text((char*)"Enter your choice (1-5) ",21,3);
    gotoxy(40,23);
    cin>>main_ch;
    if(cin)
    switch(main_ch)
    {
    case 1:
	lgame:
	basic_screen((char*)"CHOOSE PROFILE AND TOPIC");
	fin.open("Profiles.txt",ios::in|ios::binary);
	if(fin)
	{
	    center_text((char*)"Enter your profile number:",6,3);
	    gotoxy(40,8);
	    cin>>pn;
	    found=0;

	    while(!fin.eof())
		{
		    fin.read((char*)&p,sizeof(p));
		    if(fin.eof()) break;
		    if(p.getno()==pn)
		    {
			found=1;
			len=8+strlen(p.getname());
			gotoxy((80-len)/2+1,10);
			cout<<"Hey "<<p.getname()<<" !";
			center_text((char*)"The topics are:",12);
			center_text((char*)"1. Sports",14);
			center_text((char*)"2. GK    ",15);
			center_text((char*)"Enter topic no.(1 or 2): ",17,3);
			ltopic:
			gotoxy(40,18);
			cout<<"  ";
			gotoxy(40,18);
			cin>>tn;
			if(tn!=1&&tn!=2)
			{
			    center_text((char*)"Wrong topic no.! Enter 1 or 2: ",17,3);
			    goto ltopic;
			}
			break;
		    }
		}
	    fin.close();
	    if(!found)
	    {
		center_text((char*)"The profile no. entered does not exist!",10,3);
		center_text((char*)"Press enter to go back...",21,3);
		gotoxy(40,22);
		getch();
		goto start;
	    }
	    center_text((char*)"ALL THE BEST!",21);
	    center_text((char*)"Press enter to start the quiz...",23,3);
	    gotoxy(40,24);
	    getch();

	    //Initializing qno with 11 random nos (and displaying loading message since it takes too long)
	    basic_screen(topich[tn-1]);
	    for(i=0;i<11;++i)
	    {
		gotoxy(33,12);
		cout<<"LOADING......"<<11-i<<"  ";
		gotoxy(28,18);
		cout<<"10s FEELS LOOOOOONG RIGHT?";

		time_t t;
		r1:
		srand(time(&t));
		randnum=rand()%20+65; // range is from 65 to 84
		if(i==0)
		qno[i]=randnum;
		for(j=0;j<i;++j)
		if(qno[j]==randnum)
		goto r1;
		else if(j==i-1)
		qno[i]=randnum;

	    }

	   //resetting flags
	   obj.cFlag=obj.eFlag=obj.sFlag=obj.correct=0;

	   for(g=0;g<10;++g)
	    {
		game_screen(tn,qno[g]);
	    }

	    basic_screen((char*)"END OF QUIZ");
	    center_text((char*)"You answered   /10 questions correctly.",8);
	    gotoxy(34,8);
	    cout<<obj.correct;
	    center_text((char*)"Lifelines used:",10);
	    if(obj.cFlag==-1) place_text((char*)"Clueless!",36,wherey()+1);
	    if(obj.eFlag==-1) place_text((char*)"Eliminate",36,wherey()+1);
	    if(obj.sFlag==-1) place_text((char*)"Swap",38,wherey()+1);
	    if(!obj.cFlag&&!obj.eFlag&&!obj.sFlag) place_text((char*)"None",38,wherey()+1);
	    center_text((char*)"Your final score is:   ",16,3);
	    gotoxy(50,16);
	    cprintf("%.1f",p.points);

	    fout.open("POINTS.txt",ios::out|ios::app|ios::binary);
	    fout.write((char*)&p,sizeof(p));
	    fout.close();
	    center_text((char*)"Press enter to go to main menu...",21,3);
	    gotoxy(40,22);
	    getch();
	    goto start;
	}
	else
	{
	    center_text((char*)"No profiles have been created!",10);
	    center_text((char*)"(To create a profile, go to PROFILES in the main menu)",12);
	    center_text((char*)"Press enter to go to back...",21,3);
	    gotoxy(40,22);
	    getch();
	    goto start;
	}

    case 2:
	lprofile:
	basic_screen(profiles);
	center_text((char*)" 1. ADD     ",6);
	center_text((char*)" 2. MODIFY  ",8);
	center_text((char*)" 3. VIEW ALL",10);
	center_text((char*)" 4. BACK    ",12);
	place_text((char*)"If you are a new player, go to ADD. If you have already created your profile, then you can go to MODIFY to change your name. VIEW ALL will show you the listof all profiles and their numbers.",2,16);
	center_text((char*)"Enter your choice (1-4) ",21,3);
	gotoxy(40,23);
	cin>>profile_ch;
	switch(profile_ch)
	{
	case 1:
	    basic_screen((char*)"ADD PROFILE");
	    p.newprofile();
	    if(n<10)
	    {
		fout.open("Profiles.txt",ios::out|ios::app|ios::binary);
		fout.write((char*)&p,sizeof(p));
		fout.close();
	    }
	    center_text((char*)"Press enter to go back...",21,3);
	    gotoxy(40,22);
	    getch();
	    goto lprofile;

	case 2:
	    basic_screen((char*)"MODIFY PROFILE");
	    center_text((char*)"Enter profile no.: ",6);
	    gotoxy(39,8);
	    cin>>pn;
	    found=0;
	    file.open("Profiles.txt",ios::in|ios::out|ios::binary);
	    while(!file.eof())
		{
		    pos=file.tellg();
		    file.read((char*)&p,sizeof(p));
		    if(file.eof()) break;
		    if(p.getno()==pn)
		    {
			found=1;
			p.modify();
			file.seekp(pos);
			file.write((char*)&p,sizeof(p));
			center_text((char*)"Profile updated successfully!",14);
			break;
		    }
		}
	    file.close();
	    if(!found)
		center_text((char*)"The profile no. entered does not exist!",10);

	    center_text((char*)"Press enter to go back...",21,3);
	    gotoxy(40,22);
	    getch();
	    goto lprofile;

	case 3:
	    basic_screen((char*)"ALL PROFILES");

	    fin.open("Profiles.txt",ios::in|ios::binary);
	    if(fin)
	    {
		center_text((char*)"PROFILE NO.  NAME       ",6);
		lines=8;
		fin.seekg(0);
		while(!fin.eof())
		{
		    fin.read((char*)&p,sizeof(p));
		    if(fin.eof()) break;
		    p.showprofile();
		}
	    }
	    else center_text((char*)"No profiles have been created yet!",6);

	    fin.close();
	    center_text((char*)"Press enter to go back...",21,3);
	    gotoxy(40,22);
	    getch();
	    goto lprofile;

	case 4:
	    goto start;

	default:
	    center_text((char*)"Invalid option! Press enter to retry...",21,3);
	    gotoxy(40,22);
	    getch();
	    goto lprofile;
	}

    case 3:
	basic_screen((char*)"POINTS HISTORY");
	available=0;
	fin.open("POINTS.txt",ios::in|ios::binary);
	if(fin)
	{
	    available=1;
	    c=0;
	    while(!fin.eof())
	    {
		fin.read((char*)&psort[c],sizeof(psort[c]));
		if(fin.eof()) break;
		c=c+1;
	    }

	    //Sorting(in descending order of points):
	    for(i=0;i<c;++i)
	     for(j=0;j<c-i-1;++j)
		if(psort[j].points<psort[j+1].points)
		{
		    pTemp=psort[j];
		    psort[j]=psort[j+1];
		    psort[j+1]=pTemp;
		}
	}
	else
	{
	    center_text((char*)"No points history available!",10);
	    available=0;
	}
     fin.close();

	if(available==1)
	{
	    fout.open("POINTS.txt",ios::out|ios::binary);
	    {
		center_text((char*)"NAME                POINTS SCORED",6);
		lines=8;
		if(c>10)
		    for(i=0;i<10;++i)
		    {
			psort[i].showpoints();
			fout.write((char*)&psort[i],sizeof(psort[i]));
		    }
		else for(i=0;i<c;++i)
		    {
			psort[i].showpoints();
			fout.write((char*)&psort[i],sizeof(psort[i]));
		    }
	    }
	    fout.close();
	}

	center_text((char*)"Press enter to go back...",21,3);
	gotoxy(40,22);
	getch();
	goto start;

   case 4:
	pg=1;
    instruct:
	basic_screen((char*)"INSTRUCTIONS");
	lines=6;
	while(fin.getline(str,100)&&lines<(20))
	{
	     place_text(str,2,lines);
	     lines++;
	}
	pg++;
	if(!fin.eof())
	{
	    center_text((char*)"Press enter to go to next page...",21,3);
	    gotoxy(40,22);
	    getch();
	    goto instruct;
	}
	fin.close();
	gotoxy(3,6);
	cout<<"1)Enter the number for the given function.";
	gotoxy(3,7);
	cout<<"2)Create a profile, enter profile number and select topic to play.  ";
	gotoxy(3,8);
	cout<<"3)There are 10 questions with 4 options and 2 lifelines for each question.";
	gotoxy(3,9);
	cout<<"4)The lifelines 'Swap' and 'Eliminate' are there for all questions. ";
	gotoxy(3,10);
	cout<<"5)A third lifeline 'Swap' is there for a few questions.";
	gotoxy(3,11);
	cout<<"6)The value of the question decreases when the lifeline is used.";
	gotoxy(3,12);
	cout<<"7)The new value of the question is given on the side.";
	gotoxy(3,13);
	cout<<"8)The total score comes out at the last.";
	gotoxy(3,14);
	cout<<"9)You can see you scores in POINTS HISTORY.";
	gotoxy(3,15);
	cout<<"10)Enjoy the game!";

	center_text((char*)"Press enter to go back to main menu...",21,3);
gotoxy(40,22);
	getch();
	goto start;

    case 5: exit(0); break;

    default:
	center_text((char*)"Invalid option! Press enter to retry...",21,3);
	gotoxy(40,22);
	getch();
	goto start;
    } // end of main switch

    getch();
    closegraph();
    return 0;
}
