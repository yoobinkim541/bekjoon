# include <bits/stdc++.h>
using namespace std;

int avr (const vector<int>& v);
int center (const vector<int>& v);
int mode (const vector<int>& v);
int boundery (const vector<int>& v);

int main (void){
    ios::sync_with_stdio(0); cin.tie(0);
    int N;
    cin >> N;
    vector<int> v;
    for (int i = 0; i < N; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    int average = avr(v);
    cout << average << '\n';
    int mid = center(v);
    cout << mid << '\n';
    int mod = mode(v);
    cout << mod <<'\n';
    int bdy = boundery(v);
    cout << bdy <<'\n';

}

int avr (const vector<int>& v){
    int sum = 0;
    for (int i : v) sum += i;
    int result = round((double)sum / v.size());
    
    return result;
}

int center (const vector<int>& v){
    vector<int> center = v;
    sort(center.begin(),center.end());
    int mid = center.size()/2;
    
    return center[mid];
}

int mode(const vector<int>& v) {
    map<int,int> m;

    for (int x : v){
        m[x] += 1;        
    }

    int max1 = 0;
    for (auto[value,count] : m){
        max1 = max(max1,count);
    }

    vector<int> candidates;
    for (auto [val, cnt] : m) {
        if (cnt == max1)
            candidates.push_back(val);
    }

    sort(candidates.begin(),candidates.end());
    if (candidates.size() >= 2) return  candidates[1];
    else return candidates[0];
}

int boundery (const vector<int>& v){
    vector<int> a = v;
    sort(a.begin(),a.end());
    int max = a.back();
    int min = a.front();

    return max - min;
}