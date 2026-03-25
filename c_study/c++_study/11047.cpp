#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,K;

int main(void){
    cin >> N >> K;
    vector<int> v;
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    reverse(v.begin(),v.end());
    int sum = 0;
    int count = 0;
    while(sum < K){
        for(int i : v){
            if(sum == K){
                break;
            }
            if(sum + i <= K){
                sum += i;
                count++;
                break;
            }
        }
    }

    cout << count;
    return 0;
}