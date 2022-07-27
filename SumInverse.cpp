#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(){
	int n,num;
	float sum=1.0;
	
	printf("Enter n\n");
	scanf("%d", &n);
	
	for(int i=1; i<=n; i++){
		num = i + 2;
		sum = sum + (1/(n*n));
	}
	
	printf("The sum is = %lf", sum);
	return 0;
}
