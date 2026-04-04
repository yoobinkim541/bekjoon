#include<iostream>
#include<vector>
using namespace std;
    
int N;
void find_paper(vector<vector<int>> &graph,int n,int x_start,int y_start,int& white,int& blue){
    bool Allsame = true;
    int start = graph[y_start][x_start]; 

    for(int i = y_start; i < y_start+n; i++){
        for(int j = x_start; j < x_start+n; j++){
            if(graph[i][j] != start){
                Allsame = false;
                break;
            }
        }
        if(!Allsame) break;
    }

    if(Allsame){
        if(start == 1){
            blue += 1;
        }
        else{
            white += 1;
        }
    }
    else{        
        //1사분면 (n/2 - 1 , 0부터)
        find_paper(graph,n/2,x_start + n/2,y_start,white,blue);
        //2사분면 (0,0부터)
        find_paper(graph,n/2,x_start,y_start,white,blue);
        //3사분면 (0,n/2-1부터)
        find_paper(graph,n/2,x_start,y_start + n/2,white,blue);
        //4사분면 (n/2-1,n/2-1부터)
        find_paper(graph,n/2,x_start + n/2,y_start + n/2,white,blue);
    }

}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    vector<vector<int>> graph(N,vector<int>(N,0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> graph[i][j];
        }
    }

    int white = 0; int blue = 0;
    find_paper(graph,N,0,0,white,blue);
    cout << white << '\n';
    cout << blue << '\n';

    return 0;
}