#include<stdio.h>
#include<stdlib.h>
int ans = 0;
void step_counter(int );
int main(void){
    int N;
    int steps = 40;
    int i,j,k;
    scanf(" %d", &N);
    for( i=1; i<=N; i++){
       scanf(" %d", &steps);
        step_counter(steps);
        printf("%d\n",ans);
        ans = 0;
    }
}
void step_counter(int steps_left){
    if(steps_left>=2){
        step_counter(steps_left-2);
        step_counter(steps_left-1);
    }
    else{
        ans++;
    }
}
