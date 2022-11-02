#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void inc_order(float* a1, float* b1, float* c1){

    float a=*a1, b=*b1, c=*c1;
    float temp;

    if(b>a){
        if(c>b){
            
        }else{
            if(c>a){
                temp = b;
                b = c;
                c = temp;
            }else{
                temp = b;
                b = c;
                c = temp;

                temp = b;
                b = a;
                a = temp;
            }
        }
    }else{
        if (c > b){
            if(c > a){
                temp = a;
                a = b;
                b = temp;
            }else{
                temp = b;
                b = a;
                a = temp;

                temp = b;
                b = c;
                c = temp;
            }
        }else{
                temp = c;
                c = a;
                a = temp;
        }
    }

    *a1=a;
    *b1=b;
    *c1=c;
}

int check_triangle(float a, float b, float c){

    if (a + b < c) return 0;
    if (b + c < a) return 0;
    if (c + a < b) return 0;

    return 1;
}

void type_triangle(float a, float b, float c){
    
    a = a*a;
    b = b*b;
    c = c*c;

    float sum = a+b;
    // printf("\nCheck\n: %f %f %f %f\n", a, b, c, sum);

    if(sum > c){
        printf("\nAcute Triangle");}
    else if(sum < c){ 
        printf("\nObtuse Triangle");}
    else{
        printf("\nRight Triangle");
    }
}

void max_angle(float a, float b, float c){

    float temp = ((b*b) + (c*c) - (a*a))/(2*b*c);
    temp *= (3.141592/180);

    float angle = acos(temp);
    angle *= (180/3.141592);

    printf("\nMax Angle is: %f", angle);
}

void main(){

    float a,b,c;

    printf("Enter three numbers\n");
    scanf("%f %f %f", &a, &b, &c);

	inc_order(&a, &b, &c);
    printf("\nInc Order\n: %f %f %f\n", a, b, c);

    if(check_triangle(a, b, c)){
        printf("\nThe sides form a triangle");
        type_triangle(a,b,c);
        max_angle(a,b,c);
    }else{
        printf("\nThe sides do not form a triangle");
    }
}
