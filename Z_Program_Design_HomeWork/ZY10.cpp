#include <bits/stdc++.h>

int main() {
    // freopen("input/ZY10.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while (T--) {
        long long a, b, c, d;
        scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
        int count = 0;

        long long cd = c * d;
        long long y_limit = (cd - 1) / b; 

        for (long long y = 1; y <= y_limit; ++y) {
            long long numerator = a * c * y;
            long long denominator = cd - b * y;

            if (numerator % denominator == 0) {
                count++;
            }
        }
    printf("%d\n",count);
    }
    // freopen("CON","r",stdin);
    // system("pause");
    return 0;
}