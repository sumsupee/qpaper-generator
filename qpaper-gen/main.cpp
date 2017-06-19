#include <iostream>
#include <cstdio>
#include <cstdlib>
#include<sstream>
#include "functions.h"//Customized header file
#include "sqlite3.h"
#include <chrono>//for time delay !Requires C++11
#include <thread>//for time delay !Requires C++11
#include<ctime>
#include<fstream>


using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

using namespace std;

int response;
char nm[25];

int home()
{
    char l1[25]="QPAPER-GENERATOR";
    centerstring(l1);
    cout<<endl;
  /*char l2[10]="WELCOME!";
    centerstring(l2);*/
    cout<<endl;
    cout<<"Please switch to full-screen for better viewing experience...";
    cout<<"\n\tChoose the following options:";
    cout<<"\n1. Generate Question Paper";
    cout<<"\n2. Instructions";
    cout<<"\n3. About";
    cout<<"\n4. EXIT\n\t Your response:";

    cin>>response;
    return 0;
}



int main(int argc, char* argv[])
{
  home:  home();

if (response==1)
{
        //Function of qpaper generator

         system("cls");
    cout<<"\n\tEnter the name of your database(with .db extension): ";

    cin>>nm;

    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;
    const char* data = "Callback function called";//not used

   /* Open database */
   rc = sqlite3_open(nm, &db);
   //Database open check
   if( rc ) {
      fprintf(stderr, "\n\t\tCan't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   } else {
      fprintf(stderr, "\n\t\tOpened database successfully\n");
   }
   /**********************/
   std::string command;
   std::ostringstream check;
   //Check if database complies to the format
   check<< "SELECT count(*) FROM QuestionBank";
   command = check.str();
   rc = sqlite3_exec(db, command.c_str(), callback_count_noprint, 0, &zErrMsg);
   if( rc != SQLITE_OK ) {
      fprintf(stderr, "\n\t\tSQL error: %s\n\n", zErrMsg);
      sqlite3_free(zErrMsg);
      sleep_for(nanoseconds(10));
      sleep_until(system_clock::now() + seconds(1));
        cout<<"\n\t\tYour database is not in a readable format! Please have a look at the instructions again!";
        sleep_for(nanoseconds(10));
        sleep_until(system_clock::now() + seconds(3));
        system("cls");
        goto instructions;  //Redirected to Instructions
   }


//Table of Details
   cout<<"\n\tYou have the following number of questions in your database-";
   cout<<"\n\tMarks\tE\tM\tH";
  for(int j=1;j<=10;j++)
    {
    std::ostringstream temp;
    std::ostringstream temp1;
    std::ostringstream temp2;
    std::string command;
   cout<<"\n\t  "<<j<<"  \t";
   temp<< "SELECT count(*) FROM QuestionBank WHERE Marks="<<j<<" AND Difficulty='E' ;";
   command = temp.str();
   rc = sqlite3_exec(db, command.c_str(), callback_count, 0, &zErrMsg);
   cout<<"\t";
   temp1<< "SELECT count(*) FROM QuestionBank WHERE Marks="<<j<<" AND Difficulty='M' ;";
   command = temp.str();
   rc = sqlite3_exec(db, command.c_str(), callback_count, 0, &zErrMsg);
   cout<<"\t";
   temp2<< "SELECT count(*) FROM QuestionBank WHERE Marks="<<j<<" AND Difficulty='H' ;";
   command = temp.str();
   rc = sqlite3_exec(db, command.c_str(), callback_count, 0, &zErrMsg);
   }
   cout<<"\n";
    Repeatif: sleep_for(nanoseconds(10));
    sleep_until(system_clock::now() + seconds(1));
    cout<<"\n\tPlease enter the difficulty of the paper(E/M/H)- ";
    char diff;
    cin>>diff;
    if(diff=='E' || diff=='e' || diff=='M' || diff=='m' || diff=='H' || diff=='h')
    {
        sleep_for(nanoseconds(10));
        sleep_until(system_clock::now() + seconds(1));
        diff=toupper(diff);
    }
    else
    {
        cout<<"\n\tYou entered and undesirable response!\n";
        goto Repeatif;
    }

    cout<<"\n\tEnter the number of questions you need(<=no. of available questions(look at the table): \n";
    cout<<"\n\t\tMarks        Number of Questions";
    int qs[10];//Array for number of qestions!
    for(int k=1;k<=10;k++)
    {
        cout<<"\n\t\t  "<<k<<"                   ";//Hard coded spacing
        cin>>qs[k];
        sleep_for(nanoseconds(1000000));
        sleep_until(system_clock::now() + seconds(0));
    }
    system("cls");

    //QPAPER generated response

    if( rc != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
        cout<<"\n\t\tYour database is not in a readable format! Please have a look at the instructions again!";
        sleep_for(nanoseconds(10));
        sleep_until(system_clock::now() + seconds(3));
        system("cls");
        goto instructions;
   }
   else {
      fprintf(stdout, "\n\t\tOperation done successfully check for file 'qpaper.txt' in the file where the application is stored. \n");
   }

    //Question Paper
 freopen("qpaper.txt","w",stdout);//Prints question in qpaper.txt


    char top[50]="QUESTION-PAPER";
    cout<<"\n\n";
    centerstring(top);
    cout<<endl;

    time_t now=time(0);
    char* dt =ctime(&now);
    centerstring(dt);
    cout<<"\n\n";


    std::ostringstream tem[10];

    int k;
    for( k=1;k<=10;k++)
   {
        if(qs[k]!=0)
        {tem[k]<< "SELECT * FROM QuestionBank WHERE Marks="<<k<<" AND Difficulty='"<< diff <<"' ORDER BY RANDOM() LIMIT "<<qs[k]<<";";
        command = tem[k].str();
        rc = sqlite3_exec(db, command.c_str(), callback, 0, &zErrMsg);
        }
        cout<<"\n";
   }
   cout<<"\n\t\t***END OF QPAPER***";

    sqlite3_close(db);

}


    else if (response==2)
    {
        instructions://function of About page
            system("cls");
            cout<<"\n\t\tInstructions for creating the database:";
            cout<<"\n\t\t\t1. The database should have the following columns in proper order QID(INTEGER), Difficulty(TEXT), Question(TEXT) and Marks(INTEGER).";
            cout<<"\n\t\t\t2. You can use DB Browser for Sqlite, which will be even easier to enter data manually in a database. ";
            cout<<"\n\t\t\t3. There are three levels of difficulty, i.e., E(Easy)/M(Medium)/H(Hard).";
            cout<<"\n\t\t\t4. The program wont run(or may give wrong results) if the database isn't in a proper order.";
            cout<<"\n\t\t\t5. A sample.db has been provided. ";

            cout<<"\n\nThe output will be generated as a .txt file- qpaper.txt, so that if you wish to edit the questions or wish to add more according to your wish you can make changes freely.";
            cout<<"\n\tIMPORTANT! Copy the contents of the text file or duplicate it into another folder as new data will be fed into it once the program re-runs. ";

        //char entry required to go to home
        cout<<"\n\t\tPress any key to go to HOME";
        char yo;
        cin>>yo;
        system("cls");
        goto home;
    }
    else if(response==3)
    {
        system("cls");
        char wel[20]="QPAPER-GENERATOR";
        char abt[6]="ABOUT";
        centerstring(wel);cout<<endl;
        centerstring(abt);cout<<endl;
        cout<<"\n\t\tProgram to generate question papers from a question bank(database-.db file).";
        cout<<"\nThis is program is meant to provide questions randomly as a suggestion and thus it avoids biases and preferences caused when you select questions yourself from a question bank.";
        cout<<"\n\n\t\tCheck for updates or compile the source code on your own, go to: www.github.com/sumsupee/qpaper-generator/ ";
        cout<<"\n\n\t\tCreated by Sumedh Supe, QPAPER-GENERATOR v1.00.00";
        //char entry required to go to home
        cout<<"\n\n\t\tPress any key to go to HOME";
        char yo;
        cin>>yo;
        system("cls");
        goto home;
    }
    else if(response==4)
    {
        exit(0);
    }
    else{
        cout<<"\n\t\tInvalid response! Please re-enter response.";

        cout<<"\n\t\tPress any key to go to HOME";
        char yop;
        cin>>yop;
        goto home;
    }



    return 0;
}

