#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

double dist(const Point& a, const Point& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

// 处理条带中最多 6 个点的优化检查
double stripClosest(vector<Point>& strip, double d) {
    double minD = d;

    sort(strip.begin(), strip.end(),
         [](const Point &a, const Point &b){ return a.y < b.y; });

    for (int i = 0; i < strip.size(); i++) {
        for (int j = i + 1; j < strip.size(); j++) {
            if (strip[j].y - strip[i].y >= minD) break;
            minD = min(minD, dist(strip[i], strip[j]));
        }
    }
    return minD;
}

// 分治核心函数：points 已按 x 排序
double closestUtil(vector<Point>& points, int l, int r) {
    if (r - l <= 3) { // 小规模直接暴力
        double minD = 1e18;
        for (int i = l; i <= r; i++)
            for (int j = i + 1; j <= r; j++)
                minD = min(minD, dist(points[i], points[j]));
        return minD;
    }

    int mid = (l + r) / 2;
    double midX = points[mid].x;

    double dL = closestUtil(points, l, mid);
    double dR = closestUtil(points, mid + 1, r);
    double d = min(dL, dR);

    // 构造条带
    vector<Point> strip;
    for (int i = l; i <= r; i++) {
        if (fabs(points[i].x - midX) < d)
            strip.push_back(points[i]);
    }

    return min(d, stripClosest(strip, d));
}

// 主入口
double closestPair(vector<Point>& points) {
    sort(points.begin(), points.end(),
         [](const Point &a, const Point &b){ return a.x < b.x; });
    return closestUtil(points, 0, points.size() - 1);
}

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);

    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    double ans = closestPair(points);
    cout << "最短距离 = " << ans << endl;
    system("pause");
    return 0;
}
