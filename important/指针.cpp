#include <stdio.h>
void swap1(int *x,int *y){
	int temp = *y;
	*y = *x;
	*x = temp;
}

int main(){
	int m=0,n=0;
	scanf("%d%d",&m,&n);
	printf("%d ,%d\n",m,n);
	swap1(&m,&n);
	printf("%d ,%d",m,n);
	return 0;
}
