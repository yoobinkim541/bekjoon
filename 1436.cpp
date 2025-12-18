#include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int count = 1, i = 666;
    while (count <= n){
        if (to_string(i).find("666") != string::npos) count += 1;
        i += 1;
    }
    cout << (i-1);
}