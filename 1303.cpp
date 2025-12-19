#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<char>> & field, vector<vector<bool>> & visited, int & count_parts, int x, int y,char team);
int fourway_x[4] = {1,-1,0,0};
int fourway_y[4] = {0,0,1,-1};
int N,M;

int main (void){
    ios::sync_with_stdio(false); cin.tie(0);
    
    cin >> M >> N;
    vector<vector<char>> field(N,vector<char>(M));
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        int count = 0;
        for(auto a : str){
            field[i][count] = a;
            count += 1;
        }
    }

    vector<vector<bool>> visited (N,vector<bool>(M,false));
    int sum_w = 0, sum_b = 0, count_parts = 0;

    for(int i  = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!visited[i][j] && field[i][j] == 'W'){
                count_parts = 0;
                DFS(field,visited,count_parts,i,j,'W');
                sum_w += count_parts * count_parts;

            }
            else if(!visited[i][j] && field[i][j] == 'B'){
                count_parts = 0;
                DFS(field,visited,count_parts,i,j,'B');
                sum_b += count_parts * count_parts;
            }
        }
    }

    cout << sum_w << ' ' << sum_b;
}

void DFS (vector<vector<char>> & field, vector<vector<bool>> & visited, int & count_parts, int x, int y, char team){
    visited[x][y] = true;
    count_parts += 1;

    int next_x, next_y;
    for(int i = 0; i < 4; i++){
        next_x = x + fourway_x[i];
        next_y = y + fourway_y[i];

        if(next_x >= 0 && next_y >= 0 && next_x < N && next_y < M && !visited[next_x][next_y] &&  field[next_x][next_y] == team){
            DFS(field,visited,count_parts,next_x,next_y,team);
            
        }
    }

}