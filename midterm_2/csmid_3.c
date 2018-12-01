#include<stdio.h>
char map[1001][1001];
int color[1001][1001] = {0};
int len, wid;
int pond = 0;
void find(void);
void coloring(int ,int );
int main(void){
    int i, j;
    scanf(" %d", &len);
    scanf(" %d", &wid);
    for(i=0;i<len;i++){
        for(j=0;j<wid;j++){
            scanf(" %c", &map[i][j]);
        }
    }
    find();
    printf("%d\n",pond);
    return 0;
}
void find(void){//y = len  , x = wid
    int i,j;
    for(i=0;i<len;i++){
        for(j=0;j<wid;j++){
            if(map[i][j] == '~' && color[i][j] == 0){
                pond++;
                coloring(i,j);
            }
        }
    }
}
void coloring(int y,int x){
    if((x<0 || y<0)||(y>=len || x>=wid)){
        return ;
    }
    if(map[y][x] == '.'){
        return ;
    }
    if(color[y][x] == 1){
        return ;
    }
    color[y][x] = 1;
    coloring(y+1,x);
    coloring(y-1,x);
    coloring(y,x+1);
    coloring(y,x-1);
}