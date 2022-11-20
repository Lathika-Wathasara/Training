#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    vector<int>  order;
    vector<int> cook;
    vector<int> waiting_time;
    vector<int> index;
    vector<int> mp;
   // map<int, int> mp_1;
    priority_queue <int, vector<int>, greater<int>> pq_1 ;  

    int ppl;
    
    cin>> ppl;
    

    int o,c;
    for (int i =0; i<ppl; i++){

        
        cin>> o;
        cin>> c;
    
        order.push_back(o);
        cook.push_back(c);
        waiting_time.push_back(0);
        index.push_back(i);
        mp.push_back(o+c);
       
        pq_1.push(o+c);
    }
int time =0;

    while (index.size()!=0){
        int t = pq_1.top();
        time = time +t;
        int serve_index=1000;
        pq_1 = priority_queue <int, vector<int>, greater<int>>(); // reset it
        int len= index.size();
        vector<int> index_2;
        for (int i =0; i< len; i++){
            if (mp[index[i]]==t){
                serve_index=index[i];
            }
            waiting_time[index[i]]= waiting_time[index[i]] +t;  // should reduce the order time
            
            if (serve_index!= index[i]){
                index_2.push_back(index[i]);
                if (time>order[index[i]]){
                    mp[index[i]]= cook[index[i]];
                }
                else{
                   mp[index[i]]= cook[index[i]] + order[index[i]]- time; 
                }
                pq_1.push(mp[index[i]]);
            }
        }
        index= index_2;

    }

    int avg=0;
    for (int i=0; i<ppl; i++){
        avg = avg + waiting_time[i]- order[i];
    }
    avg = avg/ppl;
    cout<< avg<< endl;
    
    //return 0;
}
