# include <bits/stdc++.h>
using namespace std;


int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    long long a_min = 100000, b_min = 100000, a_max = -100000, b_max = -100000;
    for (int i  = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        if (a_max < a) a_max = a;
        if (a_min > a) a_min = a;
        if (b_max < b) b_max = b;
        if (b_min > b) b_min = b;
    }
    cout << (a_max - a_min)*(b_max - b_min);
}