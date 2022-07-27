#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(){
	int num, rem, c=9;
	short bin[10];
	for(int i=0; i<10; i++)
		bin[i]=0;
	
	printf("Enter a number\n");
	scanf("%d", &num);
	
	while(num>0){
		rem = num%2;
		num = num/2;
		bin[c--]=rem;
		
//		if(rem){
//			bin = bin << 1;
//			bin = bin + 1;
//		}else{
//			bin = bin << 1;
//			bin = bin + 0;
//		}
	}
	
	printf("Binary is\n");
	for(int i=0; i<10; i++)
		printf("%d",bin[i]);
	
	return 0;
}

