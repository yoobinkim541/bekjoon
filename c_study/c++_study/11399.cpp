#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;

int main(void){
    cin >> N;
    vector<int> v;
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    int sum = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= i; j++){
            sum += v[j];
        }
    }
    cout << sum;
    return 0;
}