#include<stdio.h>
int main(void){
    int i;
    int ternary_digit[8] = {0};
    int input,digits,digit_store_place = 7;
    scanf(" %d %d",&input,&digits);
    while(input != 0){
        ternary_digit[digit_store_place] = input % 3;
        input /= 3;
        digit_store_place--;
    }
    for( i=8-digits; i<8; i++){
        printf("%d",ternary_digit[i]);
    }
    printf("\n");

}
