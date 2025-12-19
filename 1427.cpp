# include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0); cin.tie(0);
    int num;
    cin >> num;
    string s = to_string(num);
    sort(s.begin(),s.end(), [](int a, int b) {
        return a > b;
    });
    cout << s;
}