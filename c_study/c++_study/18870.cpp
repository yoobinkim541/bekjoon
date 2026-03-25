#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(0);
    int N;
    cin >> N;
    vector<int> v;

    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    set<int> s;
    for(int i : v){
        s.insert(i);
    }

    vector<int> set_v;
    for(int i : s){
        set_v.push_back(i);
    }

    unordered_map<int, int> compressed;
    for (int i = 0; i < set_v.size(); i++){
        compressed[set_v[i]] = i;
    }

    for(int i : v){
        cout << compressed[i] << ' ';
    }
}