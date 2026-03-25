#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    int N,M;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    cin >> M;
    for (int j = 0; j < M; j++){
        int cnt = 0, target = 0;
        cin >> target;
        int lower = lower_bound(v.begin(), v.end(), target) - v.begin();
        int upper = upper_bound(v.begin(), v.end(), target) - v.begin();
        cnt = upper - lower;
        cout << cnt << " ";
    }

    return 0;
}