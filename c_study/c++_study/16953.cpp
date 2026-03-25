#include <bits/stdc++.h>
using namespace std;

int BFS(long long a, long long b);

int main (void){
    long long A,B;
    cin >> A >> B;
    int answer = BFS(A,B);
    cout << answer;

    return 0;

}

int BFS (long long a, long long b){
    queue<long long> q;
    map<long long, long long> distance;
    q.push(a);
    distance[a] = 1;

    while(!q.empty()){
        long long current = q.front();
        q.pop();
        if(b == current) return distance[current];

        for(long long next : {current*2,current*10+1}){
            
            
            if(next <= b && !distance.count(next)){
                distance[next] = distance[current] + 1;
                q.push(next);
            }
            
            if(b == next) return distance[next];
        }
    }
    return -1;
}