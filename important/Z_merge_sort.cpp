#include <stdio.h>
#include <stdlib.h>
void swap(int *l,int *r){
	int tmp = *l;
	*l = *r;
	*r = tmp;
}

void merge_sort(int *p,int n){
	if(n<=1) return;
	int l = n/2,r = n- n/2;//把数组分成两份 
	merge_sort(p,l);//对左边排序 
	merge_sort(p+l,r);//对右边排序 
	int * pn = (int*)malloc(sizeof(int) * n);//申请新数组 
	int i = 0,j = l,k = 0;
	while(i<l && j<n){
		if(p[i] > p[j])
			pn[k++] = p[j++];
		else
			pn[k++] = p[i++];
	}
	for(;i<l;i++) pn[k++] = p[i];
	for(;j<n;j++) pn[k++] = p[j];
	for(int i = 0;i<n;i++)	p[i] = pn[i];
	free(pn);
}

int main(){
	int p[10];
	int n=0;
	scanf("%d",&n);
	for (int i = 0;i<n;i++){
		scanf("%d",&p[i]);
	}
	merge_sort(p,n);
	for(int i = 0;i<n;i++)
		printf("%d ",p[i]);
	system("pause");
	return 0;
}
