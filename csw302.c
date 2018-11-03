#include<stdio.h>
int main(void){
    int n,m,x,y;
    int i,j,k;
    char map[17][17] = {'\0'};
    scanf("%d%d%d%d", &n, &m, &x, &y);
    for(i=0;i<m;i++){
        map[x][i] = '+' ;
    }
    for(i=0;i<n;i++){
        map[i][y] = '+' ;
    }
    map[x][y] = 'S';
    for( i=x-1,j=y-1; i>=0&&j>=0; i--,j--){
        map[i][j] = '*';
    }
    for( i=x+1,j=y-1; i<=m&&j>=0; i++,j--){
        map[i][j] = '*';
    }
    for( i=x-1,j=y+1; i>=0&&j<=n; i--,j++){
        map[i][j] = '*';
    }
    for( i=x+1,j=y+1; i<=m&&j<=n; i++,j++){
        map[i][j] = '*';
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(map[i][j]=='\0'){
                printf("-");
            }
            else{
                printf("%c",map[i][j]);
            }
        }
        printf("\n");
    }

}
