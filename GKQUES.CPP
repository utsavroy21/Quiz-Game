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
    strcpy(obj.q[i].ques,"The country that covers most time zones-");
    strcpy(obj.q[i].ans[0],"USA");
    strcpy(obj.q[i].ans[1],"France");
    strcpy(obj.q[i].ans[2],"Canada");
    strcpy(obj.q[i].ans[3],"Russia");
    strcpy(obj.q[i].clue,"European country.");
    obj.q[i].key=2 ;
    break;

   case 1:
    strcpy(obj.q[i].ques,"Which coutry has the most number of lakes?");
    strcpy(obj.q[i].ans[0],"Canada");
    strcpy(obj.q[i].ans[1],"Pakistan");
    strcpy(obj.q[i].ans[2],"India");
    strcpy(obj.q[i].ans[3],"USA");
    strcpy(obj.q[i].clue,"Famous for wood.");
    obj.q[i].key=1 ;
    break;

   case 2:
    strcpy(obj.q[i].ques,"The country with most number of languages spoken?");
    strcpy(obj.q[i].ans[0],"Fiji");
    strcpy(obj.q[i].ans[1],"Cameroon");
    strcpy(obj.q[i].ans[2],"Nauru");
    strcpy(obj.q[i].ans[3],"Papua New Guinea");
    strcpy(obj.q[i].clue,"It is located in the pacific");
    obj.q[i].key=4 ;
    break;

   case 3:
    strcpy(obj.q[i].ques,"Least peaceful nation");
    strcpy(obj.q[i].ans[0],"Iraq");
    strcpy(obj.q[i].ans[1],"Syria");
    strcpy(obj.q[i].ans[2],"Pakistan");
    strcpy(obj.q[i].ans[3],"Somalia");
    strcpy(obj.q[i].clue,"!");
    obj.q[i].key=4 ;
    break;

   case 4:
    strcpy(obj.q[i].ques,"Which country isthe largest producer of sugar?");
    strcpy(obj.q[i].ans[0],"Brazi");
    strcpy(obj.q[i].ans[1],"Cuba");
    strcpy(obj.q[i].ans[2],"India");
    strcpy(obj.q[i].ans[3],"Argentina");
    strcpy(obj.q[i].clue,"!");
    obj.q[i].key=2 ;
    break;

   case 5:
    strcpy(obj.q[i].ques,"The country having no rivers");
    strcpy(obj.q[i].ans[0],"Cameroon");
    strcpy(obj.q[i].ans[1],"Egypt");
    strcpy(obj.q[i].ans[2],"Saudi Arabia");
    strcpy(obj.q[i].ans[3],"Bahrain");
    strcpy(obj.q[i].clue,"!");
    obj.q[i].key=3 ;
    break;

   case 6:
    strcpy(obj.q[i].ques,"The currency of Indonesia is _____.");
    strcpy(obj.q[i].ans[0],"Rupiah");
    strcpy(obj.q[i].ans[1],"Dinar");
    strcpy(obj.q[i].ans[2],"Ringgit");
    strcpy(obj.q[i].ans[3],"Riyal");
    strcpy(obj.q[i].clue,"It is equivalent to 100 sen.");
    obj.q[i].key=1 ;
    break;

    case 7:
    strcpy(obj.q[i].ques,"The largest oxygen producer");
    strcpy(obj.q[i].ans[0],"Canada");
    strcpy(obj.q[i].ans[1],"Russia");
    strcpy(obj.q[i].ans[2],"Japan");
    strcpy(obj.q[i].ans[3],"USA");
    strcpy(obj.q[i].clue,"Is also geographically the third largest country");
    obj.q[i].key=2 ;
    break;

   case 8:
    strcpy(obj.q[i].ques,"The largest producer of rice ____.");
    strcpy(obj.q[i].ans[0],"China");
    strcpy(obj.q[i].ans[1],"Japan");
    strcpy(obj.q[i].ans[2],"India");
    strcpy(obj.q[i].ans[3],"Phillippines");
    strcpy(obj.q[i].clue,"East asian island country");
    obj.q[i].key=4 ;
    break;

   case 9:
    strcpy(obj.q[i].ques,"Which is the poorest country in the wrold");
    strcpy(obj.q[i].ans[0],"Sierra Leonne");
    strcpy(obj.q[i].ans[1],"Chad");
    strcpy(obj.q[i].ans[2],"Niger");
    strcpy(obj.q[i].ans[3],"Somalia");
    strcpy(obj.q[i].clue,"Coastal Africa.");
    obj.q[i].key=4 ;
    break;

   case 10:
    strcpy(obj.q[i].ques,"The country named after a tree is ______.");
    strcpy(obj.q[i].ans[0],"Brazil");
    strcpy(obj.q[i].ans[1],"Egypt");
    strcpy(obj.q[i].ans[2],"Libya");
    strcpy(obj.q[i].ans[3],"Cameroon");
    strcpy(obj.q[i].clue,"!");
    obj.q[i].key=1 ;
    break;

   case 11:
    strcpy(obj.q[i].ques,"The world's highest mountain is in _____.");
    strcpy(obj.q[i].ans[0],"China");
    strcpy(obj.q[i].ans[1],"Pakistan");
    strcpy(obj.q[i].ans[2],"Nepal");
    strcpy(obj.q[i].ans[3],"India");
    strcpy(obj.q[i].clue,"!");
    obj.q[i].key=3 ;
    break;

   case 12:
    strcpy(obj.q[i].ques,"The headquarters of Red Cross is in ______.");
    strcpy(obj.q[i].ans[0],"New York");
    strcpy(obj.q[i].ans[1],"Washington");
    strcpy(obj.q[i].ans[2],"Geneva");
    strcpy(obj.q[i].ans[3],"The Hague");
    strcpy(obj.q[i].clue,"!");
    obj.q[i].key=3;
    break;

   case 13:
    strcpy(obj.q[i].ques,"The World Trade Organization was established in ______.");
    strcpy(obj.q[i].ans[0],"1980");
    strcpy(obj.q[i].ans[1],"1985");
    strcpy(obj.q[i].ans[2],"1990");
    strcpy(obj.q[i].ans[3],"1995");
    strcpy(obj.q[i].clue,"!");
    obj.q[i].key=4 ;
    break;

   case 14:
    strcpy(obj.q[i].ques,"NATO stands for ______.");
    strcpy(obj.q[i].ans[0],"North American Trade Organisation");
    strcpy(obj.q[i].ans[1],"North Atlantic Treaty Organisation");
    strcpy(obj.q[i].ans[2],"North American Trust Organisation");
    strcpy(obj.q[i].ans[3],"North Atlantic Trade Organisation");
    strcpy(obj.q[i].clue,"!");
    obj.q[i].key=2 ;
    break;

   case 15:
    strcpy(obj.q[i].ques,"Which country, on the map of the world, appears as a 'Long Shoe'?");
    strcpy(obj.q[i].ans[0],"Portugal");
    strcpy(obj.q[i].ans[1],"Italy");
    strcpy(obj.q[i].ans[2],"Greece");
    strcpy(obj.q[i].ans[3],"Hungary");
    strcpy(obj.q[i].clue,"!");
    obj.q[i].key=2 ;
    break;

   case 16:
    strcpy(obj.q[i].ques,"The most number of pyramids can be found in");
    strcpy(obj.q[i].ans[0],"Egypt");
    strcpy(obj.q[i].ans[1],"Peru");
    strcpy(obj.q[i].ans[2],"Spain");
    strcpy(obj.q[i].ans[3],"Sierra Leonne");
    strcpy(obj.q[i].clue,"Not egypt");
    obj.q[i].key=2 ;
    break;

   case 17:
    strcpy(obj.q[i].ques,"The largest consumer of coca cola in the world is ______.");
    strcpy(obj.q[i].ans[0],"USA");
    strcpy(obj.q[i].ans[1],"Iceland");
    strcpy(obj.q[i].ans[2],"Canada");
    strcpy(obj.q[i].ans[3],"India");
    strcpy(obj.q[i].clue,"!");
    obj.q[i].key=2 ;
    break;

   case 18:
    strcpy(obj.q[i].ques,"Which from the following countries does NOT have veto-power?");
    strcpy(obj.q[i].ans[0],"United States");
    strcpy(obj.q[i].ans[1],"United Kingdom");
    strcpy(obj.q[i].ans[2],"Canada");
    strcpy(obj.q[i].ans[3],"France");
    strcpy(obj.q[i].clue,"!");
    obj.q[i].key=3 ;
    break;

   case 19:
    strcpy(obj.q[i].ques,"Largest producer of coffee?");
    strcpy(obj.q[i].ans[0],"India");
    strcpy(obj.q[i].ans[1],"China");
    strcpy(obj.q[i].ans[2],"Brazil");
    strcpy(obj.q[i].ans[3],"Mexico");
    strcpy(obj.q[i].clue,"!");
    obj.q[i].key=3 ;
    break;
 }
}

ofstream fout("GK.TXT",ios::out|ios::binary);
for(i=0;i<20;++i)
fout.write((char*)&obj.q[i],sizeof(obj.q[i]));
fout.close();

cout<<"Success";
getch();
}
