#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    long long num;
    cin >> num;
    vector<bool> v(21);

    for(int i = 0; i < num; i++){
        string str;
        int n;
        cin >> str;
        if(str != "all" && str != "empty"){
            cin >> n;
        }
        

        if(str == "add"){
            v[n] = true;

        }
        else if(str == "remove"){
            if (v[n] == true){
                v[n] = false;
            }
        }
        else if(str == "check"){
            if (v[n] == true) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(str == "toggle"){
            if (v[n] == true){
                v[n] = false;
            }
            else{
                v[n] = true;
            }
        }
        else if(str == "all"){
            for(int i = 1; i <= 20; i++ ){
                v[i] = true;
            }
        }
        else if(str == "empty"){
            for (int i = 1; i <= 20; i++){
                v[i] = false;
            }
        }
    }
}