#include <iostream>
using namespace std;

int main(void){
    string s;
    cin >> s;
    int count[26] = {0,};
    for(auto a : s){
        count[a - 'a']++;
    }   
    for(int i = 0; i < 26; i++){
        cout << count[i] << ' ';
    }           
}