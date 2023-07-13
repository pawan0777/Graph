#include<bits/stdc++.h>
using namespace std;

// Consider the graph:
/*
1--2
|  | \
|  |  5
|  | /
3--4

The Graph contions 5 Nodes and 6 Edges
*/

int main(){
    // We can represent graph in two ways:
    // 1. Adjacency Matrix
                           // 0 1 2 3 4 5
    int matrixGraph[6][6] = {{0,0,0,0,0,0}, // 0
                             {0,0,1,1,0,0}, // 1
                             {0,1,0,0,1,1}, // 2
                             {0,1,0,0,1,0}, // 3
                             {0,0,1,1,0,1}, // 4
                             {0,0,1,0,1,0}};// 5
    // 2. Adjacency list
    vector<int> listGraph[6] = {{},       // 0
                                {2,3},    // 1
                                {1,4,5},  // 2
                                {1,4},    // 3
                                {3,2,5},  // 4
                                {2,4}};   // 5
    return 0;
}