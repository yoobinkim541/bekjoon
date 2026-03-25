#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;    

void DFS(vector<pair<int,int>> &v,vector<vector<int>> &graph,int start, int &visit, vector<bool> &visited){
    visited[start-1] = true;
    v[start-1].second = visit;
    for(auto next : graph[start]){
        if(!visited[next-1]){
            visited[next-1] = true;
            DFS(v,graph,next, ++visit, visited);
        }
    }
}

int main(void){
    vector<pair<int, int>> v;
    vector<vector<int>> graph;
    
    int N, M, V;
    cin >> N >> M >> V;
    graph.resize(N+1);
    vector<bool> visited(graph.size(), false);

    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i <= N; i++){
        v.push_back({i, 0});
        sort(graph[i].begin(), graph[i].end());
    }
    int visit = 1;
    DFS(v,graph,V,visit,visited);
    sort(v.begin(), v.end(),[](pair<int,int> a, pair<int,int> b){
        return a.first < b.first;
    });
    for(auto a : v){
        cout << a.second << "\n";
    }
    return 0;
}