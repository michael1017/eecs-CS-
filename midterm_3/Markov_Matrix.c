#include<stdio.h>
#include<stdlib.h>
int main(void){
    int T, n;
    float resident[6];
    float resident_temp[6];
    int i, j, k, h;
    float matrix[6][6];
    float temp = 0, p;
    int times;
    scanf(" %d", &T);
    for(i=0; i<T; i++){
        scanf(" %d", &n);
        for(j=1; j<=n; j++){
            for(k=1; k<=n; k++){
                scanf(" %f", &matrix[j][k]);
            }
        }
        for(j=1; j<=n; j++){
            scanf(" %f", &resident[j]);
        }
        scanf(" %f", &p);
        for(h = 0; h<10000; h++){
            //printf("  %f %f\n", resident[1], p);
            if(resident[1] <= p){
                times = h;
                break;
            }
            for(j=1; j<=n; j++){
                for(k=1; k<=n; k++){
                    temp += matrix[j][k] * resident[k];
                }
                resident_temp[j] = temp;
                temp = 0;
            }
            for(k=1; k<=n; k++){
                resident[k] = resident_temp[k];
            }
        }
        if(h == 10000){
            printf("Never\n");
        }
        else{
            printf("%d\n", times);
        }
    }
    return 0;
}