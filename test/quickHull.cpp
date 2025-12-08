#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

// 向量叉积
double cross(Point A, Point B, Point C) {
    return fabs((B.x - A.x) * (C.y - A.y) -
                (B.y - A.y) * (C.x - A.x));
}

// 判断点 C 在 AB 线段的哪一侧（>0 在左侧，<0 在右侧）
double side(Point A, Point B, Point C) {
    return (B.x - A.x) * (C.y - A.y) -
           (B.y - A.y) * (C.x - A.x);
}

// 找到点集中距 AB 最远的点
int farthestPoint(vector<Point>& pts, Point A, Point B) {
    double maxDist = -1;
    int idx = -1;
    for (size_t i = 0; i < pts.size(); i++) {
        double d = cross(A, B, pts[i]);
        if (side(A, B, pts[i]) > 0 && d > maxDist) {
            maxDist = d;
            idx = i;
        }
    }
    return idx;
}

// QuickHull 递归
void quickHullRec(vector<Point>& pts, Point A, Point B,
                  vector<Point>& hull) {
    int idx = farthestPoint(pts, A, B);
    if (idx == -1) {
        hull.push_back(B); // B 是凸包点
        return;
    }

    Point C = pts[idx];

    // 对三角形 ABC 外部区域递归
    vector<Point> left1, left2;
    for (Point p : pts) {
        if (side(A, C, p) > 0) left1.push_back(p);
        if (side(C, B, p) > 0) left2.push_back(p);
    }

    quickHullRec(left1, A, C, hull);
    quickHullRec(left2, C, B, hull);
}

// 快速凸包主函数
vector<Point> quickHull(vector<Point>& pts) {
    if (pts.size() < 3) return pts;

    // 找最左 & 最右点
    int minX = 0, maxX = 0;
    for (size_t i = 1; i < pts.size(); i++) {
        if (pts[i].x < pts[minX].x) minX = i;
        if (pts[i].x > pts[maxX].x) maxX = i;
    }

    Point A = pts[minX], B = pts[maxX];

    vector<Point> leftSet, rightSet;
    for (size_t i = 0; i < pts.size(); i++) {
        if (side(A, B, pts[i]) > 0) leftSet.push_back(pts[i]);
        else if (side(A, B, pts[i]) < 0) rightSet.push_back(pts[i]);
    }

    vector<Point> hull;
    hull.push_back(A);
    quickHullRec(leftSet, A, B, hull);
    quickHullRec(rightSet, B, A, hull);

    return hull;
}

/////// ASCII 可视化 ///////
void visualize(vector<Point>& pts, vector<Point>& hull) {
    const int W = 60, H = 25;
    char grid[H][W];

    // 清空
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            grid[i][j] = ' ';

    // 找范围（做缩放）
    double minX = 1e9, maxX = -1e9, minY = 1e9, maxY = -1e9;
    for (auto& p : pts) {
        minX = min(minX, p.x);
        maxX = max(maxX, p.x);
        minY = min(minY, p.y);
        maxY = max(maxY, p.y);
    }

    auto norm = [&](Point p) {
        int X = (int)((p.x - minX) / (maxX - minX + 1e-9) * (W - 1));
        int Y = (int)((p.y - minY) / (maxY - minY + 1e-9) * (H - 1));
        return pair<int,int>(X, H - 1 - Y); // 翻转 Y 轴
    };

    // 标记所有点
    for (auto& p : pts) {
        auto [X, Y] = norm(p);
        grid[Y][X] = '*';
    }

    // 标记凸包点
    for (auto& p : hull) {
        auto [X, Y] = norm(p);
        grid[Y][X] = '#';  // hull 用 #
    }

    // 打印
    cout << "\n=== ASCII Visualization ===\n";
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++)
            cout << grid[i][j];
        cout << "\n";
    }
}

/////// 主函数 //////
int main() {
    int n;
    cout << "输入点数 n: ";
    cin >> n;

    vector<Point> pts(n);
    cout << "请依次输入 n 个点 (x y):\n";
    for (int i = 0; i < n; i++)
        cin >> pts[i].x >> pts[i].y;

    vector<Point> hull = quickHull(pts);

    cout << "\n凸包点序列（按 QuickHull 顺序）:\n";
    for (auto& p : hull)
        cout << "(" << p.x << ", " << p.y << ")\n";

    visualize(pts, hull);

    system("pause");  // ★ 避免 VSCode 终端关闭
    return 0;
}
