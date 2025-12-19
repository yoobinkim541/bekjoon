# include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0); cin.tie(0);
    int have_len, need_len;
    cin >> have_len >> need_len;
    vector<long long> v;
    for(int i = 0; i < have_len; i++){
        long long num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(),v.end());
    long long start = 1, end = v.back();
    long long answer = 0;

    while(start <= end){
        long long mid = (start + end) / 2;
        long long count = 0;

        for(int j = 0; j < v.size(); j++){
            count += v[j] / mid;
        }

        if(count >= need_len){
            answer = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    cout << answer;
}
