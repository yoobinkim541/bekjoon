#include <bits/stdc++.h>
using namespace std;


int N,M,K,X;
void BFS(vector<vector<int>> & city,vector<int> & answer);
int main (void){
    cin >> N >> M >> K >> X;
    vector<vector<int>> city(N+1);
    for(int i = 1; i <= M; i++){
        int a,b;
        cin >> a >> b;
        city[a].push_back(b);
    }

    vector<int> answer;
    BFS(city,answer);
    sort(answer.begin(),answer.end());
    
    if(answer.empty()) {
        cout << -1 << '\n';
        return 0;
    }

    else{
        for(int i : answer){
            cout << i << '\n';
        }
        return 0;
    }
}

void BFS(vector<vector<int>> & city,vector<int> & answer){
    vector<int> distance(N+1,-1);
    queue<int> q;
    q.push(X);
    distance[X] = 0;

    while(!q.empty()){
        int current = q.front();
        q.pop();

        for(int next : city[current]){
            if(distance[next] == -1){
                q.push(next);
                distance[next] = distance[current] + 1;
                if(distance[next] == K) answer.push_back(next);
            }
        }
    }
}