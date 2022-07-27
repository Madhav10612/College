#include <stdio.h>
#include <stdbool.h>
#include <math.h>


void find_max(){
    int a,b,c,max;

    printf("Enter Three Numbers");
    scanf("%d %d %d", &a, &b, &c);

    max = a;
    if(max < b){ max = b; }
    if(max < c){ max = c; } 

    printf("The maximum is %d",max);
}

void sum(){

    int sum=0,n;

    printf("Enter n\n");
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        sum = sum + i;
    }

    printf("\nSum is = %d", sum);
}


int main(){

    // find_max();

    sum();
    
    return 0;
}
