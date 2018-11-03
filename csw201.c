#include <stdio.h>
#include <string.h>
int main(void){
    int input,input_plus_1;
    int i = 0 , diff = 0;
    char digit_num1[10],digit_num2[10];

    scanf(" %d",&input);
    input_plus_1 = input + 1;

    while(input!=0){
        digit_num1[i] = input%2 + 48;
        input /= 2;
        i++;
    }
    digit_num1[i]='\0';
    i=0;
    while(input_plus_1!=0){
        digit_num2[i] = input_plus_1%2 + 48;
        input_plus_1 /= 2;
        i++;
    }
    digit_num2[i]='\0';
    i=0;
    while(i<strlen(digit_num1)){
        if(digit_num1[i] == '1'){
            diff++;
        }
        else{
            break;
        }
        i++;
    }

    for(i=strlen(digit_num2)-1;i>=0;i--){
    	printf("%c",digit_num2[i]);
	}

    printf(" %d",diff);
    return 0;
}
