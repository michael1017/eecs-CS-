#include<stdio.h>
int main(void){
    char big_input1[1005] = {0};
    char big_input2[1005] = {0};
    char answer[1005] = {0};
    int big_input_size = 0,answer_size = 0;
    int count_times,divisor,num_reg = 0;
    int i,k,flag = 0;
    scanf(" %d",&count_times);
    for(k=1;k<=count_times;k++){
        scanf("%s",big_input1);
        scanf("%s",big_input2);
        scanf("%d",&divisor);
        for( i=0; big_input1[i]!=0; i++){
            big_input1[i] -= 48;
            big_input2[i] -= 48;
            big_input1[i] += big_input2[i];
            
        }
        big_input_size = i; 
        //the number of atom big_input contains
        //just like strlen()    :)
        for(i=0;i<big_input_size;i++){
            num_reg *=10;
            answer[i] = (big_input1[i]+num_reg)/divisor;
            num_reg = (big_input1[i]+num_reg)%divisor;
        }
        for(i=big_input_size-1;i>=1;i--){
            answer[i-1] += answer [i] /10 ;
            answer[i]  %= 10; 
        }
        for(i=0;i<big_input_size;i++){
            if(answer[i]!=0){
                flag = 1;
            }
            if(flag){
                printf("%d",answer[i]);
            }
        }
        if(!flag){
            printf("0");
        }
        printf("\n");
        big_input1[0] = '\0';
        big_input2[0] = '\0';
        answer[0] = '\0';
        big_input_size = answer_size = 0;
        num_reg = 0;
        flag = 0;

    }
    return 0;
}
