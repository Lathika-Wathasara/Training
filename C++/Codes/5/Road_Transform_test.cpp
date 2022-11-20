#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#include <bits/stdc++.h>


#define edge pair<int, int>

class Graph {
    private:
        // graph is stored as a vector of pairs, where each pair takes the form: <weight, edge>
        vector<pair<int, edge> > G;  // graph 
        vector<pair<int, edge> > T;  // minimum spanning tree for the graph G
        int *parent; // to set parents for Union Find algorithm
        int V;  // number of vertices/nodes in graph
    public:
        Graph(int V);
        void addWeightedEdge(int u, int v, int w);
        vector<pair<int, edge>> findMSTKruskal();
        void Union_set(int u, int v);
        int find_set(int i);
        bool Check_connections(vector<pair<int, edge>> T);
};

Graph::Graph(int V) {
    parent = new int[V];

    // set parent to self initially 
    //i           0 1 2 3 4 5 ...
    //parent[i]   0 1 2 3 4 5 ...
    for (int i = 0; i < V; i++)
        parent[i] = i;

    G.clear();
    T.clear();
}

void Graph::addWeightedEdge(int u, int v, int w) {
  G.push_back(make_pair(w, edge(u, v)));
}

int Graph::find_set(int i){
    if (i== parent[i]){
        return i;
    }
    else{
        return find_set(parent[i]);
    }
}

void Graph::Union_set(int u, int v){
    parent[u] = parent[v];
    // we change the parent of u, into parent of v 
}

// updates T to the minimum spanning tree using Kruskal's algorithm
vector<pair<int, edge>>  Graph::findMSTKruskal() { 
    int i, uRep, vRep;
    sort(G.begin(),G.end()); // sorting according to the weights
    for (i=0; i<G.size(); i++){
        uRep = find_set(G[i].second.first);
        vRep = find_set(G[i].second.second);
        if (uRep != vRep){
            T.push_back(G[i]); // add to the MST
            Union_set(uRep,vRep);
        }
    }
    return T;
}


int get_total(vector<pair<int, edge> > T){
    int Total=0;
    for (int i = 0; i < T.size(); i++){
        Total = Total + T[i].first;
    }
    return Total;
}

bool Graph::Check_connections(vector<pair<int, edge>> T){
    int p= parent[T[0].second.first];
    for (int i=0; i<T.size() ;i++){
        if ((parent[T[i].second.first]!= p)||(parent[T[i].second.second]!= p)){
            cout<<p << parent[T[i].second.first]<<parent[T[i].second.second]<<endl;
            return false;
        }
    }
    return true;
}


int main() {
    int n,m,k;
    cin >> n>>m>>k;

    Graph g(n); //num of cities
    
    int c_1, c_2, w;
    int i =0;
    while (i < m){
        cin >> c_1 >> c_2 >> w;
        g.addWeightedEdge(c_1, c_2, w);
        i=i+1;
    }
    
    vector<pair<int, edge> > T;//for MST
    T = g.findMSTKruskal();
    
    if (g.Check_connections(T)==true){
         for (int i = T.size()-1; i >= -1 ; i--){
            if (get_total(T)<=k){
                cout<< T.size()-1-i;
                break;
            }
            else if (i==-1){
                cout<< -1;
                break;
            }
            else{
               T[i].first = 1;
            } 
        } 
    }
    else{
        cout<< -1;
    }

    return 0;
}