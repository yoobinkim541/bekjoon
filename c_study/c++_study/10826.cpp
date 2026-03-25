#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string string_add(string f0,string f1){
    int sum = 0;
    string result = "";
    int j = f1.length() -1;
    int i = f0.length() -1;

    while(i >= 0 || j >= 0 || sum > 0){
        if(i >= 0) sum += f0[i--] - '0';
        if(j >= 0) sum += f1[j--] - '0';
        result.push_back(char(sum % 10 + '0'));
        sum /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main(void){
    int num;
    cin >> num;

    if(num == 0){
        cout << 0;
        return 0;
    }
    else if(num == 1){
        cout << 1;
        return 0;
    }

    string f0 = "0";
    string f1 = "1";
    string fn = "";

    for(int i = 2; i <= num; i++){        
        fn = string_add(f0,f1);
        f0 = f1;
        f1 = fn;
    }

    cout << fn << '\n';
    return 0;
}