#include <iostream>
#include <vector>
#include <queue>
using namespace std;
    
bool isPeak;
int N,M;
void FindMountain(vector<vector<bool>>& visited, vector<vector<int>>& graph, int i, int j){
        queue<pair<int,int>> q;
        int dx[8] = {-1,-1,-1,0,0,1,1,1};
        int dy[8] = {-1,0,1,-1,1,-1,0,1};
        q.push({i,j});
        visited[i][j] = true;

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int k = 0; k < 8; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx >= 0 && nx < N && ny >= 0 && ny < M){
                    if(!visited[nx][ny] && graph[nx][ny] == graph[i][j]){
                        visited[nx][ny] = true;
                        q.push({nx,ny});
                    }
                    else if(graph[nx][ny] > graph[i][j]){
                        isPeak = false;
                }
            }
        }
    }
}


int main(void){
    cin >> N >> M;
    vector<vector<int>> graph;
    vector<vector<bool>> visited(N,vector<bool>(M,false));
    for(int i = 0; i < N; i++){
        vector<int> v;
        for(int j = 0; j < M; j++){
            int num;
            cin >> num;
            v.push_back(num);
        }
        graph.push_back(v);
    }

    int count = 0;
    for(int i = 0 ; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!visited[i][j]){ 
                isPeak = true;
                FindMountain(visited,graph,i,j);
                if(isPeak) count++;
            }
        }
    }

    cout << count << "\n";
    return 0;
}