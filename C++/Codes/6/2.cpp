#include <bits/stdc++.h>
#include <vector>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'prims' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY edges
 *  3. INTEGER start
 */


bool find_(vector<int> finished_nodes, int v){
    int finished_nodes_size =finished_nodes.size();
    for (int i=0; i<finished_nodes_size; i++){
        if (v==finished_nodes[i]){
            return true;
        }
    }
    return false;
}

int find_ind(vector<int> unfinished_nodes, int v){
    int unfinished_nodes_size =unfinished_nodes.size();
        
    for (int i=0; i<unfinished_nodes_size; i++){
        if (v==unfinished_nodes[i]){
            return i;
        }
}
    return 0; // check 
}

void make_unfinished(vector<vector<int>> edges, vector<int> unfinished_nodes, int start){
    int  edges_size =  edges.size();
    for (int i=0; i< edges_size; i++){
        if ((find_(unfinished_nodes, edges[i][0])== false)&& (edges[i][0]!= start)){
            unfinished_nodes.push_back(edges[i][0]);
        }
        else if ((find_(unfinished_nodes, edges[i][1])== false)&& (edges[i][0]!= start)){
             unfinished_nodes.push_back(edges[i][1]);
        }
    }
    
}

int prims(int n, vector<vector<int>> edges, int start) {
    vector<int> finished_nodes;
    vector<int> unfinished_nodes;
    finished_nodes.push_back(start);
    make_unfinished(edges,unfinished_nodes,start);
    
    /*for (int i=0; i<n; i++){
        if (i!= start){
        unfinished_nodes.push_back(i);}
    }  */
    int minimum_total_w=1000; 
    //vector<vector<int>> min_edges ;
    
    while (true){
        int min_edge;
        int min_edge_w = 10000;
        int v;
        int finished_nodes_size =finished_nodes.size();
        int  edges_size =  edges.size();
        
        for (int i=0; i<finished_nodes_size; i++){
            for (int u =0; u<edges_size; u++){
                if ((finished_nodes[i]==edges[u][0])&& (edges[u][2]<min_edge_w) && (find_(finished_nodes,edges[u][1]) == false)){
                    min_edge_w= edges[u][2];
                    min_edge = u;
                    v = edges[u][1];
                }
                else if ((finished_nodes[i]==edges[u][1])&& (edges[u][2]<min_edge_w) && (find_(finished_nodes,edges[u][0]) == false)){
                    min_edge_w= edges[u][2];
                    min_edge = u;
                    v = edges[u][0];
                }
            }
            }
        minimum_total_w = minimum_total_w + min_edge_w;
        int ind_v = find_ind(unfinished_nodes,v);
        
        /*cout<< v<< endl;
        int unfinished_nodes_size = unfinished_nodes.size();
        for (int i=0; i<unfinished_nodes_size; i++){
            cout<< unfinished_nodes[i]<< endl;
        }*/
        
        unfinished_nodes.erase(unfinished_nodes.begin()+ ind_v); // check here
        finished_nodes.push_back(v);
        edges.erase(edges.begin()+ min_edge);
        
        if (finished_nodes_size +1 == n){
            return minimum_total_w;
        }
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<vector<int>> edges(m);

    for (int i = 0; i < m; i++) {
        edges[i].resize(3);

        string edges_row_temp_temp;
        getline(cin, edges_row_temp_temp);
        
        vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int edges_row_item = stoi(edges_row_temp[j]);

            edges[i][j] = edges_row_item;
        }
    }

    string start_temp;
    getline(cin, start_temp);

    int start = stoi(ltrim(rtrim(start_temp)));
    
    
    int result = prims(n, edges, start);

    fout << result << "\n";

    fout.close();

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
