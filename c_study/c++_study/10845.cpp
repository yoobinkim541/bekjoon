#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    int N;
    cin >> N;
    queue<int> q;
    for (int i = 0; i < N; i++){
        string str;
        cin >> str;
        if (str == "push"){
            int X;
            cin >> X;
            q.push(X);
        }

        else if(str == "pop"){
            if (q.size() == 0) cout << -1 << '\n';
            else{
                cout << q.front() << '\n';
                q.pop();
            }
        }

        else if(str == "size") cout << q.size() << '\n';

        else if(str == "empty"){
            if (q.size() == 0) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        
        else if(str == "front"){
            if (q.size() == 0) cout << -1 << '\n';
            else cout << q.front() << '\n';
        }

        else if (str == "back"){
            if (q.size() == 0) cout << -1 << '\n';
            else cout << q.back() << '\n';
        }
    }

    return 0;
}