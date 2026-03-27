#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int input = 0;
        cin >> input;
        vector<int> dp(input+1);
        // N을 만드는 경우의 수 dp[n] = dp[n-1] + dp[n-2] + dp[n-3]
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for(int i = 4; i <= input; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        cout << dp[input] << '\n';
    }

    return 0;
    
}