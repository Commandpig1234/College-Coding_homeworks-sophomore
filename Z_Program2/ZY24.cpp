#include <iostream>
#include <vector>
#include <algorithm>
#define divisor (1000000009LL);
using namespace std;

typedef long long ll;

int main(){
    // freopen("input/ZY24.txt","r",stdin);

    int N,K;
    cin >> N >> K;
    vector<ll> nums(N);
    for(int i = 0;i<N;i++){
        cin >> nums[i];
    }
    sort(nums.begin(),nums.end());
    int l = 0;
    int r = N-1;
    ll ans = 1;
    if(K % 2 == 1){
        ans = nums[r--];
        K--;
    }
    while(K>0){
        ll prob_l = nums[l] * nums[l+1];
        ll prob_r = nums[r] * nums[r-1];
        if(prob_l > prob_r){
            ans *= prob_l;
            l+=2;
            K-=2;
        }
        else{
            ans *= prob_r;
            r-=2;
            K-=2;
        }
        if(ans > 0){
            ans = ans % divisor;
        }
        else{
            ans = 0 - ans;
            ans = ans % divisor;
            ans = 0 - ans;
        }
    }
    
    cout << ans << endl;


    // freopen("CON","r",stdin);
    system("pause");
}