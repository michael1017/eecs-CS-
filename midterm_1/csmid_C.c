#include<stdio.h>
long long int x[105], y[105];
int line = 0;
int t,n;
void find_line(int ,int );
int main(void){
    int i,j,k,q;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d",&n);
        for(j=0;j<n;j++){
            scanf("%lld",&x[j]);
            scanf("%lld",&y[j]);
        }
        for(j=0;j<n-2;j++){
            for(k=j+1;k<n-1;k++){
                //printf("(%d,%d) (%d,%d)\n",x[j],y[j],x[k],y[k]);
                find_line(j,k);
                //printf("\n\n");
            }
        }
        printf("%d\n",line);
        line = 0;
    }

}
void find_line(int j,int k){
    int m;
    long long int f0,f1,f2,f3;
    int flag = 0;
    f0 = x[k] - x[j];
    f1 = y[j];
    f2 = y[k] - y[j] ;
    f3 = x[j];
    for(m=k+1;m<n;m++){
        if( f0*(y[m]-f1) == f2*(x[m]-f3)){
            flag = 1;
            break;
        }
    }
    for(m=0;m<k;m++){
        if(m==j) continue ;
        if( f0*(y[m]-f1) == f2*(x[m]-f3)){
            flag = 0;
            break;
        }
    }
    if(flag == 1){
        line++;
    }
    return ;
}     
