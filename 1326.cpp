#include <bits/stdc++.h>
using namespace std;

int N;
int BFS(vector<int> & v,int a, int b);

int main (void){
    cin >> N;
    vector<int> v(N+1);
    for(int i = 1; i <= N; i++){
        int n;
        cin >> n;
        v[i] = n;
    } 
    int a,b;
    cin >> a >> b;
    int answer = BFS(v,a,b);
    cout << answer;
}

int BFS(vector<int> & v,int start, int end){
    queue<int> q;
    q.push(start);
    vector<int> visited(N+1,-1);
    visited[start] = 0;

    while(!q.empty()){
        
        int current = q.front();
        q.pop();

        for(int next = current + v[current]; next <= N; next += v[current]){
            if(visited[next] != -1) continue;
            visited[next] = visited[current] + 1;
            if(next == end) return visited[next];
            q.push(next);
        }

        for(int next = current - v[current]; next >= 1; next -= v[current]){
            if(visited[next] != -1) continue;
                q.push(next);
                visited[next] = visited[current] + 1;
                if(next == end) return visited[next];
                q.push(next);
            
        }
    }
    return -1;
}