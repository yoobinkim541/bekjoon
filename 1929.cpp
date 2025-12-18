# include <bits/stdc++.h>
using namespace std;


int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    int M,N;
    cin >> M >> N;
    vector<bool> v (N+1, true);
    v[0] = v[1] = false;
    for(int i = 2; i * i <= N; i++){
        if (v[i] == false) continue;
        for (int j = i*i; j <= N; j += i){
            v[j] = false;
        }
    }
    for(int i = M; i <= N; i++){
        if (v[i] == true) cout << i << '\n';
    }
}
