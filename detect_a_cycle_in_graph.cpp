#include<bits/stdc++.h>
using namespace std;

bool dfs(int src, int par, vector<int> graph[], int n, bool vis[]){
    vis[src] = 1;
    for(auto it: graph[src]){
        if(!vis[it])
            dfs(it, src, graph, n, vis);
        else if(it != par)
            return true;
    }
}

bool bfs(int src, vector<int> graph[], int n, bool vis[]){
    queue<pair<int, int>> q;
    q.push({src,-1});
    vis[src] = 1;
    while(!q.empty()){
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        for(auto it: graph[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push({it, node});
            }
            else{
                if(par != it)
                    return true;
            }
        }
    }
    return false;
}

int main(){
    vector<int> graph[] = {{}, {2,3}, {1,4}, {1,6,5}, {2,8}, {3,8}, {3,7}, {6}, {4,5}};
    bool vis[9] = {0};
    bool ans = false;
    for(int i=1; i<9; i++){
        if(!vis[i])
            if(bfs(i, graph, 9, vis)){
                ans = true;
                break;
            }
    }
    if(ans)
        cout<<"Yes";
    else 
        cout<<"No";
    return 0;
}