#include <bits/stdc++.h>
using namespace std;

void DFS (vector<vector<int>> &,vector<vector<bool>> &,int i,int j, int&);
int fourways_x[4] = {0,0,1,-1};
int fourways_y[4] = {1,-1,0,0};
int N;

int main (void){
    
    cin >> N;
    vector<vector<int>> map(N,vector<int>(N)); 
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        int cnt = 0;
        for(char s : str){
            map[i][cnt] = s - '0';
            cnt += 1;
        }
    }

    vector<vector<bool>> visited (N,vector<bool>(N,false));
    int cnt_connectedparts = 0, cnt_parts = 0;
    vector<int> parts_num;


    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if (!visited[i][j] && map[i][j] == 1){
                cnt_parts = 1;
                DFS(map,visited,i,j,cnt_parts);
                parts_num.push_back(cnt_parts);
                cnt_connectedparts += 1;
            }
        }
    }
    cout << cnt_connectedparts << '\n';

    sort(parts_num.begin(),parts_num.end());

    for(auto a : parts_num){
        cout << a << '\n';
    }

    return 0;
}

void DFS (vector<vector<int>> & map,vector<vector<bool>> & visited,int i,int j, int& cnt_parts){
    visited[i][j] = true;

    int next_x,next_y;
    for(int o = 0; o < 4; o++){
        next_x = i + fourways_x[o];
        next_y = j + fourways_y[o];

        if(next_x >= 0 && next_y >= 0 && next_x < N && next_y < N && visited[next_x][next_y] == false && map[next_x][next_y] == 1){
            cnt_parts += 1;
            DFS(map,visited,next_x,next_y,cnt_parts);
        }
    }
}   