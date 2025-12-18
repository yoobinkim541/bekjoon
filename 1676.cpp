/* 
그냥 브루트포스를 사용하여 곱으로 팩토리얼을 만든 후 0을 count 하면 13! 에서 int 오버플로우 / 20! 에서 long long 오버플로우가 된다.
따라서 다른 방법을 찾아야 함
10이 만들어지려면 2와 5의 쌍이 존재하여야 한다.
하지만 2보다 5의 개수가 더 적기 때문에 5의 개수를 count 하면 0의 개수를 수학적으로 알아낼 수 있다.
 */

#include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, zero_count = 0;
    cin >> N;
    
    for (int i = 5; i <= N; i *= 5){
        zero_count += N / i;
    }
    
    cout << zero_count;
}