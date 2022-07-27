#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(){
	int sum=0,c=1;
	
	while(sum<10000){
		sum += c++;
	}
	
	printf("N is = %d", --c);
	return 0;
}
