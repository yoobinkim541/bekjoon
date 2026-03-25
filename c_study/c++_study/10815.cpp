# include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0); cin.tie(0);
    int N;
    cin >> N;
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < N; i++){
        int num;
        cin >> num;
        v1.push_back(num);
    } 
    
    sort(v1.begin(),v1.end());
    int M;
    cin >> M;
    bool b;

    for (int j = 0; j < M; j++){
        int num;
        cin >> num;
        b = binary_search(v1.begin(),v1.end(),num);
        if (b) cout << 1 << ' ';
        else cout << 0 << ' ';
    }
}