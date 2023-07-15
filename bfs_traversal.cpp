#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adjMat = {{0,0,0,0,0,0},
                              {0,0,1,0,1,1},
                              {0,1,0,1,0,0},
                              {0,0,1,0,1,0},
                              {0,1,0,1,0,1},
                              {0,1,0,0,1,0}}; 
bool visited[6] = {0};
vector<int> vec;

void bfsOnAdjMat(int vertex){
    queue<int> q;
    q.push(vertex);
    visited[vertex] = 1;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        vec.push_back(curr);
        for(int i=1; i<adjMat.size(); i++){
            if(adjMat[curr][i] == 1 and !visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

void bfsOnAdjLs(vector<int> graph[], vector<int> &bfsvec, int strt){
    bool visited[12] = {0};
    queue<int> q;
    q.push(strt);
    visited[strt] = 1;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        bfsvec.push_back(curr);
        for(auto it: graph[curr]){
            if(!visited[it]){
                visited[it] = 1;
                q.push(it);
            }
        }
    }
}

int main(){
    vector<int> adjLs[12] = {{}, {2,6}, {1,5,4}, {10,11}, {2,9,10,11}, {2,6}, {1,5,8}, {8,9}, {6,7}, {4,7}, {3,4}, {3,4}};
    vector<int> bfsvec;
    bfsOnAdjLs(adjLs, bfsvec, 3);
    bfsOnAdjMat(1);
    for(int i: vec)
        cout<<i<<" ";
    return 0;
}