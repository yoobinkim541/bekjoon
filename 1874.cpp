# include <bits/stdc++.h>
using namespace std;


int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    int N;
    cin >> N;
    vector<int> final;
    stack<int> s;
    vector<char> result;
    int temp = 1;
    for (int i  = 0; i < N; i++){
        int a;
        cin >> a;
        final.push_back(a);
    }

    for(int i = 0; i < N; i++){
        int a = final[i];

        while(temp <= a){
            s.push(temp);
            result.push_back('+');
            temp += 1;
        }

        if(s.top() == a){
            s.pop();
            result.push_back('-');
        }
        else{
            cout << "NO" << '\n';
            return 0;
        }
    }
    for (int i = 0; i < result.size(); i++){
        cout << result[i] << '\n';
    }
}