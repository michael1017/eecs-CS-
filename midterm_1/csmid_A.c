#include<stdio.h>
int main(void){
    int n,m;
    int i,j,k;
    scanf("%d", &n);
    scanf("%d", &m);
    int initial[200003]={0};
    int request[m];
    for(i=0;i<m;i++){
        scanf("%d", &request[i]);
    }
    for(i=m-1;i>=0;i--){
        if(initial[request[i]] == 0){
            printf("%d\n", request[i]);
            initial[request[i]] = 1;
        }
    }
    for(i=1;i<=n;i++){
        if(!initial[i]){
            printf("%d\n",i);
        }
    }
    //printf("\n");

}
