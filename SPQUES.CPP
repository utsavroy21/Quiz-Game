 #include <iostream.h>
 #include <conio.h>
 #include <fstream.h>
 #include <string.h>

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
    }q[20];

 } obj;

void main()
{
 int i;
 for(i=0;i<20;++i)
 {
  obj.q[i].num=i+65;
  switch(i)
  {
   case 0:
    strcpy(obj.q[i].ques,"The 2014 FIFA WC was hosted by?");
    strcpy(obj.q[i].ans[0],"South Africa");
    strcpy(obj.q[i].ans[1],"Argentina");
    strcpy(obj.q[i].ans[2],"France");
    strcpy(obj.q[i].ans[3],"Germany");
    strcpy(obj.q[i].clue,"!");
    obj.q[i].key=1 ;
    break;

   case 1:
    strcpy(obj.q[i].ques,"Which country won the final of the triangular cricket series held in February 1997?");
    strcpy(obj.q[i].ans[0],"India");
    strcpy(obj.q[i].ans[1],"South Africa");
    strcpy(obj.q[i].ans[2],"Zimbabwe");
    strcpy(obj.q[i].ans[3],"New Zealand");
    strcpy(obj.q[i].clue,"!");
    obj.q[i].key=2 ;
    break;

   case 2:
    strcpy(obj.q[i].ques,"Who has one the most individual medals  in olympics?");
    strcpy(obj.q[i].ans[0],"Usain Bolt");
    strcpy(obj.q[i].ans[1],"P T Usha");
    strcpy(obj.q[i].ans[2],"Mark Spitz");
    strcpy(obj.q[i].ans[3],"Michael Phelps");
    strcpy(obj.q[i].clue,"He/she was a swimmer.");
    obj.q[i].key=4 ;
    break;

   case 3:
    strcpy(obj.q[i].ques,"Which of these events made its debut at the 2014 Glasgow CWG?");
    strcpy(obj.q[i].ans[0],"Archery");
    strcpy(obj.q[i].ans[1],"Women's Boxing");
    strcpy(obj.q[i].ans[2],"Women's Weightlifting");
    strcpy(obj.q[i].ans[3],"Women's Wrestling");
    strcpy(obj.q[i].clue,"Sarita Devi of India won a silver medal in this event.");
    obj.q[i].key=2 ;
    break;

   case 4:
    strcpy(obj.q[i].ques,"The Asian Games were held in Delhi for the first time in ___");
    strcpy(obj.q[i].ans[0],"1971");
    strcpy(obj.q[i].ans[1],"1982");
    strcpy(obj.q[i].ans[2],"1951");
    strcpy(obj.q[i].ans[3],"1963");
    strcpy(obj.q[i].clue,"!");
    obj.q[i].key=3 ;
    break;

   case 5:
    strcpy(obj.q[i].ques,"Which country will be hosting the 2018 Commonwealth Games?");
    strcpy(obj.q[i].ans[0],"New Zealand");
    strcpy(obj.q[i].ans[1],"India");
    strcpy(obj.q[i].ans[2],"Scotland");
    strcpy(obj.q[i].ans[3],"Australia");
    strcpy(obj.q[i].clue,"This country did not host the 2010 CWG.");
    obj.q[i].key=4 ;
    break;

   case 6:
    strcpy(obj.q[i].ques,"Who received the khel ratna award in 2015?");
    strcpy(obj.q[i].ans[0],"Saina Nehwal");
    strcpy(obj.q[i].ans[1],"Sachin Tendulkar");
    strcpy(obj.q[i].ans[2],"Abhinav Bindra");
    strcpy(obj.q[i].ans[3],"Sania Mirza");
    strcpy(obj.q[i].clue,"She won the tennis doubles");
    obj.q[i].key=4 ;
    break;

    case 7:
    strcpy(obj.q[i].ques,"India won its first Olympic hockey gold in ___?");
    strcpy(obj.q[i].ans[0],"1928");
    strcpy(obj.q[i].ans[1],"1948");
    strcpy(obj.q[i].ans[2],"1932");
    strcpy(obj.q[i].ans[3],"1936");
    strcpy(obj.q[i].clue,"Amsterdam hosted the Olympics in that year.");
    obj.q[i].key=1 ;
    break;

   case 8:
    strcpy(obj.q[i].ques,"How old was Pele when he won his first World Cup?");
    strcpy(obj.q[i].ans[0],"18");
    strcpy(obj.q[i].ans[1],"16");
    strcpy(obj.q[i].ans[2],"20");
    strcpy(obj.q[i].ans[3],"17");
    strcpy(obj.q[i].clue,"!");
    obj.q[i].key=4 ;
    break;

   case 9:
    strcpy(obj.q[i].ques,"Who was the first Indian to reach the semi final in Wimbledon Tennis Championship?");
    strcpy(obj.q[i].ans[0],"Leander Paes");
    strcpy(obj.q[i].ans[1],"Mahesh Bhupathi");
    strcpy(obj.q[i].ans[2],"Ramanathan Krishnan");
    strcpy(obj.q[i].ans[3],"Ramesh Krishnan");
    strcpy(obj.q[i].clue,"This happened in the years 1960 and 1961.");
    obj.q[i].key=3 ;
    break;

   case 10:
    strcpy(obj.q[i].ques,"India reached the final of the Davis Cup for the first time in ___?");
    strcpy(obj.q[i].ans[0],"1970");
    strcpy(obj.q[i].ans[1],"1974");
    strcpy(obj.q[i].ans[2],"1964");
    strcpy(obj.q[i].ans[3],"1966");
    strcpy(obj.q[i].clue,"!");
    obj.q[i].key=4 ;
    break;

   case 11:
    strcpy(obj.q[i].ques,"With which sport is the 'Uber Cup' associated?");
    strcpy(obj.q[i].ans[0],"Golf");
    strcpy(obj.q[i].ans[1],"Tennis");
    strcpy(obj.q[i].ans[2],"Badminton");
    strcpy(obj.q[i].ans[3],"Squash");
    strcpy(obj.q[i].clue,"!");
    obj.q[i].key=3 ;
    break;

    case 12:
    strcpy(obj.q[i].ques,"Ashwini Ponappa is a ____ player.");
    strcpy(obj.q[i].ans[0],"Golf");
    strcpy(obj.q[i].ans[1],"Squash");
    strcpy(obj.q[i].ans[2],"Tennis");
    strcpy(obj.q[i].ans[3],"Badminton");
    strcpy(obj.q[i].clue,"She, along with Jwala Gutta, won the doubles gold medal for this event at the 2014 CWG.");
    obj.q[i].key=4 ;
    break;

   case 13:
    strcpy(obj.q[i].ques,"How many gold medals have been won by India in the Olympics so far?");
    strcpy(obj.q[i].ans[0],"8");
    strcpy(obj.q[i].ans[1],"4");
    strcpy(obj.q[i].ans[2],"6");
    strcpy(obj.q[i].ans[3],"1");
    strcpy(obj.q[i].clue,"!");
    obj.q[i].key=1 ;
    break;

   case 14:
    strcpy(obj.q[i].ques,"Roland Garros is the ___ of the 4 annual Grand Slam tournaments.");
    strcpy(obj.q[i].ans[0],"First");
    strcpy(obj.q[i].ans[1],"Second");
    strcpy(obj.q[i].ans[2],"Third");
    strcpy(obj.q[i].ans[3],"Fourth");
    strcpy(obj.q[i].clue,"!");
    obj.q[i].key=2 ;
    break;

   case 15:
    strcpy(obj.q[i].ques,"Who has set up a Tennis School at Anantapur in Andhra Pradesh?");
    strcpy(obj.q[i].ans[0],"Andy Murray");
    strcpy(obj.q[i].ans[1],"Rafael Nadal");
    strcpy(obj.q[i].ans[2],"Novak Djokovic");
    strcpy(obj.q[i].ans[3],"Pete Sampras");
    strcpy(obj.q[i].clue,"!");
    obj.q[i].key=2 ;
    break;

   case 16:
    strcpy(obj.q[i].ques,"Where was the 1st ODI match played in India?");
    strcpy(obj.q[i].ans[0],"Mumbai");
    strcpy(obj.q[i].ans[1],"New Delhi");
    strcpy(obj.q[i].ans[2],"Ahmedabad");
    strcpy(obj.q[i].ans[3],"Kolkata");
    strcpy(obj.q[i].clue,"!");
    obj.q[i].key=3 ;
    break;

   case 17:
    strcpy(obj.q[i].ques,"Who was the first captain of the Indian Test team?");
    strcpy(obj.q[i].ans[0],"Vijay Hazare");
    strcpy(obj.q[i].ans[1],"Vijay Merchant");
    strcpy(obj.q[i].ans[2],"C K Nayudu");
    strcpy(obj.q[i].ans[3],"Lala Amarnath");
    strcpy(obj.q[i].clue,"!");
    obj.q[i].key=3 ;
    break;

   case 18:
    strcpy(obj.q[i].ques,"How many Grand Slams has Roger Federer won so far?");
    strcpy(obj.q[i].ans[0],"14");
    strcpy(obj.q[i].ans[1],"20");
    strcpy(obj.q[i].ans[2],"17");
    strcpy(obj.q[i].ans[3],"16");
    strcpy(obj.q[i].clue,"!");
    obj.q[i].key=3 ;
    break;

   case 19:
    strcpy(obj.q[i].ques,"Which country won the World Cup (Cricket) in 2011?");
    strcpy(obj.q[i].ans[0],"Pakistan");
    strcpy(obj.q[i].an[1],"South Africa");
    strcpy(obj.q[i].ans[2],"India");
    strcpy(obj.q[i].ans[3],"England");
    strcpy(obj.q[i].clue,"!");
    obj.q[i].key=3 ;
    break;

  /* case 20:
    strcpy(obj.q[i].ques,"Who was the captain of the Indian cricket team that won the World Cup in  1983?");
    strcpy(obj.q[i].ans[0],"Sunil Gavaskar");
    strcpy(obj.q[i].ans[1],"Sachin Tendulkar");
    strcpy(obj.q[i].ans[2],"Kapil Dev");
    strcpy(obj.q[i].ans[3],"Ravi Shastri");
    strcpy(obj.q[i].clue,"!");
    obj.q[i].key=3 ;
    break;
    */
 }
}

ofstream fout("SPORTS.TXT",ios::out|ios::binary);
for(i=0;i<20;++i)
fout.write((char*)&obj.q[i],sizeof(obj.q[i]));
fout.close();
cout<<"Success";
getch();
}
