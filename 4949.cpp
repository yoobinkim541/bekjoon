# include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0); cin.tie(0);
   
    while (1){ 
        string s;
        stack<char> stk;
        bool isValid = true;
        getline(cin,s);
        if (s == ".") break;
        for (auto c : s){
            if (c == '(' || c == '['){
                stk.push(c);
            }
            else if (c == ')'){
                if (stk.size() == 0 || stk.top() != '(') {
                cout << "no" << '\n';
                isValid = false;
                break;
                }
                stk.pop();
            }
            else if (c == ']'){
                if(stk.size() == 0 || stk.top() != '[') {
                    cout << "no" << '\n';
                    isValid = false;
                    break;
                }
                stk.pop();
            }

        }
        if (isValid && stk.empty()) cout << "yes" << '\n';
        else if (isValid == true) cout << "no" << '\n';

    }
}   