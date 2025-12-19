#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(0);
    int N,M;
    cin >> N >> M;
    vector<string> v;
    unordered_map<string, int> m;

    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        v.push_back(str);
        m[str] = i;
    }

    for(int j = 0; j < M; j++){
        string s;
        cin >> s;

        bool number = all_of(s.begin(),s.end(),::isdigit);
        if(number){
            int i = stoi(s);
            cout << v[i-1] << '\n';
        }

        else{
                cout << m[s] + 1 << '\n';
            }
        }
        
    }
