#include<stdio.h>
#include<string.h>
int main(void){
    char input[1001];
    int i,j,k;
    scanf("%s",input);
    for( i=1; i<strlen(input); i++){
        for( j=i; j<strlen(input); j++){
            printf("%c",input[j]);
        }
        for( j=0; j<i; j++){
            printf("%c",input[j]);
        } 
        printf("\n");
    }
    printf("%s\n",input);

}