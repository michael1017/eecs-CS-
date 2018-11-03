#include<stdio.h>
int main(void){
    float a,b,c,d;
    scanf(" %f",&a);
    scanf(" %f",&b);
    scanf(" %f",&c);
    if((b/a)==(c/b)){
    	d=(b/a); printf("%g %g",a/d,c*d);
	} 
    else{
    	d=b-a; printf("%g %g",a-d,c+d);
	} 
    return 0;
}
