#include <iostream>

using namespace std;

void insertionSort(int array[],int n){
    for(int i = 1;i<n;i++){
        int ToInsert = array[i];
        int j = i-1;
        while(j >=0 && array[j] > ToInsert){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = ToInsert;
    }
    return;
}

void solve(){
    int n = 7;
    // for(int i = 0;i<7;i++)
    //     cin >> array[i];
    int array[] = {89,45,68,90,29,34,17};
    insertionSort(array,n);
    for(int i = 0;i<7;i++)
        cout << array[i] <<endl;
}

int main(){
    // freopen("input/","r",stdin);

    solve();

    freopen("CON","r",stdin);
    system("pause");
}