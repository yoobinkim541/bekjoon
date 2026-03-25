#include <bits/stdc++.h>
using namespace std;

int N,M;
int fourway_x[4] = {1,-1,0,0};
int fourway_y[4] = {0,0,1,-1};
void BFS(vector<vector<int>> & graph, pair<int, int> startpoint);
int main (void){
    cin >> N >> M;
    pair<int, int> startpoint;
    vector<vector<int>> graph(N,vector<int>(M));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> graph[i][j];
            if(graph[i][j] == 2) startpoint = {i,j};
        }
    }

    BFS(graph,startpoint);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

void BFS(vector<vector<int>> & graph, pair<int, int> startpoint){
    vector<vector<bool>> visited(N,vector<bool> (M,false));
    queue<pair<int,int>> q;
    q.push(startpoint);
    visited[startpoint.first][startpoint.second] = true;
    graph[startpoint.first][startpoint.second] = 0;

    while(!q.empty()){
        int current_n = q.front().first;
        int current_m = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int next_n = fourway_x[i] + current_n;
            int next_m = fourway_y[i] + current_m;

            if(next_n >= 0 && next_n < N && next_m >= 0 && next_m < M && !visited[next_n][next_m] && graph[next_n][next_m] == 1){
                q.push({next_n,next_m});
                visited[next_n][next_m] = true;
                graph[next_n][next_m] = graph[current_n][current_m] + 1;
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!visited[i][j] && graph[i][j] == 1) graph[i][j] = -1;
        }
    }
}
