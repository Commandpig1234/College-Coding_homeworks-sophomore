#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> data_pair;
bool comp_pair(const data_pair& a,const data_pair& b){
    return a.first < b.first;
}

void solve(){
    int num;
    cin >> num;
    int low = 0,high = num -1;
    int key,index;
    vector<data_pair> records;
    records.reserve(num);
    while(num--){
        cin >> key >> index;
        pair<int,int> record(key,index);
        records.push_back(record);
    }
    sort(records.begin(), records.end(),comp_pair);
    for(data_pair record : records){
        printf("(%d %d)",record.first,record.second);
    }
    cout << endl;
    int mid = (low + high) / 2;
    int target = 0;
    cin >> target;
    while(low <= high){
        if(target > records[mid].first){
            low = mid + 1;
        }
        else if(target < records[mid].first){
            high = mid - 1;
        }
        else{
            printf("(%d %d)\n",records[mid].first,records[mid].second);
            return;
        }
        mid = (low + high) / 2;
    }
    cout << "error\n";
    return;
}

int main(){
    // freopen("input/bisearch.txt","r",stdin);

    solve();

    freopen("CON","r",stdin);
    system("pause");
}