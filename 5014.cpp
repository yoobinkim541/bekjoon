#include <bits/stdc++.h>
using namespace std;


int F,S,G,U,D;
bool BFS (int & answer);
int main (void){
    cin >> F >> S >> G >> U >> D;
    int answer = 0;
    bool result = BFS(answer);

    if(result){
        cout << answer;
    }
    else{
        cout << "use the stairs";
    }

    return 0;
}

bool BFS (int & answer){
    vector<int> visited(F+1,-1);
    queue<int> q;
    q.push(S);
    visited[S] = 0;

    if(S == G) return true;

    while(!q.empty()){
        int current = q.front();
        q.pop();

        if(current == G) {
            answer = visited[G];
            return true;
        }

        for(int next : {current + U, current - D}){
            if(next > 0 && next <= F && visited[next] == -1){
                q.push(next);
                visited[next] = visited[current] + 1; 
            }
        }
    }
    return false;
}