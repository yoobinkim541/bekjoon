# include <bits/stdc++.h>
using namespace std;


int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++ ){
        int a,b;
        cin >> b >> a;
        long long combination = 1;
        for (int j = 1; j <= b; j++) {
            combination *= (a - j + 1);
            combination /= j;
        }
        cout << combination << '\n';

    }
}
