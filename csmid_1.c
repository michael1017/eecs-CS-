#include<stdio.h>
#include<string.h>

int main(void){
    char find[7];
    char input[15][15];
    int n,max = 0;
    int i,j,k,flag = 0,same = 0;
    scanf("%s",find);
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",input[i]);
        for(j=0;j<strlen(input[i]);j++){
            for(k=0;k<strlen(find);k++){
                if(input[i][j+k]!=find[k]){
                    flag = 1;
                    break;
                }
            }
            if(!flag){
                same ++;
            }
            flag = 0;
        }
        if(same>max){
            max = same;
        }
        flag = same = 0;
    }
    printf("%d",max);

}
