#include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0); cin.tie(0);

    int n, count = 0;
    cin >> n;
    while (n >= 0){ // N이 음수면 -1 출력
        if (n % 5 == 0){  // 그리디 사용
            count += n / 5; // 5부터 채우기
            cout << count;
            return 0;
        }
        n -= 3; // 조건 충족 x > -3 한 후 다시 5 채우기
        count += 1;
    }

    cout << -1;
}
