#include<stdio.h>
#include<string.h>
int judge(int );
char input[2003];
int main(void){
   
    int i,j,len;
    while( scanf("%s",input)!=EOF){
        len = strlen(input);

        printf("%d\n", judge(len));
    }
    return 0;
}
int judge(int len){
    int i,j,k;
    int answer = 0;
    for(i=1;i<len-1;i++){
        for(j=1;i-j>=0,i+j<len;j++){
            if(input[i-j]==input[i+j]){
                answer++;
            }
            else{
                break;
            }
        }
    }
    for(i=0,k=1;k<len;i++,k++){
        for(j=0;i-j>=0,k+j<len;j++){
            if(input[i-j]==input[k+j]){
                answer++;
            }
            else{
                break;
            }
        }
    }
    return answer;
}
                                                        