#include<bits/stdc++.h>
using namespace std;

int drr[] = {0, 0, -1, 1};
int drc[] = {-1, 1, 0, 0};

void bfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &vis){
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    q.push({i, j});
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int d=0; d<4; d++){
            int ro = r + drr[d];
            int co = c + drc[d];
            if(ro>=0 and ro<n and co>=0 and co<m and !vis[ro][co] and grid[ro][co] == '1'){
                vis[ro][co] = 1;
                q.push({ro, co});
            }
        }
    }
}

int main(){
    vector<vector<char>> grid = {{'1','1','0','0','0'},
                                 {'1','1','0','1','0'},
                                 {'0','0','1','0','0'},
                                 {'0','0','0','1','1'}};
    int n = grid.size();
    int m = grid[0].size();
    int ct = 0;
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    for(int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if(!vis[i][j] and grid[i][j] == '1'){
                ct++;
                bfs(i, j, grid, vis);
            }
        }
    }
    cout<<ct<<endl;
    return 0;
}