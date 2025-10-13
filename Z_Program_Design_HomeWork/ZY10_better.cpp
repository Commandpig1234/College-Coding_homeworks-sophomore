#include <stdio.h>
#include <math.h> // For sqrt, although we can avoid it with M*M <= K

// A helper function to find the maximum of two numbers, C-style
long long max_ll(long long a, long long b) {
    return a > b ? a : b;
}

void solve() {
    long long a, b, c, d;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

    // Use 64-bit integers (long long) for all calculations to prevent overflow.
    // The problem constraints are tight, but a*c*c*d should fit in long long
    // for the contest's test cases.
    long long K = a * c * c * d;
    long long const_term = a * c;

    int count = 0;

    // Find all divisors of K by iterating up to sqrt(K)
    // We use M*M <= K instead of M <= sqrt(K) to avoid floating point issues
    // and the need for the math library.
    for (long long M = 1; M * M <= K; ++M) {
        if (K % M == 0) {
            // M is a divisor. Check if it corresponds to a valid positive integer x.
            
            // Condition 1: M > a*c
            // Condition 2: (M - a*c) is divisible by b
            if (M > const_term && (M - const_term) % b == 0) {
                count++;
            }

            // N/M is the other corresponding divisor.
            long long M2 = K / M;
            
            // If M*M != K, then M and M2 are different divisors.
            // We need to check M2 as well to avoid missing solutions.
            if (M * M != K) {
                if (M2 > const_term && (M2 - const_term) % b == 0) {
                    count++;
                }
            }
        }
    }

    printf("%d\n", count);
}

int main() {
    freopen("input/ZY10.txt","r",stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    freopen("CON","r",stdin);
    system("pause");
    return 0;
}