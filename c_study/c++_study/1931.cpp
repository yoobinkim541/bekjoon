#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
    vector<pair<int,int>> meeting;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int a,b;
        cin >> a >> b;
        meeting.push_back({a,b});
    }
    // 끝나는 시간을 기준으로 정렬 후 같을 시 시작시간 비교 후 정렬
    sort(meeting.begin(),meeting.end(),[](pair<int,int> a, pair<int,int> b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        return a.second < b.second;
    });

    int least_time = 0;
    int count = 0;
    for(int i = 0; i < N; i++){
        if(meeting[i].first >= least_time){
            least_time = meeting[i].second;
            count++;
        }
    }
    cout << count;
    
}