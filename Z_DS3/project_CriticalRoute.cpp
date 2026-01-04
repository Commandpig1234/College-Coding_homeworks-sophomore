#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using int_box = vector<int>;

struct Edge{
    int to;
    int w;
};

int n, m;
vector<string> name;
vector<vector<Edge>> G;
vector<int_box> keyG;
int_box indeg, outdeg;
int_box topo;               
int_box ve, vl;
int_box path;        
vector<int_box> paths;

void dfs(int u){
    path.push_back(u);

    if (outdeg[u] == 0){
        paths.push_back(path);
    }
    else{
        for (int i = 0; i < keyG[u].size(); i++){
            dfs(keyG[u][i]);
        }
    }

    path.pop_back();
}

void solve(){

    name.clear();
    G.clear();
    keyG.clear();
    indeg.clear();
    outdeg.clear();
    topo.clear();
    ve.clear();
    vl.clear();
    path.clear();
    paths.clear();

    scanf("%d,%d\n", &n, &m);

    string line;
    getline(cin, line);

    string cur = "";
    for (int i = 0; i < line.size(); i++){
        if (line[i] == ','){
            name.push_back(cur);
            cur.clear();
        }
        else{
            cur += line[i];
        }
    }
    name.push_back(cur);

    G.resize(n);
    keyG.resize(n);
    indeg.assign(n, 0);
    outdeg.assign(n, 0);

    for (int i = 0; i < m; i++){
        int u, v, w;
        scanf("<%d,%d,%d>", &u, &v, &w);
        if (i != m - 1) getchar();

        G[u].push_back({v, w});
        indeg[v]++;
        outdeg[u]++;
    }

    int_box indeg2 = indeg;
    int_box zero;

    for (int i = 0; i < n; i++)
        if (indeg2[i] == 0)
            zero.push_back(i);

    while (!zero.empty()){
        sort(zero.begin(), zero.end());
        int u = zero[0];
        zero.erase(zero.begin());

        topo.push_back(u);

        for (int i = 0; i < G[u].size(); i++){
            int v = G[u][i].to;
            indeg2[v]--;
            if (indeg2[v] == 0)
                zero.push_back(v);
        }
    }

    if(topo.size() != n){
        cout << "NO TOPOLOGICAL PATH" << endl;
        return;
    }

    for (int i = 0; i < topo.size(); i++){
        if (i) cout << "-";
        cout << name[topo[i]];
    }
    cout << endl;

    ve.assign(n, 0);

    for (int i = 0; i < topo.size(); i++){
        int u = topo[i];
        for (int j = 0; j < G[u].size(); j++){
            int v = G[u][j].to;
            int w = G[u][j].w;
            if (ve[u] + w > ve[v])
                ve[v] = ve[u] + w;
        }
    }

    int maxTime = 0;
    for (int i = 0; i < n; i++)
        if (ve[i] > maxTime)
            maxTime = ve[i];

    vl.assign(n, maxTime);

    for (int i = topo.size() - 1; i >= 0; i--){
        int u = topo[i];
        for (int j = 0; j < G[u].size(); j++){
            int v = G[u][j].to;
            int w = G[u][j].w;
            if (vl[v] - w < vl[u])
                vl[u] = vl[v] - w;
        }
    }

    for (int u = 0; u < n; u++){
        for (int j = 0; j < G[u].size(); j++){
            int v = G[u][j].to;
            int w = G[u][j].w;
            if (ve[u] + w == ve[v]){
                keyG[u].push_back(v);
            }
        }
        sort(keyG[u].begin(), keyG[u].end());
    }

    for (int i = 0; i < n; i++){
        if (indeg[i] == 0)
            dfs(i);
    }

    sort(paths.begin(), paths.end());

    for (int i = 0; i < paths.size(); i++){
        for (int j = 0; j < paths[i].size(); j++){
            if (j) cout << "-";
            cout << name[paths[i][j]];
        }
        cout << endl;
    }
    return;
}

int main(){
    // freopen("input/project_CriticalRoute.txt", "r", stdin);

    solve();

    freopen("CON", "r", stdin);
    system("pause");
    return 0;
}
