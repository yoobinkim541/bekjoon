#include <bits/stdc++.h>
using namespace std;

void DFS (int*,int*,int*,int*,vector<bool>&,vector<int>*);

int main(void){
    int n;
    cin >> n;
    int start, end;
    cin >> start >> end;
    int m;
    cin >> m;
    vector<int> v[n+1];
    for(int i = 1; i <= m; i++){
        int a,b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int j = 1; j <= m; j++){
        sort(v[j].begin(),v[j].end());
    }

    vector<bool> visited(n+1);
    int result = -1; int count = 0;
    DFS(&start,&end,&count,&result,visited,v);

    cout << result;

}

void DFS (int* start,int* end,int* count,int* result,vector<bool>& visited,vector<int>* v){
    visited[*start] = true;

    for(int i : v[*start]){ 
        if(!visited[i]){
            *count += 1;
            if(i == *end){
                *result = *count;
                return;
            }
            DFS(&i,end,count,result,visited,v);
            if(*result != -1) return;
            *count -= 1;
        }
    }
}