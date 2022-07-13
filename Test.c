#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    double one;
    double two;
} roots;

void *quad(double a, double b, double c, roots *r){
    double sq = (b*b) - (4*a*c);
    r->one = (b + sqrt(sq))/a;
    r->one = (b - sqrt(sq))/a;
}

void sum(){
    double a, b, c;
    printf("Enter 3 numbers\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    printf("\nSum is = %lf", a + b + c);
    printf("\nProduct is = %lf", a * b * c);
}

int main(){
    int a = 1, b =0, c=3;

    if(a || b) printf("Or");
    if(a && b) printf("And");

    printf("\nhello World!");
    return 0;
}

