#include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> zero(N+2);
        vector<int> one(N+2);
        zero[0] = 1; zero[1] = 0;
        one[0] = 0; one[1] = 1;
            for (int i  = 2; i<= N; i++){
                zero[i] = zero[i-1] + zero[i-2];
                one[i] = one[i-1] + one[i-2];
            }
            cout << zero[N] << " " << one[N] << endl;
        }

    }