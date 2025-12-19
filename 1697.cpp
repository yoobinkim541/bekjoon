    #include <bits/stdc++.h>
    using namespace std;

int N,K;

pair<int,int> BFS ();

int main (void){
    cin >> N >> K;
    
    auto [a,b] = BFS();

    cout << a << '\n';
    cout << b;
    
}

pair<int, int> BFS (){
    vector<int> distance(100001,-1);
    vector<int> way(100001,0);
    
    queue<int> q;
    q.push(N);
    distance[N] = 0;
    way[N] = 1;
 
    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int next : {x-1,x+1,x*2}){
            if (0 > next || next > 100000) continue;

            if(distance[next] == -1){
                distance[next] = distance[x] + 1;
                way[next] = way[x];
                q.push(next);
            }

            else if(distance[next] == distance[x] + 1) way[next] += way[x];
        }
    }
    return {distance[K],way[K]};

}