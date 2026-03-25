#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(void){
    int n;
    vector<int> v;
    cin >> n;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }


    int count = 0;
    int start_v = 0;
    int end_v = 0;
    map<int, int> m;
    for(;end_v < n;end_v++){
        m[v[end_v]]++;
        while(m.size() > 2){
            m[v[start_v]]--;
            if(m[v[start_v]] == 0){
                m.erase(v[start_v]);
            }
            start_v++;
        }
        count = max(count, end_v - start_v+1);
    }
    cout << count << endl;

}