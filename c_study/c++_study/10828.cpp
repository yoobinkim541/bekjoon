#include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0); cin.tie(0);
    int N;
    cin >> N;
    stack<int> s;
    for (int i = 0; i < N; i++){
        string str;
        cin >> str;
        if (str == "push"){
            int X;
            cin >> X;
            s.push(X);
        }

        else if (str == "pop"){
            if (s.size() == 0) cout << -1 << '\n';
            else{
            cout << s.top() << '\n';
            s.pop();
            }   
        }

        else if (str == "size"){
            cout << s.size() << '\n';
        }

        else if (str == "empty"){
            cout << s.empty() << '\n';
        }
        else if (str == "top"){
            if (s.size() == 0) cout << -1 << '\n';
            else cout << s.top() << '\n';
        }
    }
    return 0;
}