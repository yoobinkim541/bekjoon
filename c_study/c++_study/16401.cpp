# include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0); cin.tie(0);
    long long M,N;
    cin >> M >> N;
    vector<long long> v;

    for (int i  = 0; i < N; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(),v.end());

    long long start = 1, end = v.back();
    long long answer = 0;
    while(start <= end){
        long long mid = (start + end) / 2;
        int count = 0;
        for (int i = 0; i < N; i++){
            count += v[i] / mid;
        }

        if (count >= M){
            
            start = mid + 1;
            answer = mid;
        }
        else{
           end = mid - 1; 
        }

    }
    cout << answer;
}