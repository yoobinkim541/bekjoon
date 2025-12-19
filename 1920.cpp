#include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0); cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int j = 0; j < N; j++){
        cin >> A[j];
    }
    sort(A.begin(), A.end());

    int M;
    cin >> M;
    for (int j = 0; j < M; j++){
        int target;
        cin >> target;
        if (binary_search(A.begin(), A.end(), target))
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }
}
