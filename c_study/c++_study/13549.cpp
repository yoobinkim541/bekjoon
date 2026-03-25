#include <bits/stdc++.h>
using namespace std;

int N,K;

int BFS (void);

int main (void){
    cin >> N >> K;
    
    auto a = BFS();

    cout << a;

    return 0;
    
}

int BFS (void){
    vector<int> distance(100001,1000000);
    
    deque<int> dq;
    dq.push_back(N);
    distance[N] = 0;
 
    while(!dq.empty()){
        int x = dq.front();
        dq.pop_front();

        if (x == K) break;

        int nx = x*2;
        if(nx <= 100000 && distance[x] < distance[nx]){
            distance[nx] = distance[x];
            dq.push_front(nx);
        }

        for(int next : {x-1,x+1}){
            if (0 > next || next > 100000) continue;

            if(distance[next] > distance[x] + 1){
                distance[next] = distance[x] + 1;
                dq.push_back(next);
            }
        }
    }
    return distance[K];

}