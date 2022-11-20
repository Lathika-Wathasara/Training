#include<iostream> 
using namespace std;

int fibonacy(int n){
    if ((n==0)||(n==1)){
        return n;
    }
    else 
    {
        return (fibonacy(n-1)+fibonacy(n-2));
    }
}

int main(){
    int num;
    cin>> num;
    cout<< fibonacy(num);
    return 0;

}