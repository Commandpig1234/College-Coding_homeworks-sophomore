#include <bits/stdc++.h>

int N;
double x[100005], y[100005];

double calculate(double px) {
    double max_dist = 0.0;
    for (int i = 0; i < N; i++) {
        double dx = px - x[i];
        double dy = y[i]; // y - 0 = y
        double current_dist = dx * dx + dy * dy;
        if (current_dist > max_dist) {
            max_dist = current_dist;
        }
    }
    return max_dist;
}

int main(){
    
    // freopen("input/ZY14.txt","r",stdin);

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%lf %lf", &x[i], &y[i]);
    }
    double left = -20000.0;
    double right = 20000.0;
    for(int i = 0; i < 100; i++)
    {
        double mid1 = left + (right - left) / 3.0;
        double mid2 = right - (right - left) / 3.0;
        if(calculate(mid1) < calculate(mid2))
        {
            right = mid2;
        }
        else
        {
            left = mid1;
        }
    }
    double min_max_dist = sqrt(calculate(left));
    printf("%.4f\n", min_max_dist);
    
    // freopen("CON","r",stdin);
    // system("pause");

    return 0;
}