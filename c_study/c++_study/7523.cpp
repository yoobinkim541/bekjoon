#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    long long n = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        long long a;
        long long b;
        long long result = 0;
        cin >> a >> b;
        if (a > b) swap(a, b);
        result = (a + b) * (b - a + 1) / 2;
        cout << "Scenario #" << i << ":" << '\n';
        cout << result << '\n';

        cout << '\n';
    }

    return 0;
}