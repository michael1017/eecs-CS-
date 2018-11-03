#include<stdio.h>
long long int a[101][101];
long long int b[101][101];
/*declared in global to avoid overflow*/
int main(void){
    long long int n,m,p;
    long long int i,j,k;  /*var in loop , i = n, j = m, k = p */ 
    long long int reg_sum = 0; /* sum_register :) */
    while(scanf(" %lld %lld %lld",&n,&m,&p)!=EOF){
/*----  store array a  ------*/
        for( i=1; i<=n; i++){
            for( j=1; j<=m ; j++){
                scanf(" %lld",&a[i][j]);
            }
        }
/*----  store array b  ------*/
        for( j=1; j<=m; j++){
            for( k=1; k<=p ; k++){
                scanf(" %lld",&b[j][k]);
            }
        }
/*---- calculate and print array c  -----*/
/*---- don't have to store value in an another array, just output !!  +_+ ---------*/ 
        for( i=1; i<=n; i++){
            for( k=1; k<=p; k++){
                for( j=1; j<=m; j++){
                    reg_sum += a[i][j]*b[j][k];
                }
                printf("%lld",reg_sum);
                if(k==p){
                    printf("\n");
                }
                else{
                    printf(" ");
                }
                reg_sum = 0;
            }
        }
        printf("\n");
    }
    
 
    return 0;
} 
