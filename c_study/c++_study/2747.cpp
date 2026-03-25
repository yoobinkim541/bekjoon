#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<long long> v;
    long long f0 = 0;
    long long f1 = 1;
    if(n == 0){
        cout << f0;
        return 0;
    }
    else if(n == 1){
        cout << f1;
        return 0;
    }

    v.push_back(f0);
    v.push_back(f1);

    for(int i = 2; i <= n; i++){
        long long f = v[i-2] + v[i-1];
        v.push_back(f);
    }
    cout << v[n];
    return 0;
}