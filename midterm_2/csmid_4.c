#include<stdio.h>
char map[1001][1001];
int color[1001][1001] = {0};
int m, n, flag = 0;
void find_road(int ,int );
int main(void){

    int i, j;
    int pos_x, pos_y;
    
    scanf(" %d", &m);
    scanf(" %d", &n);
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf(" %c", &map[i][j]);
            if(map[i][j] == 'e'){
                pos_x = j;
                pos_y = i;
            }
        }
    }
    find_road(pos_y,pos_x);
    flag ? printf("Alive!\n") : printf("Dead!\n") ;
    return 0;
}
void find_road(int y,int x){
    if(flag){
        return ;
    }
    if((x<0 || y<0)||(y>=m || x>=n)){
        return ;
    }
    if(map[y][x] == '^'){
        return ;
    }
    if(color[y][x] == 1){
        return ;
    }
    if(map[y][x] == '~'){
        flag = 1;
        return ;
    }
    color[y][x] = 1;
    find_road(y-1,x);
    find_road(y+1,x);
    find_road(y,x-1);
    find_road(y,x+1);
}