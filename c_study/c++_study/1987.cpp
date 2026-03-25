#include <iostream>
#include <vector>
using namespace std;
int r,c;

void DFS(vector<vector<char>> &board,vector<char> &s,int x,int y,int &max_dist, int dist){
    max_dist = max(max_dist,dist);
    s.push_back(board[x][y]);
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < r && ny >= 0 && ny < c){
            bool b = false;
            for(auto a : s){
                if(a == board[nx][ny]){
                    b = true;
                    break;
                }
                
            }
            if(!b){
                DFS(board,s,nx,ny,max_dist,dist+1);
                s.pop_back();
            }
        }
    }

}

int main(void){
    cin >> r >> c;
    vector<vector<char>> board;
    for(int i = 0; i < r; i++){
        string str;
        cin >> str;
        vector<char> row;
        for(auto a : str){
            row.push_back(a);
        }
        board.push_back(row);
    }

    int max_dist = 0; vector<char> s;
    DFS(board,s,0,0,max_dist,1);

    cout << max_dist;
    return 0;
}