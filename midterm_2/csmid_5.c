#include<stdio.h>
void draw(char ,int ,int );
void show(int );
int max(int ,int );
int c,f,h;
int s;
char d;
char map[55][55];

int main(void){    
    int i;
    scanf("%d %d %d %d %c",&c,&f,&h,&s,&d);
    for(i=0;i<c;i++){
        map[0][i] = '-';
    }
    for(i=0;i<f;i++){
        map[h+1][i] = '-';
    }
    draw(d,0,s);
    return 0;
}
void draw(char dir, int pos,int height){
    int i;
    if(dir == 'u'){
        for(i=height;i>0;i--){
            map[i][pos] = '*';
            pos++;
        }
        if(pos>c){
            map[0][pos] = '*';
            show(pos);
        }
        else{
            draw('d',pos,2);
        }
    }
    else{
        for(i=height;i<=h;i++){
            map[i][pos] = '*';
            pos++;
        }
        if(pos>f){
            map[h+1][pos] = '*';
            show(pos);
        }
        else{

            draw('u',pos,h-1);
        }
    }
}
void show(int pos){
    int i,j;
    for(i=0;i<=h+1;i++){
        for(j=0;j<=pos;j++){
            if(map[i][j] != '*' && map[i][j] != '-'){
                printf(" ");
            }
            else{
                printf("%c",map[i][j]);
            }
        }
        printf("\n");
    }
}
int max(int a,int b){
    if(a>b){
        return a;
    }
    else {
        return b;
    }
}