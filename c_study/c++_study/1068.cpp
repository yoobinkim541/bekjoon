    #include<iostream>
    #include<vector>
    #include<queue>
    using namespace std;

    int BFS(vector<vector<int>>& graph, int start,int erase){
        queue<int> q;
        q.push(start);
        int count = 0;
        
        while(!q.empty()){
            int cur = q.front();
            q.pop();

            int cnt = 0;
            for(auto next : graph[cur]){
                if(next == erase) continue;
                q.push(next);
                cnt++;
            }
            if(cnt == 0) count++;
        }
        return count;
    }

    int main(void){
        int n;
        int root;
        cin >> n;
        vector<vector<int>> graph(n);
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            if(num == -1) {
                root = i;
            }
            else{
                graph[num].push_back(i);
            }
        }

        int erase;
        cin >> erase;
        if(erase == root){
            cout << 0 << '\n';
            return 0;
        }

        cout << BFS(graph,root,erase) << '\n';
        return 0;
    }