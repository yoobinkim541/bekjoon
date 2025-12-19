#include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;

    for (int i  = 0; i < T; i++){
        string temp;
        cin >> temp;
        while (temp.find("()") != string::npos) {
            temp.erase(temp.find("()"), 2);
        }
        if (temp.size() == 0) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    
}