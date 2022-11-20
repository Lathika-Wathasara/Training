#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int Reminder(int num, int devisor)  //reminder of negetive of positive integer
{
    if(num >= 0)
    {
        return num % devisor;
    }
    float temp = (float)num / (float)devisor;
    int rounded_num = floor(temp);
    return num - (rounded_num * devisor);
}

// creating the slot machine values 
void get_value(int n,int &y, int m, int d, int vec[]){
    int A=y;
    int B=m;
    int C=d;
    for(int i =0; i < n ; i++ ){
       vec[i]= A+B+C;

       A= Reminder((A*A+2*B+1),10007)-5000;
       B= Reminder((B*B+2*y-1),10007)-5000;
       C= Reminder(vec[i],121)-60;
       y=A;
   }
}


// taking min
int max(int n1, int n2, int n3) { return max(max(n1, n2), n3); }

// maximum of subarray sums
int max_joint_sum(int vec[], int l, int m, int h){
    int sum = 0;
    int l_sum = -2147483648;
    for (int i = m; i >= l; i--) {
        sum = sum + vec[i];
        if (sum > l_sum)
            l_sum = sum;}
    sum = 0;
    int R_sum = -2147483648;
    for (int p = m + 1; p <= h; p++) {
        sum = sum + vec[p];
        if (sum > R_sum)
            R_sum = sum;
    }
    return max(l_sum + R_sum, l_sum, R_sum);
}
 
int max_sum(int vec[], int L, int H){
    if (H == L)
        return vec[L];
    int M = (L + H) / 2;
    return max(max_sum(vec, L, M),
               max_sum(vec, M + 1, H),
               max_joint_sum(vec, L, M, H));
}

int main() {
    int n;
    cin >> n;
    int Y, M, D;
    scanf("%d %d %d", &Y, &M, &D);
    int vec[n];
    get_value(n,Y,M,D,vec);
    int MaxSum = max_sum(vec, 0, n-1);
    cout <<  MaxSum;
    return 0;}