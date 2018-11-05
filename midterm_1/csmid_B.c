#include<stdio.h>
int T;
long long int n,x[3];
long long int lcm, gcd_result[3];
long long int gcd(long long int ,long long int );
int main(void){
    int i,j,k;
    scanf(" %d", &T);
    for(i=1;i<=T;i++){
        scanf(" %lld", &n);
        scanf(" %lld", &x[0]);
        scanf(" %lld", &x[1]);
        scanf(" %lld", &x[2]);
    	//printf("%d %d %d\n",x[0],x[1],x[2]);
		x[0] = gcd(n,x[0]);
		x[1] = gcd(n,x[1]);
		x[2] = gcd(n,x[2]);
		x[0] = (x[0]/gcd(x[0],x[1]))*x[1];
		lcm = (x[0]/gcd(x[0],x[2]))*x[2];
		//lcm = gcd_result[0]*gcd_result[1]*gcd_result[2]*x[0]*x[1]*x[2] ;
		//printf("%d %d %d\n", gcd_result[0], gcd_result[1], gcd_result[2]);
		//printf("%d\n", lcm);
		printf("%lld\n",n/lcm);

    }
    
    return 0;
}
long long int gcd(long long int m,long long int n) {
	long long int r;
	if(n>m){
		r=n;
		n=m;
		m=r;	
	}
    while(n != 0) { 
        r = m % n; 
        m = n; 
        n = r; 
    } 
    return m;
}
