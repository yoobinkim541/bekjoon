#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main(void){
    int N;
    cin >> N;
    vector<int> dp(N+1);
    dp[1] = 1;
    for(int i = 2; i <= N; i++){
        dp[i] = i; // Initialize with the maximum possible count (all 1s)
        for(int j = sqrt(i); j > 0; j--){
            dp[i] = min(dp[i], dp[i-j*j]+1);
        }
    }

    cout << dp[N] << '\n';
    return 0;
}