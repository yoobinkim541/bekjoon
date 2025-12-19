#include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    queue<int> v;
    for(int i = 1; i <= n; i++) {
        v.push(i);
    }
    while (v.size() != 1){
        v.pop();
        int temp = v.front();
        v.pop();
        v.push(temp);
    }
    cout << v.front();
}