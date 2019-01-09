#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _Factory{
    char *name;
    int car1;
    int car2;
}Factory;
int cmp(const void* , const void* );
int take_car1(const void* , const void* );
int take_car2(const void* , const void* );
int dic_sort(const void*, const void *);
int main(void){
    int n, x, y;
    int i, j, k;
    int max_case;
    long long int max_sum = 0;
    long long int max_car = 0;
    long long int temp_sum;
    long long int temp_car;
    Factory list[600];
    scanf(" %d %d %d", &n, &x, &y);
    for ( i=0; i<n; i++){
        char *name_in;
        name_in = (char* )malloc(sizeof(char )*25);
        scanf("%s %d %d", name_in, &list[i].car1, &list[i].car2);
        list[i].name = name_in;
    }
    for (i = x; i <= n - y; i++) {
        temp_sum = 0;
        temp_car = 0;
        qsort(list, n, sizeof(Factory), cmp);
        qsort(list, i, sizeof(Factory), take_car1);
        qsort(list + i + 1, n - i, sizeof(Factory), take_car2);
        for ( j=0; j<x; j++){
            temp_sum += list[j].car1;
            temp_car += list[j].car1;
        }
        for ( j=n-y; j<n; j++){
            temp_sum += list[j].car2;
        }
        if(temp_sum > max_sum){
            max_sum = temp_sum;
            max_car = temp_car;
            max_case = i;
        }
        if(temp_sum == max_case && temp_car > max_car){
            max_car = temp_car;
            max_case = i;
        }
    }
    qsort(list, n, sizeof(Factory), cmp);
    qsort(list, max_case, sizeof(Factory), take_car1);
    qsort(list + max_case + 1, n - max_case, sizeof(Factory), take_car2);
    qsort(list, x, sizeof(Factory), dic_sort);
    for ( j=0; j<x; j++){
        printf("%s\n", list[j].name);
    }
    for (j=0; j<n; j++){
        free(list[j].name);
    }
    

}
int cmp(const void *A, const void *B){
    const Factory* a = (const Factory* ) A;
    const Factory* b = (const Factory* ) B;
    if (a->car1 - a->car2 > b->car1 - b->car2) {
        return -1;
    }
    else if (a->car1 - a->car2 < b->car1 - b->car2){
        return 1;
    }
    else {
        if(a->car1 > b->car1){
            return -1;
        }
        else if(a->car1 < b->car1){
            return 1;
        }
        else {
            return strcmp(a->name, b->name);
        }
    }
}
int take_car1(const void* A, const void* B){
    const Factory* a = (const Factory *)A;
    const Factory* b = (const Factory *)B;
    if(a->car1 > b->car1){
        return -1;
    }
    else if(a->car1 < b->car1){
        return 1;
    }
    else{
        return strcmp(a->name, b->name);
    }

}
int take_car2(const void* A, const void* B){
    const Factory* a = (const Factory *)A;
    const Factory* b = (const Factory *)B;
    if(a->car2 > b->car2){
        return 1;
    }
    else if(a->car2 < b->car2){
        return -1;
    }
    else{
        return strcmp(a->name, b->name);
    }
}
int dic_sort(const void* A, const void* B){
    const Factory* a = (const Factory *)A;
    const Factory* b = (const Factory *)B;
    return strcmp(a->name, b->name);
}