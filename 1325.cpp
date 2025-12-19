#include <bits/stdc++.h>
using namespace std;

int N,M;
int DFS (vector<vector<int>> & v,vector<bool> &, int i);

int main(void){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N >> M;
    vector<int> cnt_vertex;
    vector<vector<int>> v(N+1);

    for(int i = 0; i < M; i++){
        int a,b;
        cin >> a >> b;
        v[b].push_back(a);
    }

    for(int i = 0; i < N; i++){
        sort(v[i].begin(),v[i].end());
    }

    int max = 0;

    for(int i = 1; i <= N; i++){
        vector<bool> visited (N+1,false);
        int cnt = DFS(v,visited,i);
        if(cnt > max){
            max = cnt;
            cnt_vertex.clear();
            cnt_vertex.push_back(i);
        }
        else if(cnt == max){
            cnt_vertex.push_back(i);
        }
    }

    for(int i : cnt_vertex){
            cout << i << ' ';
    }
}

int DFS (vector<vector<int>> & v, vector<bool> & visited,int i){
    int count_parts = 1;
    visited[i] = true;

    for(int a : v[i]){
        if(!visited[a]){
            count_parts += DFS(v,visited,a);
        }
    }
    return count_parts;
}