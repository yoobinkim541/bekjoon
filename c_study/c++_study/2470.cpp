#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int main(void){
    int N;
    cin >> N;
    vector<int> list;
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        list.push_back(temp);
    }

     sort(list.begin(), list.end());

    int left = 0; int right = N-1;
    long long result = abs(2000000000);
    int answer_left = 0 , answer_right = N-1;
    while(left < right){
        long long temp = list[left] + list[right];
        if(result > abs(temp)){
            answer_left = left;
            answer_right = right;
            result = abs(temp);
        }

        if(temp < 0){
            left++;
        }
        else{
            right--;
        }
    }
    cout << list[answer_left] << ' ' << list[answer_right];
}