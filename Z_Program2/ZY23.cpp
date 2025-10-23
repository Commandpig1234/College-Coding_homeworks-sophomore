#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(){
    // freopen("D:/VScode/Python/class2/large_input.txt","r",stdin);

    ll N = 0;
    cin >> N;
    ll sum = (1+N)*N/2;
    ll square_sum = N * (N + 1) * (2 * N + 1) /6;
    ll book_sum = 0;
    ll book_square_sum = 0;
    for(ll i = 0;i<N-2;i++){
        ll book;
        cin >> book;
        book_sum += book;
        book_square_sum += book*book;
    }
    ll m = sum - book_sum;
    ll n = square_sum - book_square_sum;
    ll dif_square = (2*n - m*m);
    ll dif = static_cast<ll>(sqrt(dif_square));
    ll x = (m+dif)/2;
    ll y = m -x;

    if(x>y)
        swap(x,y);
    cout << x << " " << y << endl;

    // freopen("CON","r",stdin);

    // system("pause");
    return 0;
}