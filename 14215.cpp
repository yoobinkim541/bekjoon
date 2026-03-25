# include <bits/stdc++.h>
using namespace std;


int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> v;
    for (int i = 0; i < 3; i++){
        int n;
        cin >> n;
        v.push_back(n);
    }

    sort(v.begin(),v.end());
    int sum = v[0] + v[1];
    if (sum <= v[2]){
        v[2] = sum - 1;
    }
    int length = v[2] + sum;
    cout << length;
}