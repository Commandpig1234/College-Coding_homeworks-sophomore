#include <bits/stdc++.h>
using namespace std;
/*
卡车是栈；B平台是队列
*/

bool is_done(int N,vector<queue<int>> stations,stack<int> truck)
{
    if(!truck.empty())
        return false;
    for(int i=0;i<N;i++)
    {
        if(!stations[i].empty())
            return false;
    }
    return true;
}

void solve()
{
    int N,S,Q;//N(2<=N<=100) 表示环中站的个数。S(1<=S<=100) 表示货车的最大容量。而 Q(1<=Q<=100) 表示 B 平台所能放置的货物的总数
    cin >> N >> S >> Q;
    vector<queue<int>> stations(N);
    for(int i = 0;i<N;i++)
    {
        int cargo_num = 0;
        cin >> cargo_num;
        for(int j = 0;j<cargo_num;j++)
        {
            int cargo_dest;
            cin >> cargo_dest;
            stations[i].push(cargo_dest);
        }
    }
    stack<int> truck;
    int time = 0;
    int current_station = 0;
    while(true)
    {
        //卸货
        while(!truck.empty())
        {   
            int cargo_dest = truck.top();
            if(cargo_dest == current_station+1)
            {
                truck.pop();
                time++;
            }
            else
            {
                if(static_cast<int>(stations[current_station].size()) < static_cast<int>(Q))
                {
                    stations[current_station].push(cargo_dest);
                    truck.pop();
                    time++;
                }
                else    
                    break;
            }
        }
        //装货
        while(!stations[current_station].empty() && truck.size() < S)
        {
            int cargo_dest = stations[current_station].front();
            truck.push(cargo_dest);
            stations[current_station].pop();
            time++;
        }
        //检查完成
        if(is_done(N,stations,truck))
            break;
        current_station = (current_station + 1) % N;
        time += 2;

    }

    cout << time << endl;
}


int main()
{
    // freopen("input/ZY3-2.txt","r",stdin);

    int SET;
    cin >> SET;
    while(SET--)
    {
        solve();
    }

    // freopen("CON","r",stdin);
    // system("pause");
}