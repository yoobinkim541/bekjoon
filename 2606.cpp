#include <bits/stdc++.h>
using namespace std;

void DFS (vector<bool> &,vector<int>*,int,int*);

int main(void){
    int com_num;
    cin >> com_num;
    int n;
    cin >> n;
    vector<int> v[com_num+1];
    for(int i = 1; i <= n; i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int j = 1; j <= com_num; j++){
        sort(v[j].begin(),v[j].end());
    }

    vector<bool> visit_dfs(com_num + 1);

    int result = 0;
    DFS(visit_dfs, v, 1, &result);

    cout << result;

}

void DFS (vector<bool>& visit_dfs, vector<int>* v,int num, int* result){
    visit_dfs[num] = 1;
    

    for(int i : v[num]){
        if(!visit_dfs[i]) {
            *result += 1;
            DFS(visit_dfs,v,i, result);
        }
    }
}