#include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0); cin.tie(0);
    stack<int> s;
    int N;
    cin >> N;
    for (int i  = 0; i < N; i++){
        int temp;
        cin >> temp;
        if (temp == 0) {
            s.pop();
        }
        else s.push(temp);
    }
    int sum = 0;
    while (!s.empty()){
        sum += s.top();
        s.pop();
    }
    cout << sum;

}