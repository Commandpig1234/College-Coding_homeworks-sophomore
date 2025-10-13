#include <stdio.h>

void print_digit(int x){
	if (x < 10)
		printf("%d",x);
	else if (x < 10 + 26)
		printf("%c",(char)(x - 10 + 'a'));
	else 
		printf("%c",(char)(x -10 -26 + 'A'));
}

void print_number(int x,int r){
	if (x >= r)
		print_digit(x/r);
	print_digit(x % r);
}
	
void print_factor(int r,int x,int y){
	print_digit(x);
	printf("*");
	print_digit(y);
	printf("=");
	if (x * y < r)
		printf(" ");
	print_number(x * y,r);
}
	
void print_line (int radix,int x){
	for (int y = 1;y <= x;y++){
		print_factor(radix,x,y);
		if (y == x)
			printf("\n");
		else
			printf(" ");
		}
}

void print_table (int radix){//radix = n radix进制 
	for (int x = 1;x < radix;x++){
		print_line(radix,x);//x为参数的radix行 
	}
}

int main(){
	int n = 0;
	scanf("%d",&n);
	print_table(n);
	return 0;
}

