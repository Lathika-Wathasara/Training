/*  C++ Program to Take Input as String and Print the String  */

#include<iostream>
#include<string.h>
using namespace std;

int main()
{
        char strng[20] , letter;
        cout<< "Enter string: ";
        cin>> strng;
        cout<< "\n Enter letter: ";
        cin>>letter;

        int l = sizeof(strng);
        int count=0;
        for(int i=0; i<l;i++){
                
                if (strng[i] == letter){count++;}
        }
        cout<<"\nNumber of repitition: "<<count;

        return 0;
}