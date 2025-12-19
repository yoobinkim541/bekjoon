#include <bits/stdc++.h>
using namespace std;

pair<int, int> BFS (vector<vector<int>> & graph);
int x,y;
int fourway_x[4] = {0,0,1,-1};
int fourway_y[4] = {1,-1,0,0};

int main (void){
    ios::sync_with_stdio(false); cin.tie(0);
    
    cin >> x >> y;
    vector<vector<int>> graph(x,vector<int>(y));  
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            int a;
            cin >> a; 
            graph[i][j] = a;
        }
    }

    pair<int, int> p = BFS(graph);
    cout << p.first << '\n' << p.second;

    return 0;
}

pair<int, int> BFS (vector<vector<int>> & graph){
    vector<vector<bool>> visited(x,vector<bool>(y,false));
    queue<pair<int,int>> q;
    int count_group = 0, max_group = 0;

    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){ 
            if(graph[i][j] == 1 && !visited[i][j]){

                visited[i][j] = true;
                count_group += 1;
                q.push({i,j});
                int area = 1;

                while(!q.empty()){
                    int current_x = q.front().first;
                    int current_y = q.front().second;
                    q.pop();

                    for(int o = 0; o < 4; o++){
                        int next_x = fourway_x[o] + current_x;
                        int next_y = fourway_y[o] + current_y;

                     if(next_x >= 0 && next_y >= 0 && next_x < x && next_y < y && !visited[next_x][next_y] && graph[next_x][next_y] == 1){
                            area += 1;
                            visited[next_x][next_y] = true;
                            q.push({next_x,next_y});
                        }
                    } 
                }
                max_group = max(max_group,area);
            }
        }
    }
    return {count_group,max_group};
}