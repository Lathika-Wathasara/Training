#include <iostream>
#include <vector>



using namespace std;

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
        void findMSTKruskal();
        void printMST();
        void Union_set(int u, int v);
        int find_set(int i);
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
void Graph::findMSTKruskal() { 
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


}

void Graph::printMST() {
    int minCost = 0;
    cout << "Edge : " << "Weight" << endl;
    for (int i = 0; i < T.size(); i++) {
        cout << T[i].second.first << " - " << T[i].second.second << " : " << T[i].first << endl;
        minCost += T[i].first;
    }
    cout << "Minimum Cost = " << minCost << endl;
}

int main() {
    int numVertices;
    cin >> numVertices;

    Graph g(numVertices);
    
    int u, v, w;
    cin >> u;
    while (u != -1) {
        cin >> v >> w;
        g.addWeightedEdge(u, v, w);
        cin >> u;
    }
 
    g.findMSTKruskal();
    g.printMST();
    return 0;
}