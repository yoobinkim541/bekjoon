#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main(void){
    int M,N;
    cin >> M >> N;
    //  그래프를 저장하는 2차원 벡터, 0으로 초기화
    vector<vector<int>> graph(N,vector<int>(M,0));
    // 토마토가 익는 날짜를 저장하는 2차원 벡터, -1로 초기화
    vector<vector<int>> dist(N,vector<int>(M,-1));
    queue<pair<int,int>> q;
    // 그래프 입력
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> graph[i][j];
            if(graph[i][j] == 1){
                q.push({i,j});
                dist[i][j] = 0;
            }
        }
    }

    // BFS를 통해 토마토가 익는 날짜 계산
    int result = 0;
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M){
                if(graph[nx][ny] == 0 && dist[nx][ny] == -1){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }
    }

    // 모든 토마토가 익었는지 확인
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(graph[i][j] == 0 && dist[i][j] == -1){
                cout << -1 << endl;
                return 0;
            }
            result = max(result, dist[i][j]);
        }
    }

    cout << result << endl;
    return 0;

}