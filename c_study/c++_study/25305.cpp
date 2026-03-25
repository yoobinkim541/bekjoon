# include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0); cin.tie(0);
    int a,b;
    cin >> a >> b;
    vector<int> v;
    for (int i = 0; i < a; i++){
        int n;
        cin >> n;
        v.push_back(n);
    }
    
    sort(v.begin(),v.end());
    cout << v[a - b];

    return 0;
}