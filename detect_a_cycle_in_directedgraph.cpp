#include<bits/stdc++.h>
using namespace std;

bool dfs(int src, vector<int> graph[], int vis[], int pathVis[]){
    vis[src] = 1;
    pathVis[src] = 1;
    for(auto it: graph[src]){
        if(!vis[it]){
            if(dfs(it, graph, vis, pathVis))
                return true;
        }
        else if(pathVis[it])
            return true;
    }
    pathVis[src] = 0;
    return false;
}

int main(){
    vector<int> graph[] = {{},{2},{3},{4,7},{5},{6},{},{5},{2,9},{10},{8}};
    int vis[11] = {0};
    int pathVis[11] = {0};
    bool ans = false;
    for(int i=1; i<11; i++){
        if(!vis[i]){
            if(dfs(i, graph, vis, pathVis))
                ans = true;
        }
    }

    // Using BFS 
    // We will apply topological sort using kahn's algorithm and we know that topological sort can only be done on DAG thus if the topological sort contains all the element of the graph that means it does'nt have a cycle and if the number of elements in the topological sort are less than number of vertices in graph thus the graph has a cycle.
    cout<<ans;
    return 0;
}