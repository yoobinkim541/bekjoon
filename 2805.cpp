# include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0); cin.tie(0);
    int N,M; // N 나무의 수 / M 가져갈 나무의 길이
    cin >> N >> M;
    vector<int> v; // 각 나무의 높이 배열
    for (int i = 0; i < N; i++) // 각 나무의 높이 input
    {
        int hight;
        cin >> hight;
        v.push_back(hight);
    }

    sort(v.begin(),v.end()); // 이분탐색용 정렬
    int start = 0;
    int end = v.back();
    int result = 0;

    while (start <= end){
        int mid = (start + end) / 2;
        long long sum = 0;
        for (int i = 0; i < v.size(); i++){
            if (v[i] > mid) sum += (v[i] - mid);
        }

        if (M <= sum) {
            if(mid <= end) result = mid;
            start = mid + 1; // sum 값이 더 크다면 더 높이 자를 수 있음 > start 값 증가
        }
        else{
            end = mid - 1; // sum  값이 더 작으면 mid 보다 작은 범위에서 탐색
        }


    }
    cout << result;


}