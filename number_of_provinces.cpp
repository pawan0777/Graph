#include<bits/stdc++.h>
using namespace std;

// number of connect components in a graph.
vector<vector<int>> graph = {{1,1,0},{1,1,0},{0,0,1}};
bool vis[3] = {0};

void dfs(int vertex){
    vis[vertex] = 1;
    for(int i=0; i<graph.size(); i++){
        if(!vis[i] and graph[vertex][i] == 1)
            dfs(i);
    }
}

int main(){
    int ct = 0;
    for (int i = 0; i < graph.size(); i++){
        if(!vis[i]){
            ct++;
            dfs(i);
        }
    }
    cout<<ct<<endl;
    return 0;
}