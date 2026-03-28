#include<iostream>
#include<vector>
using namespace std;

int main(void){
    int N;
    cin >> N;
    vector<long long> dp(N+1);
    if(N == 1){
        cout << 1 <<'\n';
        return 0;
    }
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= N; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }
    cout << dp[N] << '\n';
}