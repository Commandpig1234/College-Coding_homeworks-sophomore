/*  The Art of Computer Programming 
结构的定义 ：struct 名称{ 多组变量定义   }; 定义了一个类型 (int char ...) 
typedef long long LL;[typedef  类型（结构体） 一个类型名] 
pkg[i].name  结构.内含变量 
结构变量赋值相当于内存拷贝：Package a = {214,"zhang",0.0},b;b = a; 
传structure时传指针 

索引查找 :优：查找效率高；劣：浪费空间，要求关键字是比较小的数
散列查找：通过散列函数，将关键字映射为较小的整数，以之为数组下标完成查找。相比索引查找多一个散列函数的时间
散列函数的碰撞	  

数据结构 
队列（Quene）：一入口一出口，先进先出
栈(Stack)：入口出口，先进后出 
链表：基于结构的数据结构  struct linked_node{ int n; linked_node * next; };  

*/
#include <bits/stdc++.h>

typedef struct Package {
	int room;
	char name[20];
	double payment;
} TPackage;
TPackage pkgs[5]={
		{306,"wang",20.0},{127,"li",90.0},{510,"zhao",10.0},{423,"sun",0.0},{214,"zhang",0.0}};
Package*/*返回指针*/ linear_search/*函数名称*/(Package p[],int n,char * tgt){
	for (int i=0;i<n;i++){
		if (strcmp(p[i].name,tgt) == 0){
			return &p[i];
		}
	}
	return NULL;
}

int main(){
	Package * p =  linear_search(pkgs,5,"wang");//在哪查，包裹数，查谁的包裹 
	if (p != NULL)
		printf("%lf\n",p->payment);
	return 0;
}
	
		

