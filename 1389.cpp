#include <bits/stdc++.h>
using namespace std;

int N,M;
int BFS(vector<vector<int>> & graph, int start);

int main(void){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N >> M;
    vector<vector<int>> graph(N+1);
    

    for(int i = 0; i < M; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i <= N; i++){
        sort(graph[i].begin(),graph[i].end());
    }

    int min = INT_MAX;
    int result;

    for(int i = 1; i <= N; i++){
        vector<bool> visited (N+1,false);
        int count = BFS(graph,i);

        if(count < min){
            min = count;
            result = i;
        }
    }

    cout << result;

}

int BFS (vector<vector<int>> & graph, int start) {
    vector<int> distance(N+1, -1);
    queue<int> q;

    distance[start] = 0;
    q.push(start);

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for( int next : graph[cur]){
            if(distance[next] == -1){
                distance[next] = distance[cur] + 1;
                q.push(next);
            }
        }
    }
    int sum = 0;
    for(int i = 1; i <= N; i++){
        sum += distance[i];
    }

    return sum;
}