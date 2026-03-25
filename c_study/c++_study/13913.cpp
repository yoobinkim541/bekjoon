#include <bits/stdc++.h>
using namespace std;

int N,K;

pair<int,vector<int>> BFS ();

int main (void){
    cin >> N >> K;

    auto [a,b] = BFS();

    cout << a << '\n';
    for(int i : b){
        cout << i << ' ';
    }
}

pair<int, vector<int>> BFS (void){
    vector<bool> visited(100001,false);
    vector<int> parent(100001,-1);
    queue<pair<int, int>> q;
    q.push({N,0});
    visited[N] = true;
    parent[N] = N;
 
    while(!q.empty()){
        int x = q.front().first;
        int time = q.front().second;
        q.pop();

        if(x == K){
            vector<int> path; 
            for (int cur = K;; cur = parent[cur]){
                path.push_back(cur);
                if (cur == N) break;
            }
            reverse(path.begin(),path.end());
            return {time, path};
        }

        for(int next : {x-1,x+1,x*2}){
            if (next < 0 || next > 100000) continue;
            if (visited[next]) continue;
            visited[next] = true;
            parent[next] = x;
            q.push({next, time + 1});
        }
    }
}

