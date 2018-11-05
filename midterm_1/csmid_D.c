#include<stdio.h>
int main(void){
    int i,j,k,t,p,flag=0;
    int bingo[5][5];
    int commend;
    int operate[25];
    int status[12] = {0};
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            scanf("%d", &bingo[i][j]);
        }
    }
    scanf("%d", &t);
    for(i=0;i<t;i++){
        scanf(" %d", &commend);
        for(j=0;j<commend;j++){
            scanf("%d", &operate[j]);
        }
        for(p=0;p<commend;p++){
            for(j=0;j<5;j++){
                for(k=0;k<5;k++){
                    if(operate[p] == bingo[j][k]){
                        status[j]++;
                        status[k+5]++;
                        if(j==k) status[10]++;
                        if((j+k)==4) status[11]++;
                    }
                }
            }
            for(j=0;j<12;j++){
                if(status[j]==5){
                    printf("Case #%d: %d\n", i+1,p+1);
                    flag = 1;
                    break;
                }
            }
            if(p==commend-1 && flag==0 ){
                printf("Case #%d: Not yet \\(^o^)/\n",i+1);
            }
            if(flag){
                flag = 0; 
                break;
            } 
            
            
        }
        for(j=0;j<12;j++){
            status[j] = 0;
        }
        
    }
}