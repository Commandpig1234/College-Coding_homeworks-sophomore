#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve(){
    int length;
    int S,T,num;
    cin >> length >> S >> T >> num;
    vector<int> stones(num);

    const int INF = num + 1;
    const int compress_dist = S*T;

    for(int i = 0;i<num;i++){
        cin >> stones[i];
    }
    sort(stones.begin(),stones.end());
    int final_stepped = 0;
    if(S == T){
        for(int i = 0;i<num;i++){
            if(stones[i] % S == 0)
                final_stepped++;
        }
        cout << final_stepped << endl;
        return;
    }

    vector<int> compressed_stones;  //  压缩空桥
    compressed_stones.push_back(0);// “起点”
    
    int last_stone = 0;
    for (int i =0;i<num;i++){
        int cur_stone = stones[i];
        int dist = cur_stone - last_stone;
        int compressed_dist = min(dist, compress_dist);
        compressed_stones.push_back(compressed_stones.back() + compressed_dist);
        last_stone = cur_stone;
    }

    int compressed_last = compressed_stones.back();
    int max_len = compressed_last + T;

    vector<int> minimum(max_len, INF);
    minimum[0] = 0;

    vector<bool> is_stone(max_len,false);
    for (int i = 1; i <= num; i++){
        is_stone[compressed_stones[i]] = true;
    }

    for (int i = 1; i < max_len; i++){
        for (int j = S; j <= T; j++){
            if (i >= j){
                minimum[i] = min(minimum[i], minimum[i - j]);
            }
        }
        if (is_stone[i]){
            minimum[i]++;
        }
    }

    int result = INF;
    for (int i = compressed_last; i < max_len; i++){
        result = min(result, minimum[i]);
    }

    cout << result << endl;
}

int main(){
    // freopen("input/ZY26.txt","r",stdin);

    solve();

    freopen("CON","r",stdin);
    system("pause");
}