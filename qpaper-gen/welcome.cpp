#include <iostream>
#include "functions.h"//Customized header file

using namespace std;

//Module1-Welcome Screen

int welcome()
{
    char l1[25]="QPAPER-GENERATOR";
    centerstring(l1);
    cout<<endl;
    char l2[10]="WELCOME!";
    centerstring(l2);
    cout<<endl;
    cout<<"Please switch to full-screen for better viewing experience...";
    return 0;
}
