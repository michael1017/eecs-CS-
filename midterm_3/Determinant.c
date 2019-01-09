#include<stdio.h>
long long int calculate(int n, long long int array[][8]);
int main(void){
    long long int det[8][8];
    long long int sum = 0, temp = 1;
    int n;
    int i, j;
    scanf(" %d", &n);
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf(" %lld", &det[i][j]);
        }
    }
    printf("%lld\n", calculate(n, det));
}
long long int calculate(int n, long long int array[][8]){
    long long int new_array[8][8];
    long long int sum = 0, oper = 1;
    int i;
    int j, k;
    if(n == 1){
        sum = array[0][0];
    }
    else if(n == 2){
        sum = array[0][0]*array[1][1] - array[0][1]*array[1][0];
    }
    else{
        for(i=0; i<n; i++){
            for(j=1; j<n; j++){
                for(k=0; k<i; k++){
                    new_array[j-1][k] = array[j][k];
                }
                for(k=i+1; k<n; k++){
                    new_array[j-1][k-1] = array[j][k];
                }
            }
            sum += oper * array[0][i] * calculate(n-1, new_array);
            oper *= -1;
        }
    }
    return sum;
}