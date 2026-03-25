#include<iostream>
#include<vector>
using namespace std;

int dp(int X){
    vector<int> dp(X+1, 0);
    dp[1] = 0;
    for(int i = 2; i <= X; i++){
        dp[i] = dp[i-1] + 1;
        if(i % 3 == 0){
            dp[i] = min(dp[i], dp[i/3] + 1);
        }
        if(i % 2 == 0){
            dp[i] = min(dp[i], dp[i/2] + 1);
        }
    }
    return dp[X];

}

int main(void){
    int X;
    cin >> X;
    cout << dp(X);
    return 0;

}