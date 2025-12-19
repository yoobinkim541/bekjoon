#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(0);
    long long N,M;
    cin >> N >> M;
    unordered_set<string> s;

    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        s.insert(str);
    }

    vector<string> v;
    long long count = 0;

    for(int j = 0; j < M; j++){
        string str;
        cin >> str;
        auto a = s.count(str);
        if (a){
            v.push_back(str);
            count += 1;
        } 
    }
    sort(v.begin(),v.end());
    cout << count << '\n';
    for(string s : v){
            cout << s << '\n';
    }    
}