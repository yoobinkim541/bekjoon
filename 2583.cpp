#include <bits/stdc++.h>
using namespace std;

int fourway_x[4] = {0,0,1,-1};
int fourway_y[4] = {1,-1,0,0};

int DFS (vector<vector<bool>> & graph,vector<vector<bool>> & visited,int x, int y);
int M,N,K;

int main(void){
    ios::sync_with_stdio(false); cin.tie(0);
    
    cin >> M >> N >> K;
    vector<vector<bool>> graph(N,vector<bool>(M,false));
    vector<vector<bool>> visited(N,vector<bool>(M,false));
    
    for(int i = 0; i < K; i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int x = x1; x < x2; x++){
            for(int y = y1; y < y2; y++){
                graph[x][y] = true;
            }
        }
    }

    int count_parts = 0;
    vector<int> count_v;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!visited[i][j] && !graph[i][j]){
                int count = DFS(graph,visited, i, j);
                count_parts += 1;
                count_v.push_back(count);
            }
        }
    }

    sort(count_v.begin(),count_v.end());
    cout << count_parts << '\n';
    for (int i : count_v){
        cout << i << ' ';
    }
    
    return 0;

}

int DFS (vector<vector<bool>> & graph,vector<vector<bool>> & visited,int x, int y){
    visited[x][y] = true;
    int count = 1;

    int next_x,next_y;
    for(int i = 0; i < 4; i++){
        next_x = x + fourway_x[i];
        next_y = y + fourway_y[i];

        if(next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && !visited[next_x][next_y] && !graph[next_x][next_y] ){
            count += DFS(graph,visited,next_x,next_y);
        }
    }

    return count;
}
