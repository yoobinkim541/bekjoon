# include <bits/stdc++.h>
using namespace std;


int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    int a,b,c;
    cin >> a >> b >> c;
    int sum = a + b + c;
    if (sum == 180){
        if (a == b && a == c) cout << "Equilateral";
        else if(a == b || a == c || b == c) cout << "Isosceles";
        else cout << "Scalene";

    }
    else cout << "Error";
}