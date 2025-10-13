/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
#define N 1000000
#define MaxNum 1000000000

int S1[N],S2[N],S3[N];

int DiffWeight(int i, int j, int k){
    return abs(S1[i] - S2[j]) + abs(S2[j] - S3[k]) + abs(S3[k] - S1[i]);
}
// 返回S1[i],S2[j],S3[k]中最小的序号
// 返回i表示Si对应的数最小
int xls_min(int i, int j, int k){
    if(S1[i] <= S2[j]){
        if(S1[i] <= S3[k]){
            return 1;
        }
        return 3;
    }
    else{
        if(S2[j] <= S3[k]){
            return 2;
        }
        return 3;
    }
}

// n -> 集合的大小
int findMinDiffWeight(int n);

int main()
{
    // freopen("input/ZY6.txt","r",stdin);
    int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &S1[i]);
    for (int i = 0; i < n; i++)
		scanf("%d", &S2[i]);
    for (int i = 0; i < n; i++)
		scanf("%d", &S3[i]);
	printf("%d\n", findMinDiffWeight(n));
    system("pause");
    return 0;
}

int findMinDiffWeight(int n)
{
    int i=0,j=0,k=0;
    int MINDIF = DiffWeight(i,j,k);
    while(i+j+k<=(n-1)*3){
        if(MINDIF>0){
            int change = xls_min(i,j,k);
            if(change == 1)
                i++;
            else if(change == 2)
                j++;
            else
                k++;
            int DIF = DiffWeight(i,j,k);
            if(MINDIF>DIF)
                MINDIF = DIF;
            if(MINDIF == 0)
                return MINDIF;
        }
    }
    return MINDIF;
}


/* PRESET CODE END - NEVER TOUCH CODE ABOVE */