#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

typedef struct {
    int invest;
    int interest;
    double percent;
} stock;
// typedef struct {
//     int total;
//     int interest;
// } holding;
int year,money,d;
vector<stock> stocks;// arranged in ascending order of interests percent
stack<int> holdings; 

void sell_all(){
    while(!holdings.empty()){
        money += holdings.top();
        holdings.pop();
    }
    return;
}

void trades (){
    sell_all();
    for(int i=0;i<d;i++){
        int num = money / stocks[i].invest;
        money %= stocks[i].invest;
        if(num > 0){
            int holds = num * (stocks[i].invest + stocks[i].interest);
            holdings.push(holds);
        }
    }
}

int main(){
    freopen("input/ZY25.txt","r",stdin);

    cin >> money >> year >> d;//  d stocks
    stocks.resize(d);
    for(int i =0;i<d;i++){
        cin >> stocks[i].invest >> stocks[i].interest;
        stocks[i].percent = (0.0 + stocks[i].interest + stocks[i].invest) / stocks[i].invest;
    }
    sort(stocks.begin(),stocks.end(),[](const stock &a,const stock &b){return a.percent > b.percent;});
    while(year--){
        trades();
    }
    sell_all();
    cout << money << endl;

    freopen("CON","r",stdin);
    system("pause");
}