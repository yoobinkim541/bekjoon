#include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0); cin.tie(0);

    int N;
    cin >> N;

    vector<vector<int>> list(N, vector<int>(2));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < 2; j++){
            cin >> list[i][j];
        }
    }
    for (int i = 0; i < N; i++){
        int r = 1;
        for(int j = 0; j < N; j++){   
            if (list[i][0] < list[j][0] && list[i][1] < list[j][1]) r++;
        }
        cout << r << " ";
    }


}