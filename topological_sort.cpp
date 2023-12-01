// Definition:-
// Topological sorting is a linear ordering defined for vertices of only a directed acyclic graph (DAG). For every directed edge (u,v), vertex u comes before vertex v in the topologically sorted order. This means that topological sorting for a cyclic graph is not possible.

#include<bits/stdc++.h>
using namespace std;

void dfs(int src, vector<int> graph[], stack<int> &st, bool vis[]){
    vis[src] = 1;
    for(int it: graph[src]){
        if(!vis[src])
            dfs(it, graph, st, vis);
    }
    st.push(src);
}

int main(){
    vector<int> graph[] = {{},{},{3},{1},{0,1},{0,2}};
    stack<int> st;
    bool vis[6] = {0};
    for(int i=0; i<6; i++){
        if(!vis[i])
            dfs(i, graph, st, vis);
    }
    vector<int> vec;
    while(!st.empty()){
        vec.push_back(st.top());
        st.pop();
    }
    for(int it: vec)
        cout<<it<<" ";

    // Using BFS | Kahn's Algorithm
    queue<int> q;
    vector<int> indegree(6, 0);
    for(auto it: graph){
        for(auto i: it)
            indegree[i]++;
    }
    for(int i=0; i<6; i++){
        if(indegree[i] == 0)
            q.push(i);
    }
    vector<int> ans;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(int it: graph[node]){
            indegree[it]--;
            if(indegree[it]==0)
                q.push(it);
        }
    }
    for(int it: ans)
        cout<<it<<" ";

    return 0;
}