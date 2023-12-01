#include<bits/stdc++.h>
using namespace std;
int N = 6;

int main(){
    vector<vector<int>> graph[] = {{{1,4},{2,4}}, {{0,4},{2,2}}, {{0,4},{1,2},{3,3},{4,1},{5,6}}, {{2,3},{5,2}}, {{2,1},{5,3}}, {{2,6},{3,2},{4,3}}};
    vector<int> dist(N, INT_MAX);
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // Min Heap
    // Taking 0 as initial node that will provide the shortest distance of every node from 0
       // dist node
    pq.push({0,0});
    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it: graph[node]){
            int v = it[0];
            int wt = it[1];
            if(dist[v] > dis + wt){
                dist[v] = dis + wt;
                pq.push({dist[v], v});
            }
        }
    }
    for (int i = 0; i < N; i++){
        cout<<dist[i]<<" ";
    }
    
    return 0;
}