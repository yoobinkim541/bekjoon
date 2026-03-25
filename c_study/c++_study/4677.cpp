#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m,n;
void DFS(vector<vector<char>> &graph, vector<vector<bool>> &visited,int x, int y){
    visited[x][y] = true;
    int dx[8] = {-1,0,1,-1,1,-1,0,1};
    int dy[8] = {1,1,1,0,0,-1,-1,-1};

    for(int i = 0; i < 8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny] && graph[nx][ny] == '@'){
            DFS(graph,visited,nx,ny);
        }
    }
}

int main (void){
    while(true){
        cin >> m >> n;
        if(m == 0){
            break;
        }
        vector<vector<char>> graph(m);
        for(int i = 0; i < m; i++){
            string str;
            cin >> str;
            for(char c : str){
                graph[i].push_back(c);
            }
        }

        vector<vector<bool>> visited (m,vector<bool>(n,false));
        int pocket = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(graph[i][j] == '@' && !visited[i][j]){
                    pocket += 1;
                    DFS(graph,visited,i,j);
                }
            }
        }
        cout << pocket << '\n';
    }

    return 0;
}