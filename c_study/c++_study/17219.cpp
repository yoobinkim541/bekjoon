#include<iostream>
#include<map>
#include<string>
using namespace std;
int N,M;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    map<string,string> m;
    string site;
    string pw;
    for(int i = 0; i < N; i++){
        cin >> site >> pw;
        m[site] = pw;
    }
    for(int j = 0; j < M; j++){
        string temp;
        cin >> temp;
        cout << m[temp] << '\n';
    }
    return 0;
}