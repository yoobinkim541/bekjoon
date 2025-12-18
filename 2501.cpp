# include <bits/stdc++.h>
using namespace std;


int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    int N,K;
    cin >> N >> K;
    int count = 0;
    for (int i = 1; i <= N; i++){
        if (N % i == 0) count += 1;    
        if (count == K) {
            cout << i;
            break;
        }
    }
    if (count < K) cout << 0;
}