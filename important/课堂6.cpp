/* 
数组 
定义：  int number[10]{类型 数组名[变量个数] ；变量个数应是常量，内存中连续存放}  
int number[10] = {0,1,2,3,4,5,6,7,8,9}; 
数组中每一项可作为独立的变量使用、赋值(左值lvalue)
number[0] = 5; scanf("%d",&number[0]);
字符数组——字符串；
char str[10] = "2012"; == char str[10] = {'2','0','1','2','\0'};(9个+'\0')
字符串处理<string.h>： strlen字符串长度（从第0位到\0前一位）；strcpy字符串复制；
strcmp字符串比较；strcat字符串连接 
printf("%s",str);scanf("%s",str){没有&};scanf遇到回车和空格停 
gets(str) puts(str):字符串特殊的输入输出 ,gets遇到换行认为结束，puts自动添加换行 
二维数组：char str[10][100]; 10个最长100的数组 多重大括号 
 多维数组在内存中先变化最后一维，最后变化第一维，所有元素依次排放
 int a[10],int *p = NULL,p=a;p指向a[0]
 (指针)赋值，改变指针指向地址&n;（*指针）赋值，改变指针指向地址的数值n
 指针可用数组的使用思想 (改变数值)
*/
#include <stdio.h>
#include <string.h>
int main(){
	
	int a[10]={1,2,3,4,5,6},*p=&a[3];
	printf("%d\n",*p);
	*p = p[2];
	printf("%d",*p);
	return 0;
}
