# include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> v;

    for (int i = 0; i < n; i++){
        int money;
        cin >> money; // 지방 예산 요청
        v.push_back(money);
    }

    int max;
    cin >> max; // 총예산
    sort(v.begin(),v.end());

    int start = 1;
    int end = v.back();

    int result;

    while(start <= end){
        int mid = (start + end)/2;
        int sum = 0;

        for(int i  = 0; i < v.size(); i++){
            if (v[i] <= mid) sum += v[i];
            else sum += mid;
        }
        if (sum > max) end = mid - 1;
        else{
            if (mid <= end){
                result = mid;
            }
            start = mid + 1;
        }
        
    }
    cout << result;
}
