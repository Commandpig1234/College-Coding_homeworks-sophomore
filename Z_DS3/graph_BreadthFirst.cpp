#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;



void solve(){
    vector<char> vertices;
    vector<vector<int>> adjacents;
    char ch;
    while(cin >> ch){
        if(ch == '*')   break;
        vertices.push_back(ch);
    }

    int n = vertices.size();
    adjacents.resize(n);

    int u,v;
    while(1){
        scanf("%d,%d",&u,&v);
        if(u == -1 && v == -1)  break;
        adjacents[u].push_back(v);
        adjacents[v].push_back(u);
    }

    for(int i=0;i<n;i++){
        sort(adjacents[i].begin(),adjacents[i].end(),greater<int>());
    }

    cout << "the ALGraph is\n";
    for(int i =0;i<n;i++){
        cout << vertices[i];
        for(int a : adjacents[i]){
            cout << " " << a;
        }
        cout << endl;
    }

    vector<bool> visited(n, false);
    queue<int> q;

    cout << "the Breadth-First-Seacrh list:";

    for (int i = 0; i < n; i++){
        if (!visited[i]){
            q.push(i);
            visited[i] = true;

            while (!q.empty()){
                int cur = q.front();
                q.pop();

                cout << "" << vertices[cur];

                for (int next : adjacents[cur]){
                    if (!visited[next]){
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
        }
    }

    cout << endl;

    return;
}

int main(){
    freopen("input/graph_BreadthFirst.txt","r",stdin);

    solve();

    freopen("CON","r",stdin);
    system("pause");
}