#include <stdio.h>
#include <math.h>
#include <stdbool.h>

typedef struct _SEQ_{
    double x;
    double ep;
    double (*conv)(double, double, double,double);
} seq;

double pow_inverse(double num, double prev, double none, double x){
    return prev / x;
}

double pow_fact(double num, double prev, double i, double x){
    return ((prev*x)/i);
}

void limit_seq(seq *s){

    double prev, num, temp;
    int n=1;

    num = (s->conv)(s->x, 1, n, s->x);    
    prev = s->x;

    while ((fabs(prev - num) > s->ep) && n<50){
        printf("\n%d = %lf ", n, num);
        n++;

        temp = prev;
        prev = num;
        num = (s->conv)(num, temp, n, s->x);
    }

    if (n == 50)
        printf("The sequence is perhaps divergent");
    else{
        printf("\nThe sequence is expected to converge with tolerance level %.9f",s->ep);
        printf("\nLimit=%f after %d terms", num,n);
    }
}

int main(){
    
    seq inv;

    inv.ep = 0.0001;
    inv.x = 2.0;
    inv.conv = pow_inverse;

    limit_seq(&inv);
    

    // float ep, x, term, term1, d;
    // int n;

    // x=2.1;
    // n=1;
    // ep=0.001;
    // term=0;

    // printf("Term num \t\t Term");

    // do{
    //     term1 = (n*n*n + 3*n + 2.0)/(2*n*n + 5);
    //     d = fabs(term-term1);

    //     term = term1;
    //     printd("\n%d \t\t %f",n,term);

    //     n++;
    // }while(d>ep && n<50);

    // if(n==50)
    //     printf("The sequence is perhaps divergent");
    // else{
    //     printf("\nThe sequence is expected to converge with tolerance level %.9f",ep);
    //     printf("\nLimit=%f after %d terms", term,n);
    // }

    return 0;
}
