#include <bits/stdc++.h>
using namespace std;

int fourway_x[4] = {1,-1,0,0};
int fourway_y[4] = {0,0,1,-1};
int R,C,K;
void DFS(int & result, int x, int y,vector<vector<bool>>& visited, int dist,vector<vector<char>> & graph);

int main (void){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> R >> C >> K;
    vector<vector<char>> graph(C,vector<char>(R));

    for(int i = 0; i < R; i++){
        string str;
        cin >> str;
        for(int j = 0; j < str.size(); j++){
            graph[j][i] = str[j];
        }
    }
    vector<vector<bool>> visited(C,vector<bool>(R,false));
    visited[0][R-1] = true;
    int result = 0;
    DFS(result,0,R-1,visited,1,graph);
    cout << result;
}

void DFS(int & result, int x, int y,vector<vector<bool>>& visited, int dist,vector<vector<char>> & graph){
    if(dist == K && x == C-1 && y == 0 ){
        result += 1;
        return;
    }
    
    for(int i = 0; i < 4; i++){
        int next_x = x + fourway_x[i];
        int next_y = y + fourway_y[i];

        if(next_x < 0 || next_y < 0 || next_x >= C || next_y >= R) continue;
        if(graph[next_x][next_y] == 'T' || visited[next_x][next_y]) continue;
        visited[next_x][next_y] = true;
        DFS(result,next_x, next_y,visited,dist+1,graph);
        visited[next_x][next_y] = false;
    }   
}