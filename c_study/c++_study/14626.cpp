#include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0); cin.tie(0);
    string v;
    cin >> v;
    int index = v.find('*');
    int end = (int)v[12] - '0'; 
    index = index % 2;

    int sum = 0;
    for (int i = 0; i < 12; i++){
        if (v[i] == '*') continue; 
        else if (i % 2 == 1) sum += ((int)v[i] - '0') * 3;
        else if (i % 2 == 0) sum += (int) v[i] - '0';
    }
    for (int i = 0; i <= 9; i++) {
        int total;
        if (index == 1) total = sum + i * 3 + end;
        else total = sum + i + end;
        if (total % 10 == 0) cout << i;
    }
}

