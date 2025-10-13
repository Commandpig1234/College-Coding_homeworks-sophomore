#include <stdio.h>
#define PI 3.1415926
int main(){
	/*float r = 1.0, c = 0.0, s = 0.0;
	scanf("%f",&r);
	c = 2*r*PI;
	s = r*r*PI;
	printf("%f\n%f",c,s);*/
	int n = 0, sum = 0, sum1 = 0, sum2=0, sum3=0;
	scanf("%d",&n);
	sum1=(3+(n/3*3))*(n/3)/2;
	sum2=(5+(n/5*5))*(n/5)/2;
	sum3=(15+(n/15*15))*(n/15)/2;
	printf("%d",sum1+sum2-sum3);
	
	
	return 0;
}
