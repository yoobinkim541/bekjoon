# include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0); cin.tie(0);
    int length;
    cin >> length;
    int num;
    cin >> num;
    vector<int> location;
   

    for(int i = 0; i < num; i++){
        int n;
        cin >> n;
        location.push_back(n);
    }


    int start = 1,end = length;
    int answer = 0;

    while (start <= end) {
        int mid = (start + end) / 2;
        bool can_light = true;

        // 왼쪽 끝 확인
        if (location[0] - mid > 0) can_light = false;

        // 중간 구간 확인
        for (int i = 0; i < num - 1; i++) {
            if (location[i+1] - location[i] > 2 * mid) {
                can_light = false;
                break;
            }
        }

        // 오른쪽 끝 확인
        if (location.back() + mid < length) can_light = false;

        if (can_light) {
            answer = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    cout << answer;
}