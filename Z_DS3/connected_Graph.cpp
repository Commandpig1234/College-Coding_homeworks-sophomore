#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> adj_list;
vector<int> connect;
vector<vector<int>> connes;
vector<bool> visited;

void bfs(int u){
    queue<int> q;
    visited[u] = true;
    q.push(u);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        connect.push_back(u);
        for(int v : adj_list[u]){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void solve(){
    int n;
    cin >> n;
    adj_list.resize(n);
    visited.assign(n,false);
    int inp1 = 0,inp2 = 0;
    while(1){
        scanf("%d",&inp1);
        if(inp1 == -1)   break;
        else{
            scanf("%d",&inp2);
            adj_list[inp1].push_back(inp2);
            adj_list[inp2].push_back(inp1);
        }
    }
    for(int i = 0;i<n;i++)
        sort(adj_list[i].begin(),adj_list[i].end());

    for(int i = 0;i<n;i++){
        if(!visited[i]){
            bfs(i);
            connes.push_back(connect);
            connect.clear();
        }
    }
    for(auto &a : connes){
        bool first = true;
        for (auto &b : a){
            if(first){
                cout << b;
                first = false;
            }
            else{
                cout << "-" << b;
            }
        }
        cout << endl;
    }
    return;
}

int main(){
    // freopen("input/connected_Graph.txt","r",stdin);

    solve();

    freopen("CON","r",stdin);
    system("pause");
}