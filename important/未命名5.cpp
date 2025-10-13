 #include <bits/stdc++.h>
int number(char n) {
    int num = (n - '0');
    return num;
}

int main() {
    char A[101], B[101], C[101], OUT[102];
    scanf("%s", A);
    scanf("%s", B);
    int lenA = strlen(A);
    int lenB = strlen(B);
    int max_len = lenA > lenB ? lenA : lenB;

    // 确保A和B长度相同，较短的前面补0
    if (lenA < max_len) {
        for (int i = 0; i < max_len - lenA; i++) {
            strcat(A, "0");
        }
    }
    if (lenB < max_len) {
        for (int i = 0; i < max_len - lenB; i++) {
            strcat(B, "0");
        }
    }

    int ex = 0;
    for (int i = max_len - 1; i >= 0; i--) {
        int sum = number(A[i]) + number(B[i]) + ex;
        OUT[i] = (sum % 10) + '0';
        ex = sum / 10;
    }
    if (ex > 0) {
        OUT[max_len] = ex + '0';
        OUT[max_len + 1] = '\0';
    } else {
        OUT[max_len] = '\0';
    }

    printf("%s", OUT);
    printf("\n");
    return 0;
}
