#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= int(sqrt(n)); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int M, N;
    cin >> M >> N;
    int sum = 0, minPrime = -1;
    
    for (int i = M; i <= N; i++) {
        if (isPrime(i)) {
            sum += i;
            if (minPrime == -1) minPrime = i;
        }
    }

    if (minPrime == -1) cout << -1 << '\n'; // 소수가 없을 경우
    else cout << sum << '\n' << minPrime << '\n';

    return 0;
}
