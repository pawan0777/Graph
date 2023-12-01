// A Graph can only be bipartite when it is a linear graph(means it has no cycle) and is cycle exists the cycle length must be even but if the cycle length is odd then the graph cannot be bipartite.
#include<bits/stdc++.h>
using namespace std;

bool dfs(int src, int col, vector<int> graph[], int color[]){
    color[src] = col;
    for(auto it: graph[src]){
        if(color[it] == -1){
            if(dfs(it, !col, graph, color) == false) return false;
        }
        else if(color[it] == col)
            return false;
    }
    return true;
}

int main(){
    vector<int> graph[] = {{}, {2}, {1,3,4,5}, {2}, {2,6}, {2,8}, {4,7}, {6,8,9}, {5,7}, {7}}; // Bipartite Graph
    // vector<int> graph[] = {{}, {2}, {1,3,4,5}, {2}, {2,6}, {2,7}, {4,7}, {5,6,9}, {}, {7}}; // Not a Bipartite Graph
    bool ans = true;
    int color[10];
    for (int i = 0; i < 10; i++)
        color[i] = -1;

    // Using BFS
    // queue<int> q;
    // color[1] = 0;
    // q.push(1);
    // while(!q.empty()){
    //     int node = q.front();
    //     q.pop();
    //     for(auto it: graph[node]){
    //         if(color[it] == -1){
    //             color[it] = !color[node];
    //             q.push(it);
    //         }
    //         else if(color[it] == color[node]){
    //             ans = false;
    //             break;
    //         }
    //     }
    // }

    // Using DFS
    for(int i=1; i<10; i++){
        if(color[i] == -1){
            if(dfs(i, 0, graph, color) == false){
                ans = false;
                break;
            }
        }
    }

    if(ans)
        cout<<"Bipartite Graph!";
    else 
        cout<<"Not a Bipartite Graph!";
    return 0;
}