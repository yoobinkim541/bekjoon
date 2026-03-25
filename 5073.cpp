# include <bits/stdc++.h>
using namespace std;


int main(void){
    ios::sync_with_stdio(0); cin.tie(0);

    while (1){
    int a,b,c;
    cin >> a >> b >> c;
    int sum = a + b + c;
    if (sum == 0) break; 
    if(a >= b + c || b >= a + c || c >= a + b) cout << "Invalid" << '\n';
    else if (a == b && a == c) cout << "Equilateral" << '\n';
    else if(a == b || a == c || b == c) cout << "Isosceles" << '\n';
    else cout << "Scalene" << '\n';
    }
}