#include <iostream>
#include <vector>

using namespace std;

struct stock{
    int invest;
    int interest;
};

long long money;
int year,d;

long long trade(int money,const stock* stocks)
{
    int total = money / 1000;// 1000n $ == n 份钱
    int* income = new int[total+1]{};
    // for (int i = 0; i < d;i++)//每种股
    // {
    //     int v = stocks[i].invest, w = stocks[i].interest;
    //     for (int j = v; j <= total; j++)//（买得起的）每份钱
    //         income[j] = max(income[j], income[j - v] + w);
    // }
    
    for(int j = 1;j<=total;j++){//每份钱
        for(int i = 0;i<d;i++){//每种股
            int v = stocks[i].invest;
            int w = stocks[i].interest;
            if(v <= j){//买的起
                income[j] = max(income[j],income[j-v] + w);
            }
        }
    }
    
    return money + income[total];// $
}

int main()
{
    // freopen("input/ZY25.txt","r",stdin);

    cin >> money >> year >> d;
    stock* stocks = new stock[d];
    
    for (int i = 0; i < d; ++i)
    {
        int invest, interest;
        cin >> invest >> interest;
        invest /= 1000;
        stock new_stock = {invest,interest};
        stocks[i] = new_stock;
    }
    
    while(year--)
        money = trade(money,stocks);
    cout << money << endl;
    delete[] stocks;

    freopen("CON","r",stdin);
    system("pause");
}