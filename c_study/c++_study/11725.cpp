#include <bits/stdc++.h>
using namespace std;

void BFS (vector<int> & perent, vector<vector<int>> & vertex);
int N;

int main (void){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    
    vector<vector<int>> vertex(N+1);
    for(int i = 1; i < N; i++){
        int a,b;
        cin >> a >> b;
        vertex[a].push_back(b);
        vertex[b].push_back(a);
    }

    for(int i = 1; i <= N; i++){
        sort(vertex[i].begin(),vertex[i].end());
    }

    vector<int> perent(N+1,-1);
    BFS(perent,vertex);

    for(int i = 2; i <= N; i++){
        cout << perent[i] << '\n';
    }

    return 0;

}

void BFS (vector<int> & perent, vector<vector<int>> & vertex){
    queue<int> q;
    q.push(1);
    vector<bool> visited(N+1,false);
    visited[1] = true;

    while(!q.empty()){
        int current = q.front();
        q.pop();

        for(int next : vertex[current]){
            if(!visited[next] && perent[next] == -1){
                perent[next] = current;
                q.push(next);
            }
        }

    }

}