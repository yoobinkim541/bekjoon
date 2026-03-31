#include<iostream>
#include<vector>
using namespace std;

int main (void){
    int N;
    cin >> N;
    vector<int> dp (1001);
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 5;
    for(int i = 4; i <= N; i++){
        dp[i] = (dp[i-1] + dp[i-2]*2) % 10007;
    }
    cout << dp[N] << '\n';
}