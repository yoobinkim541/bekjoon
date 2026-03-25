#include <iostream>
#include <vector>
using namespace std;
int count_1 = 0;
int count_2 = 0;

int fib(int n){
    if(n == 1 or n == 2){
        count_1++;
        return 1;
    }
    else{
        return fib(n-1) + fib(n-2);
    }
}

void fib2(int n){
    vector<int> v(n+1,0);
    v[1] = 1;
    v[2] = 1;
    for(int i = 3; i <= n; i++){
        count_2++;
        v[i] = v[i-1] + v[i-2];
    }

}

int main(void){
    int n;
    cin >> n;
    fib(n);
    fib2(n);
    cout << count_1 << ' ' << count_2;
    return 0;
}