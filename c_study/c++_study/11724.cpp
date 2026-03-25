#include <bits/stdc++.h>
using namespace std;

void DFS (int i,vector<vector<int>> & vertex,vector<bool> & visited,int& result);

int main(void){
    ios::sync_with_stdio(false); cin.tie(0);
    int N,M;
    cin >> N >> M;
    vector<vector<int>> vertex(N+1);
    for(int i = 1; i <= M; i++){
        int a,b;
        cin >> a >> b;
        vertex[a].push_back(b);
        vertex[b].push_back(a);
    }

    for(int i = 1; i <= N; i++){
        sort(vertex[i].begin(),vertex[i].end());
    }

    vector<bool> visited(N+1,false);
    int result = 0;

    for(int i = 1; i <= N; i++){
        if(!visited[i]){
           DFS(i,vertex,visited,result);
           result += 1;
        }
    }

    cout << result;


}

void DFS (int i,vector<vector<int>> & vertex,vector<bool> & visited,int& result){
    visited[i] = true;

    for(int next : vertex[i]){
        if(!visited[next]){
            DFS(next,vertex,visited,result);
        }
    }
}