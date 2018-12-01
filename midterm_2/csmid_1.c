#include<stdio.h>
#include<string.h>
char s[21],t[21];
int slen, tlen;
int cases = 0;
void comp(int ,int );
int main(void){    
    while(scanf(" %s",s)!=EOF){
        scanf(" %s",t);
        cases = 0;
        slen = strlen(s);
        tlen = strlen(t);
        if(slen < tlen){
            printf("0\n");
        }
        else{
            comp(0,0);
            printf("%d\n",cases);
        }
    }
}
void comp(int start,int find){
    int i;
    if(start>=slen || find>=tlen){
        cases++;
        return ;
    }
    for(i=start;i<slen;i++){
        if(s[i] == t[find]){
            comp(i+1,find+1);
        }
    }
}