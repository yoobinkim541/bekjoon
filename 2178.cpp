#include <bits/stdc++.h>
using namespace std;

int fourway_x[4] = {1,-1,0,0};
int fourway_y[4] = {0,0,1,-1};
int N,M;
int BFS(int x, int y,vector<vector<int>> & graph);


int main (void){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N >> M; // N 세로, M 가로
    vector<vector<int>> graph(N,vector<int>(M,0));
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        for(int j = 0; j < str.size(); j++){
            graph[i][j] = int(str[j] - '0');
        }
    }

    int count = BFS(0,0,graph);

    cout << count;

    return 0;
}

int BFS (int x, int y,vector<vector<int>> & graph){
    vector<vector<int>> distance (N,vector<int>(M,0));
    queue<pair<int,int>> q;

    q.push({x,y});
    distance [x][y] = 1;

    while(!q.empty()){
        pair<int,int> cur = q.front();
        int cur_x = cur.first;
        int cur_y = cur.second;
        q.pop();
        
       for(int i = 0; i < 4; i++){
            int nx = cur_x + fourway_x[i];
            int ny = cur_y + fourway_y[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

            if(distance[nx][ny] == 0 && graph[nx][ny] == 1 ){
                distance[nx][ny] = distance[cur_x][cur_y] + 1;
                q.push({nx,ny});    
            }
       } 
    }
    return distance[N-1][M-1];
}