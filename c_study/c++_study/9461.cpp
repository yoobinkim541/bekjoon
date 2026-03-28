#include<iostream>
#include<vector>
using namespace std;

int main(void){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int input = 0;
        cin >> input;
        vector<long long> triangle (101);
        triangle[1] = 1;
        triangle[2] = 1;
        triangle[3] = 1;
        triangle[4] = 2;
        triangle[5] = 2;
        triangle[6] = 3;
        triangle[7] = 4;
        triangle[8] = 5;
        for(int j = 9; j <= input; j++){
            triangle[j] = triangle[j-1] + triangle[j-5];
        }
        cout << triangle[input] << '\n';
    }
    return 0;
}