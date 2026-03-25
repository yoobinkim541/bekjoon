#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(0);
    int N,M;
    cin >> N >> M;
    set<string> s;
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        s.insert(str);
    }

    int count = 0;

    for(int i = 0; i < M; i++){
        string str;
        cin >> str;
        if (s.find(str) != s.end()){
            count += 1; 
        }
    }

    cout << count;
}