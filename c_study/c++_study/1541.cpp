#include<iostream>
#include<queue>
using namespace std;

int main(void){
    string s;
    cin >> s;
    queue<char> q;

    string temp;
    int result = 0;
    bool minus = false;

    for(int i = 0; i <= s.size(); i++){
        if(i == s.length() || s[i] == '-' || s[i] == '+'){
            if(minus){
               result -= stoi(temp); 
            }
            else{
                result += stoi(temp);
            }
            temp = "";
            
            if(s[i] == '-'){
                minus = true;
            }
        }
        else{
            temp += s[i];
        }
    }



    cout << result << '\n';
    return 0;
}