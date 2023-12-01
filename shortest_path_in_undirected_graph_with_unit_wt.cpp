#include<bits/stdc++.h>
using namespace std;
int N = 9;

int main(){
    vector<int> graph[] = {{1,3}, {0,2,3}, {1,6}, {0,1,4}, {3,5}, {4,6}, {2,5,7,8}, {6,8}, {6,7}};
    vector<int> dist(N, INT_MAX);
           // node dist
    queue<pair<int,int>> q;
    // Initially we are taking 0 as the source node
    q.push({0,0});
    dist[0] = 0;
    while(!q.empty()){
        int node = q.front().first;
        int dis = q.front().second;
        q.pop();
        for(auto it: graph[node]){
            if(dist[it] > dis + 1){
                dist[it] = dis + 1;
                q.push({it, dis+1});
            }
        }
    }
    for (int i = 0; i < N; i++){
        if(dist[i] == INT_MAX) // For unreachable nodes
            dist[i] = -1;
        cout<<dist[i]<<" ";
    }
    
    return 0;
}