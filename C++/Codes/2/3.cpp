//Davis'_Staircase-With_Constraints

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include <map>

map<int , int > map_1;              // // Look up table to stor recursive values

int david_stair(int n ){
    
    if (n== 1){
        return 1;
    }
    else if (n ==2){
        return 2;
    }
    else if (n==3){
        return 4;
    }
    else if (n==0){
        return 0;
    }
    else{
        int num_1 = 0;                              // total steps for n
        for (int i =1; i <= 3; i++){
            if (map_1.find(n-i)!= map_1.end()){      //if found
                num_1 = num_1 + map_1[n-i];
            }
            else{
                int num_2 = david_stair(n-i);
                map_1[n-i] = num_2;
                num_1 = num_1 + num_2;
            }
        }
        return num_1;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int n;
    int count;
    long int m = pow(10,10)+7;
    cin>> count;
    //cout<< "Enter" << endl;
    for (int i=0; i<count;i++){
    cin>> n;
    cout<< (david_stair(n)%m) << endl;
    map_1.clear();
    }
    //return 0;
}