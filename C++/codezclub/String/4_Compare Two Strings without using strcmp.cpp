#include<iostream>
#include<string.h>

using namespace std;

int main(){
    char s1[10],s2[10],i;
    int l1,l2;
    cout<<"Enter first string: ";
    cin>> s1;
    cout<<"\nEnter second string : ";
    cin>> s2;
    l1=sizeof(s1);
    l2=sizeof(s2);
    if (l1 != l2){
        cout<<"\nStrings are not equal.";
    }
    else{
        int check=1;
        for (i=0;i<l1;i++){
            if((s1[i])!=(s2[i])){
              cout<<"\nStrings are not equal.";
              check=0;
              break;  
            }
        }
        if (check==1){
            cout<<"\nStrings are equal.";
        }
    }
return 0;
}