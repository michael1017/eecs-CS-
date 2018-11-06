#include<stdio.h>
int main(void){
    int t;
    int n, v[10001],temp;
    int i,j,k; //for loop variable
    scanf("%d", &t);
    for( i=0; i<t; i++){
        scanf("%d", &n);
        for( j=0; j<n; j++){
            scanf("%d", &v[j]);
        }
        for( j=0; j<n-1; j++){
            for( k=j+1; k<n; k++){
                if(v[j]>v[k]){
                    temp = v[j];
                    v[j] = v[k];
                    v[k] = temp;
                }
            }
        }
        for( j=0; j<n; j++){
            printf("%d", v[j]);
            j==n-1 ? printf("\n") : printf(" ");
        }
    }
    return 0;
}