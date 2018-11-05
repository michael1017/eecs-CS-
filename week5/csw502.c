#include <stdio.h>
#define MAXNV 5
int DONE = 0;
int liters[MAXNV];
int numbers[MAXNV];
void show(int nv);
void filling(int amount, int cur, int nv);
int j=0;
int water;
int min=100000000;
int min_numbers[MAXNV]={0};
int main(void)
{
    int nv, i;

    scanf("%d", &nv);
    for (i=0; i<nv; i++) {
        scanf("%d", &liters[i]);
    }
    scanf("%d", &water);
    filling(water, 0, nv);

    for(i=0;i<nv;i++)
        numbers[i]=min_numbers[i];
    show(nv);
    return 0;
}

void show(int nv)
{
    int i;
    printf("(%d", numbers[0]);
    for (i=1; i<nv; i++) {
        printf(",%d", numbers[i]);
    }
    printf(")\n");
}

void filling(int amount, int cur, int nv)
{
   int i;
    if(amount==cur){
    	if(DONE<min){
    		for(i=0;i<nv;i++){
    			min_numbers[i] = numbers[i];
			}
			min =DONE; 
		}
		return ;
	}
	if(DONE>min){
		return ;
	}
	for(i=0;i<nv;i++){
		if((cur+liters[i])<=amount){
			numbers[i]++;
			DONE++;
			filling(amount,cur+liters[i],nv);
			DONE--;
			numbers[i]--;
			
		}
	}
}