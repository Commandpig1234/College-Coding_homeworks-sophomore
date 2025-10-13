#include <stdio.h>
#include <math.h>

//变量类型 bool真(非0)/假(0)  char字符1字节-128~127  先定义再使用 
//int整数4字节-2^31~2^31-1  double浮点数8字节 ±尾数*2^指数 1~2-2^-52 -1022~1023 
//变量名必须是标识符，字母或下划线开头，由字母、下划线、数字组成，区分大小写，不能与关键字重名 
//常量，一般不占用储存空间，有类型(int double char:'A' bool:true)
//定义常量 #define 标识符 文本 (定义后文本替换)
//输入：scanf("%d",&a) &变量 %与printf相似 
//printf("%%")每两个%输出一个字符% 每两个\\输出一个字符\ 
//赋值： 变量名 = 表达式  是覆盖过程 
int main(){
	double a = 0, b = 0, c = 0, d = 0;//变量初始化 变量定义：类型 变量名 初始化 
	scanf("%f%f%f%f",&a,&b,&c,&d);
	//printf("%d",PI);
	//printf("%d",a+b+c*d);
	//printf("%d",a+b+(c*d));
	printf("%f",a*b);
	return 0;
}
