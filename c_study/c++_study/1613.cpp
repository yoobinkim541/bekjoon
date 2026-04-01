#include<iostream>
#include<vector>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int node, edge;
    cin >> node >> edge;
    vector<vector<bool>> graph (401,vector<bool>(401,false));
    for(int i = 0; i < edge; i++){
        int a,b;
        cin >> a >> b;
        graph[a][b] = true;
    }

    // 플로이드 와샬 알고리즘
    for(int k = 1; k <= node; k++){
        for(int i = 1; i <= node; i++){
            for(int j = 1; j <= node; j++){
                if(graph[i][k] && graph[k][j]){
                    graph[i][j] = true;
                }
            }
        }
    }

    // 결과 출력
    int num;
    cin >> num;
    for(int i = 0; i < num; i++){
        int a,b;
        cin >> a >> b;
        if(graph[a][b]){
            cout << "-1\n";
        }
        else if(graph[b][a]){
            cout << "1\n";
        }
        else{
            cout << "0\n";
        }
    }
}