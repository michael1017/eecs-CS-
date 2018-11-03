#include<stdio.h>
void operation(int level,int start , int reg , int destination);
int main(void){
    int height;
    scanf(" %d",&height);
    operation(height ,1 , 2 , 3);
	return 0;
}
void operation(int level ,int start , int reg , int destination){
    if(level == 1){
        printf("1\n");
    }
    else{
        operation(level-1,start,destination,reg);
        printf("%d\n",level);
        operation(level-1,reg,start,destination);
    }
}
