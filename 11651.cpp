#include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0); cin.tie(0);
    int N;
    cin >> N;
    vector<vector<int>> v;
    for (int i = 0; i < N; i++){
        int a,b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b) {
    if (a[1] == b[1]) return a[0] < b[0];
    return a[1] < b[1];
    });
    for (const auto& a : v){
        for (int b : a){
            cout << b << ' ';
        }
        cout << '\n';
    }
}