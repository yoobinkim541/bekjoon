#include <bits/stdc++.h>
using namespace std;
main(void){
    int x = 1, y = 2;

    const int* p1 = &x; // '가리키는 값'이 상수(읽기만), 포인터는 변경 가능
    cout << *p1 << endl;
    // *p1 = 3;         // ❌ but, x = 3; 은 OK / x가 const int 가 되는 것은 아님 
    p1 = &y;            // OK (*p1 = 2) 
    cout << *p1 << endl;
    x = 10;
    cout << x << endl;


    int* const p2 = &x; // '포인터 자체'가 상수(변경 불가), 값은 수정 가능
    *p2 = 4;            // OK
    // p2 = &y;         // ❌ 
    cout << *p2 << endl;

    const int* const p3 = &x; // 둘 다 상수
    cout << *p3 << endl;

    return 0;
}