#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int money[100002]; // 하루마다 쓸 금액 저장
    int a, sum = 0;
 
    for (int i = 0; i < n; i++){
        cin >> a;
        sum += a; // 최대값
        money[i] = a;
    }
    int result = 0;
    int low, mid, high;
    low = 1; // 최소값
    high = sum; // 최대값
    int total; // 현재 남은 금액
    while(low <= high){
        mid = (low + high) / 2; // 인출 금액
        total = mid; // 인출 금액으로 초기화
        bool pass = true; // 성립 가능한지
        int cnt = 1; // 인출 횟수 1로 시작
        for (int i = 0; i < n; i++){
            int day_money = money[i];
            if(day_money > mid){ // 하루쓸 돈이 인출 금액보다 크면 성립x
                pass = false; 
                break;
            }
            if(day_money > total){ // 하루쓸 돈이 남은 돈보다 큰 경우
                total = mid; //돈을 인출
                cnt++; // 인출 횟수 카운트
            }
            total -= day_money; // 하루에 쓸 돈 차감       
        }
        if(!pass || cnt > m){ // 인출 횟수가 많거나 성립x
            low = mid+1; // 인출 금액 늘려줌
        }else{ 
            result = mid; // 인출 금액 저장
            high = mid-1; // 인출 금액 낮춰서 탐색
        }
    }
 
    cout << result << endl; // 출력
    return 0;
}
