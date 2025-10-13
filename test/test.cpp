#include <stdio.h>
#include <windows.h>

int main(){
	int n,r;
	scanf("%d%d",&n,&r);
	int *a = (int*)malloc(sizeof(int)*n);
	int *b = (int*)malloc(sizeof(int)*n);
	int *dif = (int*)malloc(sizeof(int)*n);
	long long dif_total = 0;
	int is_dif = 0;
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for (int i=0;i<n;i++){
		scanf("%d",&b[i]);
		if(a[i]!=b[i]){
			dif[is_dif] = abs(b[i]-a[i]);
			dif_total += dif[is_dif];
			is_dif ++;
		}
	}
	if(is_dif > 0)
		qsort(dif, is_dif, sizeof(int), [](const void* a, const void* b) {
			return (*(int*)a) - (*(int*)b);
		});//从小到大
	if(dif_total<=r){//dif全部变为0
		printf("0\n");
	}
	else{//dif_total > r，dif无法全变为0
		int dif_dif = 0,last_sum = 0,dif_dif_sum = 0;
		long long answer = 0;
		for(int i = is_dif-1;i>0;i--){
			dif_dif = dif[i]-dif[i-1];//尝试“抹平”dif间的差距
			if(dif_dif_sum != 0)
				last_sum = dif_dif_sum;
			dif_dif_sum += dif_dif*(is_dif - i);//抹平dif_dif所需的总资源
			if(dif_dif_sum > r){//无法抹平,用last_sum抹平至与dif[i]相等
				int r_left = r - last_sum;//dif[i]~dif[is_dif-1]均为dif[i]
				for(int j = is_dif-1;j>=i;j--){
					dif[j] = dif[i];
				}
				if(r_left > 0){
					int times = r_left / (is_dif - i);
					int remain = r_left % (is_dif - i);
					for (int j = is_dif-1;j>i;j--){
						
						dif[j] -= times;
					}
					for (int j = i;j<i+remain;j++){
						dif[j]--;
					}
					break;
				}
			}
		}
		if(dif_dif_sum == r){//正好抹平
			for(int j = is_dif-1;j>0;j--){
				dif[j] = dif[0];
			}
		}
		else{//dif_dif_sum < r，继续抹平
			for(int j = is_dif-1;j>0;j--){
				dif[j] = dif[0];
			}
			int times = (r - dif_dif_sum) / is_dif;
			int remain = (r - dif_dif_sum) % is_dif;
			for (int j = is_dif-1;j>0;j--){
				dif[j] -= times;
			}
			for (int j = 0;j<remain;j++){
				dif[j]--;
			}
		}
		for (int i=0;i<is_dif;i++){
			answer += dif[i]*dif[i];
		}
		printf("%lld\n",answer);
	}
	free(a);
	free(b);
	free(dif);
	return 0;
}