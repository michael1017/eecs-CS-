#include<stdio.h>
#include<stdlib.h>
typedef struct list{
    char name[23];
    int score;
    int num;
}List;
int cmp(const void *, const void *);
int main(void){
    int i,t;
    List student[10005];
    scanf(" %d", &t);
    for( i=0; i<t; i++){
        scanf(" %s", student[i].name);
        scanf(" %d", &student[i].score);
        student[i].num = i;
    }
    qsort(student, t, sizeof(List), cmp);
    for( i=0; i<t; i++){
        printf("%s\n", student[i].name);
    }
    return 0;
}
int cmp(const void *a, const void *b){
    const List * A = (const List *) a;
    const List * B = (const List *) b;
    if (A->score > B->score){
        return -1;
    }
    else if (A->score < B->score){
        return 1;
    }
    else{
        if(A->num < B->num){
            return -1;
        }
        else{
            return 1;
        }
    }
}