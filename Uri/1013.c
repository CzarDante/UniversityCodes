#include <stdio.h>
 
int main() {
 
    int num1, num2, num3;

    scanf("%d %d %d", &num1, &num2, &num3);

    if(num1 > num2 && num1 > num3){
        printf("%d eh o maior\n", num1);
    }
    if(num1 == num2 && num1 > num3){
        printf("%d eh o maior\n", num1);
    }
    if(num2 > num1 && num2 > num3){
        printf("%d eh o maior\n", num2);
    }
    if(num2 == num3 && num2 > num1){
        printf("%d eh o maior\n", num2);
    }
    if(num3 > num1 && num3 > num2){
        printf("%d eh o maior\n", num3);
    }
 
    return 0;
}