#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main(void){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int input = 0;
        int result = 1;
        cin >> input;

        string category;
        string cloth;
        map<string, int> list;
        for(int j = 0; j < input; j++){
            cin >> cloth >> category;
            list[category]++;
        }

        for(auto [category,cloth_list] : list){
            result *= (cloth_list + 1);
        }   
        cout << result - 1 << endl;
    }
    return 0;
}