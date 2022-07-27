#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX 1000000

int main(){
	int a=0,b=1,num,c=3, sum=1;
	bool f=false;
	
	double x=b;

	printf("Sequence of x=a_n=1/a_n\n");
	
	while(c<=25){
		printf("\n%d term = %lf",c,x);

		num = a+b;
		sum = sum +num;
		
		a=b;
		b=num;
		x=(double)b/a;
		
		if(num > MAX && f==false){
			printf("Term number is %d", c);
			f=true;
		}

		c++; 
	}

	while(num < MAX){
		num = a+b;
		
		a=b;
		b=num;
		c++;
	}
	
	
	if(f==true){ 
		printf("\nSum of 25 terms = %d",sum); 
	}else{ 
		printf("\nSum of 25 terms = %d\nThe term is = %d",sum, c);
	}
	return 0;
}
