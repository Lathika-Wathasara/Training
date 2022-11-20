#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include <unordered_map>
#include  <bits/stdc++.h>
#include <string>

unordered_map<string, int> remove_space_and_add(char str[], unordered_map<string, int> map_1)
{   int i=0;
    char *token = strtok(str, " ");
   
    while (token != NULL)
    {   map_1[token]=i;
        i=i+1;
        //printf("%s\n", token);
        token = strtok(NULL, " ");
    }
    return map_1;
}

void find_word(char str[], unordered_map<string, int> map_1,int n)
{   
    char *token = strtok(str, " ");
    int i=1;
    while (token != NULL)
    {   if(map_1.find(token)== map_1.end()){
        cout<<"No";
        return;
        }
        else if(i==n){
            cout<<"Yes";
        }
        //printf("%s\n", token);
        token = strtok(NULL, " ");
        i=i+1;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int m,n;
    cin >>m>>n;
    unordered_map<string, int> map_1; //map for magazine
   

    char magazine[200],letter[200];
    
    cin.getline(magazine, 200,'\n');
    cin.getline(magazine, 200,'\n');
    
    cin.getline(letter, 200,'\n');
    
    map_1=remove_space_and_add(magazine,map_1);
    
    find_word(letter,map_1,n);
    

    return 0;
}
