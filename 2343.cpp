# include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0); cin.tie(0);
    long long lecture_num , blueray_num;
    cin >> lecture_num >> blueray_num;
    vector<long long> v;
    long long sum = 0;

    for(int i = 0; i < lecture_num; i++){
        long long num;
        cin >> num;
        v.push_back(num);
        sum += num;
    }

    long long start = *max_element(v.begin(),v.end()), end = sum;
    long long answer = 0;

    while (start <= end){
        long long mid = (start + end) / 2;
        long long count = 1, blueraysum = 0;
        
        for(int j = 0; j < lecture_num; j++){
            if(blueraysum + v[j] > mid){
                count += 1;
                blueraysum = 0;
            }
            blueraysum += v[j];
        }

        if(count <= blueray_num){
            answer = mid;
            end = mid - 1;
        }
        else start = mid + 1;
    }
    cout << answer;

}