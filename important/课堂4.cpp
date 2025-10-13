/*定义函数 ： 返回值类型 函数名称(函数参数) {content (换行)return 变量} void:返回值为空（没有返回值） 
 声明函数 ： 返回值类型 函数名称（输入参数类型） :bool isPrime(int);
 调用函数 ： 函数名（参数） 
 调用前需要 声明 或 定义 ，一个函数只能定义一次，可声明多次 
 位运算符：二进制的每位的运算 
 a位与b a&b (3 & 5：1{011 & 101}）a|b 位反a ~a(~3 : -4)
 a位异或b a ^ b 将a左/右移b位(×2的b次方) a << b; a >> b(5 << 2:101→10100==20) 
 局部变量：声明后最小的一对大括号；全局变量：声明之后均可使用；函数参数：函数内部 
 指针变量（简称指针）：指向变量的变量，记录了所指向变量储存单元地址
 int* pNum 或int *pNum,*pNum2 
  int* Num1, * Num2 :两个指针变量；  int * Num1,n1,n2:一个指针变量两个普通变量
  指针初始化：int * p = NULL
  int n = 1;
  int* p = &n; 单目&取地址  
  *p = 2//n = 2; 单目* 取指向内容 
*/
#include <stdio.h>

int main(){
	bool isPrime(int);//声明 
	int  n = 0;
	scanf("%d",&n);
//	bool bPrime = isPrime(n);
//	if (bPrime)
	if (isPrime(n))//main中的n赋值给isPrime，执行isPrime函数，isPrime返回值参与if判断 
		printf("Yes\n");
	else 
		printf("No\n"); 
	return 0;
}
bool isPrime(int n) {//输入n判断素数返回bool 
	for (int i = 2;i*i <= n;i++){
		if (n % i == 0)
			return false; 
	}
	return true;
}			
