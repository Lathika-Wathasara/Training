#include <bits/stdc++.h>

#include <iostream>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'runningMedian' function below.
 *
 * The function is expected to return a DOUBLE_ARRAY.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

double runningMedian(vector<int> a) {
    priority_queue<int> min_q;

    priority_queue<int, vector<int>,greater<int>> max_q;

    double med = a[0];
    max_q.push(a[0]);

    int n = a.size();

    for (int i =1; i<n; i++){
        int x = a[i];
        if (max_q.size() < min_q.size()){
            if (x<med && x<min_q.top()){
                max_q.push(min_q.top());
                min_q.pop();
                min_q.push(x);
            }
            else if (x<med && x > min_q.top()){
                max_q.push(x);
            }
            else{
                max_q.push(x);
            }

            med = (max_q.top() +  min_q.top())/2.0;
        }

        else if (min_q.size() == max_q.size()){
            if (x<med){
                min_q.push(x);
                med= (double)min_q.top(); //converting int to double
            }
            else {
                max_q.push(x);
                med = (double)max_q.top();
            }
        }

        else {
            if (x > med && x>max_q.top()){
                max_q.push(min_q.top());
                min_q.pop();
                min_q.push(x);
            }
            else if (x>med && x < max_q.top()){
                min_q.push(x);
            }
            else{
                min_q.push(x);
            }

            med = (max_q.top() +  min_q.top())/2.0;
        }
    }
    return med/1.0;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a_count_temp;
    getline(cin, a_count_temp);

    int a_count = stoi(ltrim(rtrim(a_count_temp)));

    vector<int> a(a_count);

    for (int i = 0; i < a_count; i++) {
        string a_item_temp;
        getline(cin, a_item_temp);

        int a_item = stoi(ltrim(rtrim(a_item_temp)));

        a[i] = a_item;
    }
    
    double results = runningMedian(a);
    
    cout << results << endl;
    
    /*vector<double> result = runningMedian(a);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";               
        }
    }

    fout << "\n";

    fout.close();*/

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
