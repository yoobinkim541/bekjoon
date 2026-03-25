#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int R,C; // 동굴의 크기

void BFS(vector<vector<char>>& graph, vector<vector<bool>>& visited, int start_row, int start_col); // BFS 탐색을 통해 미네랄 클러스터를 찾는 함수
void findColony(vector<vector<char>>& graph, vector<vector<bool>>& visited, int start_row, int start_col, vector<pair<int,int>>& sky_colony); // BFS 탐색을 통해 공중에 떠있는 미네랄 클러스터를 찾는 함수

int main(void){
    cin >> R >> C;
    vector<vector<char>> graph; // 동굴의 상태를 저장하는 2차원 벡터
    for(int i = 0; i < R; i++){
        string temp;
        vector<char> row;
        cin >> temp;
        for(char c : temp){
            row.push_back(c);
        }
        graph.push_back(row);
    }

    int N; // 막대를 던지는 횟수
    cin >> N;
    queue<int> stick; // 막대를 던지는 높이
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        stick.push(temp);
    }

    int stick_count = 0;
    while(!stick.empty()){
        vector<vector<bool>> visited(R,vector<bool>(C,false)); //미네랄 클러스터 확인 & 공중에 떠 있는 미네랄 확인용 bool array
        int height = stick.front();
        stick.pop();
        if(stick_count % 2 == 0){ // 짝수일 경우 막대를 던지는 높이에 해당하는 행에서 왼쪽에서 오른쪽으로 탐색 
        for(int i = 0; i < C; i++){
            if(graph[R-height][i] == 'x'){
                    graph[R-height][i] = '.'; // 막대가 부딪힌 돌을 제거
                    break;
                }
            }
            stick_count++;
        }
        else{
            for(int i = C-1; i >= 0; i--){ // 홀수일 경우 오른쪽에서 왼쪽으로 던짐
            if(graph[R-height][i] == 'x'){
                    graph[R-height][i] = '.'; // 막대가 부딪힌 돌을 제거
                    break;
                }
            }
            stick_count++;
        }
        for(int i = 0; i < C; i++){ // 최하단에 있는 미네랄 클러스터 찾기
            if(graph[R-1][i] == 'x'){
                BFS(graph,visited,R-1,i);
            }
        }

        // # 공중에 떠있는 미네랄 클러스터 찾기
        vector<pair<int,int>> sky_colony1;
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(graph[i][j] == 'x' && visited[i][j] == false){
                    findColony(graph,visited,i,j,sky_colony1);
                }
            }
        }

        // # 클러스터 떨어뜨리기

        // 낙하거리 계산 전 공중에 떠있는 클러스터 제거
         for(pair<int,int> p : sky_colony1){
            int row = p.first;
            int col = p.second;
            graph[row][col] = '.';
        }

        // 낙하거리 계산
        int min_dist = R;
        for(pair<int,int> p : sky_colony1){
            int row = p.first;
            int col = p.second;
            int dist = 0;
            for(int i = row+1; i < R; i++){
                if(graph[i][col] == 'x') break;
                dist++;
            }
            min_dist = min(dist, min_dist);
        }
        
        // 아래로 이동

        for(pair<int,int> p : sky_colony1){
            int row = p.first;
            int col = p.second;
            graph[row+min_dist][col] = 'x';
        }
    }    
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout << graph[i][j];
        }
        cout << "\n";
        }
        return 0;
    }

void BFS(vector<vector<char>>& graph, vector<vector<bool>>& visited, int start_row, int start_col){
    queue<pair<int,int>> q;
    q.push({start_row,start_col});
    visited[start_row][start_col] = true;
    int row[4] = {1,0,0,-1};
    int col[4] = {0,1,-1,0};

    while(!q.empty()){
        int cur_row = q.front().first;
        int cur_col = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int next_row = row[i] + cur_row;
            int next_col = col[i] + cur_col;
            if(next_row >= 0 && next_row < R && next_col >= 0 && next_col < C && graph[next_row][next_col] == 'x' && visited[next_row][next_col] == false){
                q.push({next_row,next_col});
                visited[next_row][next_col] = true;
            }   
        }
    }
}

void findColony(vector<vector<char>>& graph, vector<vector<bool>>& visited, int start_row, int start_col, vector<pair<int,int>>& sky_colony){
    queue<pair<int,int>> q;
    q.push({start_row,start_col});
    sky_colony.push_back({start_row,start_col}); // 공중에 떠있는 미네랄 클러스터의 좌표 저장
    visited[start_row][start_col] = true;
    int row[4] = {1,0,0,-1};
    int col[4] = {0,1,-1,0};

    while(!q.empty()){
        int cur_row = q.front().first;
        int cur_col = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int next_row = row[i] + cur_row;
            int next_col = col[i] + cur_col;
            if(next_row >= 0 && next_row < R && next_col >= 0 && next_col < C && graph[next_row][next_col] == 'x' && visited[next_row][next_col] == false){
                q.push({next_row,next_col});
                visited[next_row][next_col] = true;
                sky_colony.push_back({next_row,next_col}); // 공중에 떠있는 미네랄 클러스터의 좌표 저장
            }   
        }
    }
}