#include <stdio.h>
#include <ctype.h>

float calculate(void);

int main(void)
{
    printf("%.3f\n", calculate());
    return 0;
}

float calculate(void)
{
    char c;
    float ans;
    float op1, op2;

    c = getchar();
    if (c=='+') {
        op1 = calculate();
        op2 = calculate();
        ans = op1 + op2;
    } else if (c=='-') {
        op1 = calculate();
        op2 = calculate();
        ans = op1 - op2;
    } else if (c=='*') {
        op1 = calculate();
        op2 = calculate();
        ans = op1 * op2;
    }else if (c=='/'){
        op1 = calculate();
        op2 = calculate();
        ans = op1 / op2;
    }else if (isdigit(c)) {
        ans = c - '0' ;
    }else{
        printf("ERROR\n");
    }

    return ans;

}