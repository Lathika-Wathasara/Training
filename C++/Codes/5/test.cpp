#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include <unordered_map>



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unordered_map<string, int> umap;
    umap["PI"] = 3.14;
    umap["root2"] = 1.414;
    umap["root3"] = 1.732;
    umap["log10"] = 2.302;
    umap["loge"] = 1.0;
    cout<< umap[0];

    return 0;
}
