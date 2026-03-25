#include<iostream>
#include<vector>
using namespace std;
int N;

int main(void){
    cin >> N;
    vector<int> v(N+1,0);
    for(int i = 1; i <= N; i++){
        cin >> v[i];
    }
    
    vector<int> dp(N+1,0);
    dp[1] = v[1];
    dp[2] = v[1] + v[2];
    dp[3] = max(v[1] + v[3], v[2] + v[3]);
    
    for(int i = 4; i <= N; i++){
        dp[i] = max(v[i] + dp[i-2] , v[i] + v[i-1] + dp[i-3]);
    }
    cout << dp[N] << '\n';
}

