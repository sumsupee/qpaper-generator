#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include<windows.h>
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



#endif // FUNCTIONS_H_INCLUDED
