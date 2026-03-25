#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M,K;
int result = 0;
void DFS(vector<vector<bool>> &visited, vector<vector<char>> &graph, int x, int y){
    visited[x][y] = true;
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    

    for(int i = 0; i < 4; i++){
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        if(next_x >= 0 && next_x < N && next_y >= 0 && next_y < M){
            if(!visited[next_x][next_y] && graph[next_x][next_y] == '#'){
                result += 1;
                DFS(visited,graph,next_x,next_y);
            }
        }
    }


}

int main(void){
    
    cin >> N >> M >> K;
    vector<vector<char>> graph(N);
    vector<char> row(M,'.');
    for(int i = 0; i < N; i++){
        graph[i] = row;
    }
    for(int i = 0; i < K; i++){
        int a,b;
        cin >> a >> b;
        graph[a-1][b-1] = '#';
    }

    vector<vector<bool>> visited(N, vector<bool>(M, false));
    
    int max_result = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(graph[i][j] == '#' && !visited[i][j]){
                result = 1;
                DFS(visited,graph,i,j);
                max_result = max(max_result, result);
            }
        }
    }

    cout << max_result << "\n";
    return 0;
}