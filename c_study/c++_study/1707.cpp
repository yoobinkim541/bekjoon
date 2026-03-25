#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool BFS(vector<vector<int>>& graph,vector<int>& color, int start){
    queue<int> q;
    q.push(start);
    color[start] = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(auto a : graph[cur]){
            if(color[a] == 0){
                color[a] = -color[cur];
                q.push(a);
            }
            else if(color[a] == color[cur]){
                return false;
            }
        }
    }
    return true;
}

int main (void){
    int k;
    cin >> k;
    for(int i = 0; i< k; i++){
        int v,e;
        cin >> v >> e;
        vector<vector<int>> graph(v+1);
        vector<int> color(v+1,0); 
        for(int j = 0; j < e; j++){
            int a,b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int o;
        for(o = 1; o <= v; o++){
            if(color[o] == 0){
                    if(!BFS(graph,color,o)){
                    cout << "NO\n";
                    break;
                }
            }
        }
        if(o > v) cout << "YES\n";
    }
}