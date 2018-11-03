#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void *b){
    int A = *(int *)a;
    int B = *(int *)b;
    if(A<B) return -1;
    if(A==B) return 0;
    if(A>B) return 1;
}
int main(void){
    int t,n;
    int nums[10001];
    int i,j;

    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&n);
        for(j=0;j<n;j++){
            scanf("%d", &nums[j]);
        }
        qsort(nums,n,sizeof(int ),cmp);
        for(j=0;j<n;j++){
            printf("%d", nums[j]);
            j==n-1 ? printf("\n") : printf(" ") ;
        }
    }
    
}