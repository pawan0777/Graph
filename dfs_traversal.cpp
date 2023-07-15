#include<bits/stdc++.h>
using namespace std;

bool visited[12] = {0};
vector<int> dfsvec;
vector<int> adjLs[12] = {{}, {2,6}, {1,5,4}, {10,11}, {2,9,10,11}, {2,6}, {1,5,8}, {8,9}, {6,7}, {4,7}, {3,4}, 
                        {3,4}};
                           //  0 1 2 3 4 5  
vector<vector<int>> adjMat = {{0,0,0,0,0,0},
                              {0,0,1,0,1,1},
                              {0,1,0,1,0,0},
                              {0,0,1,0,1,0},
                              {0,1,0,1,0,1},
                              {0,1,0,0,1,0}}; 

void dfsOnAdjLs(int vertex){
    dfsvec.push_back(vertex);
    visited[vertex] = 1;
    for(auto it: adjLs[vertex]){
        if(!visited[it])
            dfsOnAdjLs(it);
    }
}

void dfsOnAdjMat(int vertex){
    dfsvec.push_back(vertex);
    visited[vertex] = 1;
    for (int i = 1; i <= 5; i++){
        if(adjMat[vertex][i] == 1 and !visited[i])
            dfsOnAdjMat(i);
    }
    
}

int main(){
    // dfsOnAdjLs(1);
    dfsOnAdjMat(1);
    for(int it: dfsvec)
        cout<<it<<" ";
    return 0;
}