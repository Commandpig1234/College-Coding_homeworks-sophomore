/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int n;
int a[maxn];
void findminandmax(int n); // you should finish this
int cmp(int i, int j)
{
	if (i <= 0 || i > 2 * n || j <= 0 || j > 2 * n) return -2;
	if (a[i] > a[j]) return 1;
	if (a[i] == a[j]) return 0;
	if (a[i] < a[j]) return -1;
}

int main()
{
    freopen("input/ZY7.txt","r",stdin);
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n; i++)
		scanf("%d", &a[i]);
	findminandmax(n);
    freopen("CON","r",stdin);
    system("pause");
    return 0;
}

void findminandmax(int n)
{
    int min, max;
    if (cmp(1, 2) == -1) {
        min = 1;
        max = 2;
    } else {
        min = 2;
        max = 1;
    }
    for (int i = 3; i <= 2 * n; i += 2) {
        int first = i, second = i + 1;
        if (second > 2 * n) {
            if (cmp(first, min) == -1) min = first;
            if (cmp(first, max) == 1)  max = first;
            break;
        }
        int cmp_pair = cmp(first, second);
        int smaller, larger;
        if (cmp_pair == -1) {
            smaller = first;
            larger = second;
        } else {
            smaller = second;
            larger = first;
        }
        if (cmp(smaller, min) == -1) min = smaller;
        if (cmp(larger, max) == 1)  max = larger;
    }
    printf("%d %d\n", min, max);
}


/* PRESET CODE END - NEVER TOUCH CODE ABOVE */