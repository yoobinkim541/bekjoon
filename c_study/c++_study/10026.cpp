#include <iostream>
#include <vector>
using namespace std;

int n;
void DFS(vector<vector<char>> &graph, vector<vector<bool>> &visited, int x, int y){
    visited[x][y] = true;
    char color = graph[x][y];
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && color == graph[nx][ny]){
            DFS(graph,visited,nx,ny);
        }
    }
}

void oddDFS(vector<vector<char>> &graph, vector<vector<bool>> &odd_visited,int x, int y){
    odd_visited[x][y] = true;
    char color = graph[x][y];
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < n && !odd_visited[nx][ny]){
            if(color == 'B'){
                if(color == graph[nx][ny]){
                    oddDFS(graph,odd_visited,nx,ny);
                }
            }
            else{
                if(graph[nx][ny] == 'R' || graph[nx][ny] == 'G'){
                    oddDFS(graph,odd_visited,nx,ny);
                }
            }
            
        }
    }
}

int main (void){
    cin >> n;
    vector<vector<char>> graph;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        vector<char> row;
        for(auto a : str){
            row.push_back(a);
        }
        graph.push_back(row);
    }

    vector<vector<bool>> visited(n,vector<bool>(n,false));
    vector<vector<bool>> odd_visited(n,vector<bool>(n,false));
    int result = 0, odd_result = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                result += 1;
                DFS(graph,visited,i,j);
            }
            if(!odd_visited[i][j]){
                odd_result += 1;
                oddDFS(graph,odd_visited,i,j);
            }
            
        }
    }

    cout << result << ' ' << odd_result << '\n';
    return 0;
    
}

