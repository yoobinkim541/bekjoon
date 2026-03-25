#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
set<string> result_set;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void DFS(int x,int y, vector<vector<int>> &matrix, string str){
    if(str.length() == 6){
        result_set.insert(str);
        return;
    }

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5){
            DFS(nx,ny,matrix,str + to_string(matrix[nx][ny]));
        }
    }
}


int main(){
    vector<vector<int>> matrix;

    for(int i = 0; i < 5; i++){
        matrix.push_back(vector<int>());
        for(int j = 0; j < 5; j++){
            int n;
            cin >> n;
            matrix[i].push_back(n);
        }
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            string s = to_string(matrix[i][j]);
            DFS(i, j, matrix, s);
        }
    }
    cout << result_set.size() << "\n";
    return 0;
}