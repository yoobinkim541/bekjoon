# include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0); cin.tie(0);
    long long game_play, win;
    cin >> game_play >> win;
    int z = 100 * win / game_play;
    if (z >= 99) {
        cout << -1;
        return 0;
    }

    long long start = 1, end = game_play; 
    long long answer = 0;
    while (start <= end){
        long long mid = (start + end) / 2;
        long long new_z = (100 * (win + mid)) / (game_play + mid);

        if(new_z > z){
            answer = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    cout << answer;
}