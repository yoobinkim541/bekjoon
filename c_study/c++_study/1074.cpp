#include<iostream>
#include<vector>
using namespace std;
int N,r,c;


int main(void){
    cin >> N >> r >> c;
    long long L = 1;
    int count = 0;

    // 배열의 길이 계산
    for(int i = 0; i < N; i++){
        L *= 2;
    }

    int left_x = 0;
    int left_y = 0;
    int right_x = L-1;
    int right_y = L-1;
    while(left_x != right_x && left_y != right_y){
        int mid_x = left_x + (right_x - left_x) / 2;
        int mid_y = left_y + (right_y - left_y) / 2;
        if(r <= mid_x && c <= mid_y){// 1사분면
            right_x = mid_x;
            right_y = mid_y;
        } 
        else if(r <= mid_x && c > mid_y) // 2사분면
        {
            count += (L/2) * (L/2);
            right_x = mid_x;
            left_y = mid_y + 1;
        }
        else if(r > mid_x && c <= mid_y) // 3사분면
        {
            count += (L/2) * (L/2) * 2;
            left_x = mid_x + 1;
            right_y = mid_y;
        }
        else if(r > mid_x && c > mid_y) // 4사분면
        {
            count += (L/2) * (L/2) * 3;
            left_x = mid_x + 1;
            left_y = mid_y + 1;
        }

        L /= 2;
    }
    
    cout << count;
    return 0;
}