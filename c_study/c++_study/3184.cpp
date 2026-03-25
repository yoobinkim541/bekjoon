#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sheep, wolf;    
int R,C;
void DFS(vector<vector<char>> &matrix, vector<vector<bool>> &visited, int x, int y){
    visited[x][y] = true;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    if(matrix[x][y] == 'v'){
                wolf += 1;
            }
    else if(matrix[x][y] == 'o'){
                sheep += 1;
    }

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < R && ny < C && matrix[nx][ny] != '#' && !visited[nx][ny]){
            DFS(matrix,visited,nx,ny);
        }
    }
}

int main(void){

    cin >> R >> C;
    vector<vector<char>> matrix(R);
    vector<vector<bool>> visited(R,vector<bool>(C,false));
    for(int i = 0; i < R; i++){
        string str;
        cin >> str;
        for(auto a : str){
            matrix[i].push_back(a);
        }
    }

    int all_sheep = 0, all_wolf = 0;

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(matrix[i][j] != '#' && !visited[i][j]){
                sheep = 0, wolf = 0;
                DFS(matrix, visited, i, j);
                if(sheep > wolf){
                    all_sheep += sheep;
                }
                else{
                    all_wolf += wolf;
                }
                
            }
        }
    }
    cout << all_sheep << " " << all_wolf << "\n";
    return 0;
}