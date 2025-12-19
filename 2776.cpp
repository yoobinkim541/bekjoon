# include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0); cin.tie(0);
    long long T;
    cin >> T;
    for (int i = 0; i < T; i++){
        long long N;
        cin >> N;
        vector<int> v1;

        for (int j = 0; j < N; j++){
            long long num;
            cin >> num;
            v1.push_back(num);
        }
        
        sort(v1.begin(),v1.end());

        long long M;
        cin >> M;
        
        bool b;
        for(int j = 0; j < M; j++){
            long long num;
            cin >> num;
            b = binary_search(v1.begin(),v1.end(),num);
        
            if(b == true) cout << 1 << '\n';
            else cout << 0 << '\n';
        }

        
    }
}