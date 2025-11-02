#include <bits/stdc++.h>
/*记下最后一个元素为t
重复做 
	从左边开始找一个比t大的
	
	从右边开始找一个比t小的
	
	交换两个元素
知道每个元素都与t比较过
把t交换到合适的位置
对t左边的元素排序
对t右边的元素排序  

*/

//从小到大

void swap(int *l,int *r){
	int tmp = *l;
	*l = *r;
	*r = tmp;
}

void quick_sort(int* p,int n) {//*p第一位数地址，数的个数 
	if (n<=1) return; 
	int t = p[n-1], l = 0, r = n - 2;//l:第一个，r：倒数第二个 
	do {
		for (;r >= l;l++)
			if(p[l] > t) break;
		for (;r >= l;r--)
			if(p[r] < t) break;
		if (r >= l) swap(&p[l],&p[r]);
	} while (r >= l);
	swap(&p[l],&p[n-1]);	
	quick_sort(&p[0],l);
	quick_sort(&p[l+1],n-l-1);
}


int main(){
	int p[4];
	for (int i = 0;i<=3;i++){
		scanf("%d",&p[i]);
	}
	quick_sort(p,4);
	for(int i = 0;i<=3;i++)
		printf("%d ",p[i]);
	system("pause");
	return 0;
}
