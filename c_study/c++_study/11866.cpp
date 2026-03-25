#include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0); cin.tie(0);

    int N,K;
    cin >> N >> K;
    vector<int> v;
    for (int i = 1; i < N+1; i++){
        v.push_back(i);
    }
    vector<int> result;
    int temp = 0;
    while (v.size()){
        temp = (temp + K - 1 ) % v.size();
        result.push_back(v[temp]);
        v.erase(v.begin() + temp);
    }

    cout << '<' << result[0];
    for (int i = 1; i < N; i++){
        cout << ", " << result[i];
    }
    cout << '>';
}