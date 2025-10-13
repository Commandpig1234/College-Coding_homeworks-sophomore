/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <bits/stdc++.h>
using namespace std;
int x, n;
void guessnumber(int n); // you should finish this
int guess(int y)
{
	if (y < 1 || y > n) return -1;
	if (x >= y) return 1;
	if (x < y) return 0; 
}
int main()
{
	scanf("%d%d", &x, &n);
	guessnumber(n);
    system("pause");
    return 0;
}
void guessnumber(int n)
{
    int l=1,r=n,mid;
    while(l<=r){
        mid = ((long long)(l+r))/2;
        if(guess(mid)==1) l=mid+1;
        else r=mid-1;
    }
    printf("%d\n",l-1);
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */