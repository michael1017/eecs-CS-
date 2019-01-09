#include<stdio.h>
#include<stdlib.h>
int main(void){
    unsigned long long int sum = 0;
    unsigned long long int mask_to_cal = 1;
    unsigned long long int mask_get = 0;
    unsigned long long int input[100005] = {0};
    int nums, not_zero = 0;
    int i, j;
    scanf(" %d", &nums);
    for(i=0; i<nums; i++){
        scanf(" %llu", &input[i]);
    }
    for(i=1; i<=20; i++){// get the mask we need
        for(j=0; j<nums; j++){
            if( (unsigned long long int )(input[j] & mask_to_cal) != 
                (unsigned long long int )(0)                         ){
                not_zero++;
            }
        }
        if(not_zero > nums/2){
            mask_get += mask_to_cal;
        }
        mask_to_cal <<= 1;
        not_zero = 0;
    }
    for(j=0; j<nums; j++){// use the mask we get to calculate min
        sum += input[j] ^ mask_get;
    }
    printf("%llu\n", sum);
    return 0;
}