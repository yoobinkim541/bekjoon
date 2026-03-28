#include <iostream>
#include <vector>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N,M;
    cin >> N >> M;
    vector<long long> Sum(N+1,0);
    for(int i = 1; i <= N; i++){
        int temp;
        cin >> temp;
        Sum[i] = Sum[i-1] + temp;
    }

    for(int i = 0; i < M; i++){
        int a,b;
        cin >> a >> b;
        cout << Sum[b] - Sum[a-1] << '\n';
    }

    return 0;
}