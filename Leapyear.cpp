#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(){
	int year;
	bool flag=false;
	
	printf("Enter a year\n");
	scanf("%d", &year);
	
	if(year%4 == 0) flag=true;
	if(year%100 == 0 & year%400 == 0) flag=true;
	
	if(flag) printf("The year is a leap year");
	else printf("The year is not a leap year");
	
	return 0;	
}
