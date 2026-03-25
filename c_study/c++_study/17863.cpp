#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    string s;
    cin >> s;
    bool b = true;
    for(int i = 0; i < 3; i++){
        if (s[i] != '5')  {
            b = false;
            break;
        }
    }
    if(!b){
        cout << "NO";
    }
    else{
        cout << "YES";
    }

    return 0;
}