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
    int original_num = num; // 保存原始数值
    int low = 0, high = num - 1;
    int key, index;
    vector<data_pair> records;
    records.reserve(num);
    
    while(num--){
        cin >> key >> index;
        pair<int,int> record(key, index);
        records.push_back(record);
    }
    
    sort(records.begin(), records.end(), comp_pair);
    
    // 调试输出
    for(size_t i = 0; i < records.size(); i++){
        data_pair record = records[i];
        printf("(%d %d)", record.first, record.second);
    }
    cout << endl;
    
    int target;
    cin >> target;
    
    // 重置搜索边界
    low = 0;
    high = original_num - 1; // 使用原始数值
    int mid = (low + high) / 2;
    
    while(low <= high){
        mid = (low + high) / 2; // 每次循环都要重新计算mid
        
        if(target > records[mid].first){
            low = mid + 1;
        }
        else if(target < records[mid].first){
            high = mid - 1;
        }
        else{
            printf("(%d %d)", records[mid].first, records[mid].second);
            return;
        }
    }
    cout << "error\n";
}

int main(){
    freopen("input/bisearch", "r", stdin);

    solve();

    // 修正：使用fclose而不是重定向到CON
    freopen("CON","r",stdin);
    system("pause");
    
    // 如果需要在Windows下暂停
    #ifdef _WIN32
    system("pause");
    #endif
    
    return 0;
}