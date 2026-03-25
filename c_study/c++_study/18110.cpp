#include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    int cutline = round((double)n * 0.15);
    int sum = 0;
    
    vector<int> v;
    for (int i  = 0; i < n; i++){
        int num;
        cin >> num;
        v.push_back(num);

    }
    sort(v.begin(),v.end());
    for (int i = cutline; i < n - cutline; i++){
        sum += v[i];
    }

    double result = (double)sum / (n - cutline*2);
    cout << (int)round(result);
}