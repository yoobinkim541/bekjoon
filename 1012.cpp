#include <bits/stdc++.h>
using namespace std;


int M,N,K; // 가로길이, 세로길이, 배추의 개수
void DFS(int x, int y, vector<vector<bool>>& arr, vector<vector<bool>>& visit_dfs);

int main(void){
    ios::sync_with_stdio(false); cin.tie(0);
    int T; // 테스트 횟수
    cin >> T;
    
    
     
    for (int i = 0; i < T; i++){
        cin >> M >> N >> K;
        vector<vector<bool>> visit_dfs(M,vector<bool>(N,false));
        vector<vector<bool>> arr(M,vector<bool>(N,false));
        
        for(int j = 0; j < K; j++){
            int x,y;
            cin >> x >> y;
            arr[x][y] = true;
        }

        int result = 0;

        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(arr[i][j] && !visit_dfs[i][j]){
                DFS(i,j,arr,visit_dfs);
                result += 1;
                }
            }
        }
        cout << result << '\n';
    }
}

void DFS (int x, int y, vector<vector<bool>>& arr, vector<vector<bool>>& visit_dfs){
    visit_dfs[x][y] = true;

    int xxx[4] = {0,0,-1,1};
    int yyy[4] = {-1,1,0,0};
    int x1,y1;
    for(int i = 0; i < 4; i++){
        x1 = x + xxx[i];
        y1 = y + yyy[i];
        if (x1 >= 0 && x1 < M && y1 >= 0 && y1 < N) {
            if (arr[x1][y1] && !visit_dfs[x1][y1]) {
                DFS(x1, y1,arr,visit_dfs);
            }
        }
    }
    
}
