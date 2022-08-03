#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

void check_prime(){
	
	int num,i;
	bool prime=true;
	
	printf("Enter a number\n");
	scanf("%d",&num);
	
	for(i=2; i<=(num/2);i++){
		if(num%i==0){
			prime=false;
			break;
		}
	}
	
	if(prime) printf("Number is prime\n");
	else printf("Number is not prime\n");
	
}

void print_factors(){
	
	int num,i;
	bool prime=true;
	
	printf("Enter a number\n");
	scanf("%d",&num);
	printf("The factors are:\n");
	
	for(i=2; i<=(num/2);i++){
		if(num%i==0){
			printf("%d ",i);
		}
	}
	
}

typedef struct{
	double x;
	double ep;
	double (*conv)(double,double);
}seq;

double inverse(double num, double prev){
	return prev/num;
}


void limit_x_inverse(seq s){
	
	double num, ep=0.000001, prev, x;
	
	printf("Enter a number\n");
	scanf("%lf",&x);
	
	num  = 1/x;
	prev = x;
	
	while((prev-num) > ep){
//	while(c++<10){
		printf("%lf ", num);
		prev = num;
		num = num/x;
	}
	
}

void limit_seq(seq *s){
	
	double prev, num, temp;
	
	num  = 1/(seq->x);
	prev = seq->x;
	
	while((prev-num) > seq->ep){
		printf("%lf ", num);
		
		temp = prev;
		prev = num;
		num = (seq->conv)(seq->x, temp);
	}
	
}


int main(){
	
	seq inv;
	inv.x = 2;
	inv.ep = 0.00001;
	inv.conv = &inverse;
	
//	check_prime();
//	print_factors();
//	limit_x_inverse();
	limit_seq(&inv);
	
	return 0;
}
