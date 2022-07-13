#include <stdio.h>
#include <stdbool.h>

short and(short a, short b){
	return a&b;
}
short or(short a, short b){
	return a|b;
}
short xor (short a, short b) {
	return a^b;
} 
unsigned short not(unsigned short a)
{
	return ~a;
}

void truth_table(char op, short (*opf) (short, short)){
	short a=0,b=0;

	printf("\n\n\tTruth Table For %c\n",op);
	printf("a\t\tb\t\ta %c b\n", op);
	printf("-----------------------------------------------\n");
	printf("%d\t\t%d\t\t%d\n",a,b,opf(a,b)); ++b;
	printf("%d\t\t%d\t\t%d\n",a,b,opf(a,b)); ++a; --b;
	printf("%d\t\t%d\t\t%d\n",a,b,opf(a,b)); b++;
	printf("%d\t\t%d\t\t%d\n",a,b,opf(a,b));
}

void truth_table_unary(char op, unsigned short (*opf)(unsigned short))
{
	unsigned short a=0;

	printf("\n\n\tTruth Table For %c\n",op);
	printf("a\t\t a%c\n", op);
	printf("-----------------------------------------------\n");
	printf("%d\t\t%d\n",a,opf(a)); a++;
	printf("%d\t\t%d\n",a,opf(a));
}

void do_something(){
	
	int a=45,b,c;
	float x=10.4,y;
	
	b = a++;
	c = ++a;
	y = x--;
	
	printf("a=%d b=%d c=%d x=%lf y=%lf",a,b,c,x,y);	
}

void ternary(){

	int a,b,c, res;
	scanf("%d %d %d", &a,&b,&c);

	res = (a>b)?(c>a)?c:(c>b)?a:b : 0;
	printf("\n%d",res);

}

void xor_swap(int *a, int *b){

	*b = *a^*b;
	*a = *b^*a;		//swap b to a
	
	*b = *a^*b;		//swap a to b

}

void main(){

	// truth_table('&', &and);
	// truth_table('|', &or);
	// truth_table('^', &xor);
	// truth_table_unary('~', &not);

	// ternary();

	//xor xwap
	int a=13, b=6;
	xor_swap(&a,&b);
	printf("a=%d b=%d",a,b);
}
