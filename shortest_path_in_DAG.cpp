#include<bits/stdc++.h>
using namespace std;

void toposort(int src, vector<pair<int, int>> graph[], stack<int> &st, vector<bool> &vis){
    vis[src] = 1;
    for(auto it: graph[src]){
        int v = it.first;
        if(!vis[v]){
            toposort(v, graph, st, vis);
        }
    }
    st.push(src);
}

int main(){                       // node weight
    vector<pair<int, int>> graph[] = {{{1,2},{4,1}}, {{2,3}}, {{3,6}}, {}, {{2,2}, {5,4}}, {{3,1}}};
    int N = 6;
    // Apply toposort
    stack<int> st;
    vector<bool> vis(N,0);
    for(int i=0; i<N; i++){
        if(!vis[i])
            toposort(i, graph, st, vis);
    }

    vector<int> dist(N);
    for (int i = 0; i < N; i++)
        dist[i] = 1e9;
    
    while(st.top() != 0){
        dist[st.top()] = -1;
        st.pop();
    }

    // Taking 0 as source point to get distance of every node from 0.
    dist[0] = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        for(auto it: graph[node]){
            int v = it.first;
            int wt = it.second;
            if(dist[node] + wt < dist[v])
                dist[v] = dist[node] + wt;
        }
    }

    for (int i = 0; i < N; i++){
        cout<<dist[i]<<" ";
    }
    
    return 0;
}