/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n;
bool good[maxn][maxn];
void guessdalao(int n); // you should finish this
int better(int a, int b)
{
	if (a <= 0 || a > n || b <= 0 || b > n) return -1;
	return good[a][b];
}
int main()
{
	freopen("input/ZY8.txt","r",stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			int t;
			scanf("%d", &t);
			good[i][j] = t;
		}
	guessdalao(n);
	freopen("CON","r",stdin);
	system("pause");
    return 0;
}

void guessdalao(int n)
{
	int candidate = 1;
	for(int i =2;i<=n;i++){
		if(better(candidate,i) == 0)
			candidate = i;
	}
	int maybe = candidate;
	for(int i =1;i<=n;i++){
		if(i == maybe)	continue;
		if(better(maybe,i) == 0 || better(i,maybe) == 1){
			printf("-1\n");
			return;
		}
	}
	printf("%d\n",maybe);
	return;
}


/* PRESET CODE END - NEVER TOUCH CODE ABOVE */