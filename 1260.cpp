#include <bits/stdc++.h>
using namespace std;

vector<bool> visit_dfs(1001,false);
vector<bool> visit_bfs(1001,false);
vector<int> v[1001]; // 이차원 리스트로 저장 ex) v[1] = {2,3}
vector<int> result_dfs;
vector<int> result_bfs;
int N,M,V;

void DFS (int temp);
void BFS (int temp);

int main(void){
    ios::sync_with_stdio(false); cin.tie(0);
    
    cin >> N >> M >> V;

    for(int i = 0; i < M; i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a); // 양방향 간선
        
    }

    for(int i = 1; i <= N; i++){
        sort(v[i].begin(),v[i].end());
    }

    DFS(V);
    BFS(V);

    for(int j : result_dfs) cout << j << ' ';
    cout << '\n';
    for(int o : result_bfs) cout << o <<' ';

    return 0;
}

void DFS (int V){
    visit_dfs[V] = 1;
    result_dfs.push_back(V);

    for(int i : v[V]){
        if(!visit_dfs[i]) DFS(i);
    }
}

void BFS (int V){
    queue<int> q;
    q.push(V);
    visit_bfs[V] = true;

    while(!q.empty()){
        int next = q.front();
        result_bfs.push_back(next);
        q.pop();

        for(int i : v[next]){
            if(!visit_bfs[i]){
                q.push(i);
                visit_bfs[i] = true;
            }
        }
    }
}