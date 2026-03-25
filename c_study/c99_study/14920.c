#include <stdio.h>

int main(void){
    int num;
    int count = 1;
    scanf("%d",&num);
    while (1) {
        if (num == 1) {
            break;
        }
        else if (num % 2 == 0){
            count++;
            num = num/2;
        }
        else{
            count++;
            num = num*3+1;
        }

    }
    printf("%d",count);

    return 0;
}