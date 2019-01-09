#include<stdio.h>
#include<stdlib.h>
#define LEFT 1
#define RIGHT -1
#define NONE 0
typedef struct _Line{
    int x;
    int y;
}Line;

int ERROR = 0;
Line line[2000005];
int dots[1001] = {NONE};
int tag[1002] = {0};
int map[1002] = {0};

int cmp(const void* , const void * );
void draw(int );
void set_up(int );
int main(void){
    

    int T, m, n;
    int i, j, k;
    int a, b;
    scanf(" %d", &T);
    for(i=1; i<=T; i++){
        scanf(" %d %d", &n, &m);
        set_up(n);
        for(j=0; j<2*m; j+=2){
            scanf(" %d %d", &a, &b);
            line[j].x = a;
            line[j].y = b;
            line[j+1].x = b;
            line[j+1].y = a;
        }
        qsort(line, 2*m, sizeof(Line), cmp);
        dots[1] = LEFT;
        for(j=0, k=1; j<2*m; j++){
            if(line[j].x == k){
                tag[k] = j;
                //printf("  %d %d\n", k, j);
                k++;
            }
        }tag[k] = 2*m;
        //printf("  %d %d\n", k, 2*m);

        //for(j=1; j<=n; j++){
        //   if(map[j] == 0){
                map[j] = 1;
                draw(1);
        //    }
        //}

        if(ERROR == 1){
            printf("No\n");
        }
        else{
            printf("Yes\n");
        }
        /*
        for(j=0;j<2*m;j++){
            printf("%d %d\n", line[j].x, line[j].y);
        }
        printf("\nLEFT:");
        for(j=1;j<=n;j++){
            if(dots[j] == LEFT) printf(" %d ", j);
        }
        printf("\nRIGHT:");
        for(j=1;j<=n;j++){
            if(dots[j] == RIGHT) printf(" %d ", j);
        }
        printf("\nNONE:");
        for(j=1;j<=n;j++){
            if(dots[j] == NONE) printf(" %d ", j);
        }
        */
    }
    

}
int cmp(const void* A, const void* B){
    const Line* a = (const Line* ) A;
    const Line* b = (const Line* ) B;
    if(a->x > b->x){
        return 1;
    }
    else if(a->x < b->x){
        return -1;
    }
    else{
        if(a->y > b->y){
            return 1;
        }
        else if(a->y < a->y){
            return -1;
        }
        else {
            return 0;
        }
    }
}
void draw(int k){
    int i;
    if(ERROR){
        return ;
    }
    for(i=tag[k]; i<=tag[k+1]-1; i++){
        if(dots[k] == dots[line[i].y]){
            ERROR = 1;
            return ;
        }
        dots[line[i].y] = dots[k] * (-1);
    }
    for(i=tag[k]; i<=tag[k+1]-1; i++){
        if(map[line[i].y] == 0){
            map[line[i].y] = 1;
            draw(line[i].y);
        }
    }

}
void set_up(int n){
    int i;
    //tag array and line array will be washed
    //so we don't need to set_up here
    ERROR = 0;
    for(i=1; i<=n; i++){
        dots[i] = map[i] = 0;
    }
}