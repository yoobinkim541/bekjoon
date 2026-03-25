#include <iostream>
#include <vector>
using namespace std;

int fib(int n){
    vector<int> v(n+1,0);
    v[0] = 1;
    v[1] = 1;
    if(n != 0 && n != 1){
       for(int i = 2; i <= n; i++){
            v[i] = v[i-1] + v[i-2];
        } 
    }
    
    return v[n];
}

int main(void){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        cout << fib(num) << '\n';
    }
    return 0;
}