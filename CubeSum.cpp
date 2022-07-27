#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(){
	int n,sum=0;
	
	printf("Enter n\n");
	scanf("%d", &n);
	
	for(int i=1; i<=n; i++){
		sum = sum + (i*i*i);
	}
	
	printf("The sum is = %d", sum);
	return 0;
}
