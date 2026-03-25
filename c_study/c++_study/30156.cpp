#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    string str;
    int n;
    cin >> n;
    for(int i=0; i < n; i++){
        cin >> str;
        int a = count(str.begin(),str.end(),'a');
        int b = count(str.begin(),str.end(),'b');
        int result = min(a,b);
        cout << result << '\n';
    }
    return 0;
}