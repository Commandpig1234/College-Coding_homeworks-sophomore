/*
数组续 
折半查找：int low = 0,high = 9左闭右闭 ；low = 0,high = 10：左闭右开
传数组时传输首地址 
数组的指针：
char y[10][20];		char (*p)[20] = y;其中p是20容量数组的char指针，p每+1,地址跳过20个char
char * a[10] 表示一个容量为10的数组a，每一项为一个char指针 
动态分配数组：int *a = (int *)malloc(sizeof(int) * n) 分配n个int内存的地址; free(a);不释放导致内存泄漏， 

confused
二维数组：char (*a)[20] = (char(*)[20])malloc(sizeof(char)*n*20)（“20”处必为常量）
  
*/
// 如果用 char (*a)[20] = (char(*)[20])malloc(sizeof(char)*n*m); 这种方式分配二维数组，不能单独释放某一行，只能整体 free(a)。
// 如果想单独释放每一行，可以用 char **a = (char**)malloc(sizeof(char*)*n); 
// 然后每一行 a[i] = (char*)malloc(sizeof(char)*m); 这样可以 free(a[i]) 单独释放每一行，最后 free(a)。
#include <stdio.h>

/*int main(){//质数筛 
	bool isPrime[101];
	for (int i=2;i<=100;i++){//初始化"筛子"
		isPrime[i] = true;//假设全为质数 
	}
	for (int i=2;i * i <= 100;i++){
		if (isPrime[i]){//用2到sqrt(n)的素数筛 
			for (int j =i * i;j <= 100;j += i){//从i^2开始筛掉i的倍数 
				isPrime[j] = false;//被筛掉的假设不成立 
			}
		}
	}
	for (int i = 2; i <= 100;i++){
		if (isPrime[i]){
			printf("%d\n",i);
		}
	}
	return 0;
}*/
void Bubble(int a[],int n){//参数数组仅传首地址：int a[10];int a[],int n; int *a,int n均可 高维数组首[]中可省 
	for (int i = n-1;i>=0;i--){
		for(int j=0;j<i;j++){
			if(a[j]>a[j+1]){
				int t = a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
}
int main(){//冒泡排序 
	int x[10] = {1,4,2,7,6,3,21,5,8,2};
	int n=0;
	scanf("%d",&n);
	Bubble(x,n);
	for (int i= 0;i<=n-1;i++){
		printf("%d%c",x[i]," \n"[i>=n-1]);
	}
	return 0;
}

