#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include<windows.h>
#include<chrono>
#include<thread>
#include<fstream>


using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

void centerstring(char*s)   //CENTER ALIGNS STRING
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD NewSBSize;
	NewSBSize = GetLargestConsoleWindowSize(hOut);
	int l=strlen(s);
	int pos=(int)((NewSBSize.X-l)/2);
	for(int i=0;i<pos;i++)
	std::cout<<" ";
	std::cout<<s;
}

static int callback(void *data, int argc, char **argv, char **azColName){
   int i;
  // fprintf(stderr, "%s: ", (const char*)data);

   for(i = 2; i<argc; i++) {//Modified to NOT include column 1 and column 2
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int d;
static int callback_count(void *data, int argc, char **argv, char **azColName){
//To print the number of elements by sql-query

 for(d = 0; d<argc; d++) {
      printf("%s", argv[d] ? argv[d] : "NULL");
   }
   return 0;
}

static int callback_count_noprint(void *data, int argc, char **argv, char **azColName){
//for checking if database if according to the format or not
 for(int u = 0; u<argc; u++) {
      printf("", argv[u] ? argv[u] : "NULL");
   }
   return 0;
}


#endif // FUNCTIONS_H_INCLUDED
