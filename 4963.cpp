#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> &arr,vector<vector<bool>> &visited,int,int);
int way_x[8] = {0,0,1,-1,1,1,-1,-1};
int way_y[8] = {1,-1,0,0,1,-1,-1,1};
int w,h;

int main (void){
    ios::sync_with_stdio(false); cin.tie(0);
    
    while(1){
    cin >> h >> w;
    if (w == 0 && h == 0) break;
    vector<vector<int>> arr(w,vector<int>(h));
    vector<vector<bool>> visited(w,vector<bool>(h,false));

    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            int a;
            cin >> a;
            arr[i][j] = a;
        }
    }
    int result = 0;
    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            if(arr[i][j] == 1 && !visited[i][j]){
                DFS(arr,visited,i,j);
                result += 1;
            }

        }
    }
    
    cout << result << '\n';

    }
}

void DFS (vector<vector<int>> &arr,vector<vector<bool>> &visited,int x,int y){
    visited[x][y] = true;
    int next_x,next_y;

    for(int i = 0; i < 8; i++){
        next_x = way_x[i] + x;
        next_y = way_y[i] + y;

        if(next_x >= 0 && next_y >= 0 && next_x < w && next_y < h && visited[next_x][next_y] == false && arr[next_x][next_y] == 1){
            DFS(arr,visited,next_x,next_y);
        }
    }
}