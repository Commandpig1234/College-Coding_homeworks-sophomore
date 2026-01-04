#include <iostream>
#include <vector>

using namespace std;

int row, col;
int maze[105][105];
bool visited[105][105];
vector<pair<int,int>> path;
bool found = false;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y) {
    if (found)  return;

    visited[x][y] = true;
    path.push_back({x, y});

    if (x == row - 1 && y == col - 1) {
        found = true;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < row &&
            ny >= 0 && ny < col &&
            maze[nx][ny] == 0 &&
            !visited[nx][ny]) {
            dfs(nx, ny);
            if (found)  return;
        }
    }

    path.pop_back();
}

void solve() {
    cin >> row >> col;

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> maze[i][j];

    if (maze[0][0] == 1 || maze[row-1][col-1] == 1) {
        cout << "There is no solution!" << endl;
        return;
    }

    dfs(0, 0);

    if (!found) {
        cout << "There is no solution!" << endl;
        return;
    }

    for (auto &p : path) {
        cout << "<" << p.first + 1
             << "," << p.second + 1 << "> ";
    }
    cout << endl;
    return;
}

int main(){
    // freopen("input/maze_Problem.txt","r",stdin);

    solve();

    freopen("CON","r",stdin);
    system("pause");
}
