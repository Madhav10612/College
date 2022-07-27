#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(){
	int num, max,min, n=10;
	
	printf("Enter the numbers one by one\n");
	scanf("%d",&num);
	
	max = num;
	min = num;
	
	for(int i=1; i<=n; i++){
		
		scanf("\n%d", &num);
		if(max < num) max = num;
		if(min > num) min = num;
		
	}
	
	printf("\nThe maximum is = %d\nThe minimum is = %d", max,min);
	return 0;
}
