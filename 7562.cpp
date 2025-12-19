#include <bits/stdc++.h>
using namespace std;

int BFS (int x, int y, int nx, int ny, vector<vector<int>> & chessboard, int I);
int eightway_x[8] = {-2,-2,-1,-1,1,1,2,2};
int eightway_y[8] = {-1,1,-2,2,-2,2,-1,1};

int main (void){
    ios::sync_with_stdio(false); cin.tie(0);
    int test_case;
    cin >> test_case;

    for(int i = 0; i < test_case; i++){
        int I;
        cin >> I;
        vector<vector<int>> chessboard (I,vector<int>(I,-1));
        int x,y;
        cin >> x >> y;
        int nx,ny;
        cin >> nx >> ny;
        int answer = BFS(x,y,nx,ny,chessboard, I);
        cout << answer << '\n';
    }

    return 0;
}

int BFS (int x, int y, int end_x, int end_y, vector<vector<int>> & chessboard, int I){
    chessboard[x][y] = 0;
    if(x == end_x && y == end_y) return 0;
    queue<pair<int,int>> q;
    q.push({x,y});

    while(!q.empty()){
        int current_x = q.front().first;
        int current_y = q.front().second;
        q.pop();

        for(int i = 0; i < 8; i++){
            int next_x = eightway_x[i] + current_x;
            int next_y = eightway_y[i] + current_y;

            if(next_x >= 0 && next_y >= 0 && next_x < I && next_y < I && chessboard[next_x][next_y] == -1){
                chessboard[next_x][next_y] = chessboard[current_x][current_y] + 1;
                q.push({next_x,next_y});
            }

            if(next_x == end_x && next_y == end_y) return chessboard[end_x][end_y];
        }
    }
    return chessboard[end_x][end_y];
}

