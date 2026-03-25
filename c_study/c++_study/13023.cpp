#include<iostream>
#include<vector>
using namespace std;
int N, M; //  N : 사람 수 / M : 친구 관계 수

void DFS(vector<vector<int>> & graph,vector<bool> &visited,bool& result, int depth, int cur){
    if(depth == 4){
        result = true;
        return;
    }
    visited[cur] = true;
    for(auto next : graph[cur]){
        if(!visited[next]){
            DFS(graph,visited,result,depth+1,next);
        }
    }
    visited[cur] = false;

}

int main (void){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    vector<bool> visited(N,false);
    vector<vector<int>> graph(N);
    for(int i = 0; i < M; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        graph[temp1].push_back(temp2);
        graph[temp2].push_back(temp1);
    }

    bool result = false;
    for(int i = 0; i < N; i++){
        if(result) break;
        DFS(graph,visited,result,0,i);
    }
    if(result) cout << 1;
    else cout << 0;
    return 0;
    

}