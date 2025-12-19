#include <bits/stdc++.h>
using namespace std;

void DFS (vector<vector<int>> & arr, vector<vector<bool>> & visited, int x, int y, int);
int fourway_x[4] = {0,0,1,-1};
int fourway_y[4] = {1,-1,0,0};
int N;


int main (void){
    ios::sync_with_stdio(false); cin.tie(0);
    
    cin >> N;
    vector<vector<int>> arr(N,vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int num;
            cin >> num;
            arr[i][j] = num;
        }
    }

    vector<vector<bool>> visited(N,vector<bool>(N,false));
    int count_max = 0;
    int count = 0;

    for(int i = 0; i <= 100; i++){
        
        for(int j = 0; j < N; j++){
            fill(visited.begin(), visited.end(), vector<bool>(N, false));
        }

        count = 0;
        for(int x = 0; x < N; x++){
            for(int y = 0; y < N; y++){
                if(arr[x][y] > i && !visited[x][y]){
                    DFS(arr,visited,x,y,i);
                    count += 1;
                } 
            }
        }
        if(count > count_max) count_max = count;

    }
    cout << count_max;
    
    return 0;
}

void DFS (vector<vector<int>> & arr, vector<vector<bool>> & visited, int x, int y, int hight){
    visited[x][y] = true;

    int next_x,next_y;
    for(int i = 0; i < 4; i++){
        next_x = x + fourway_x[i];
        next_y = y + fourway_y[i];

        if(next_x >= 0 && next_y >= 0 && next_x < N && next_y < N && !visited[next_x][next_y] && arr[next_x][next_y] > hight){
            DFS(arr,visited,next_x,next_y,hight);
        }
    }
}