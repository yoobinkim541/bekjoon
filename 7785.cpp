#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(0);
    long long N;
    cin >> N;
    unordered_set<string> s;
    

    for(int i = 0; i < N; i++){
        string name, inout;
        cin >> name >> inout;
        if(inout == "enter"){
            s.insert(name);
        }
        if(inout == "leave"){
            s.erase(name);
        }
    }

    vector<string> v(s.begin(),s.end());
    sort(v.rbegin(),v.rend());

    for(int j = 0; j < v.size(); j++){
        cout << v[j] << '\n';
    }
}