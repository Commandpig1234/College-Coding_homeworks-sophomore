#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define cutoff (5)

using namespace std;

vector<int> median;

int median3(vector<int> &A, int left,int right){
    int center = (left + right) / 2;
    if(A[left] > A[center])
        swap(A[left],A[center]);
    if(A[left] > A[right])
        swap(A[left],A[right]);
    if(A[center] > A[right])
        swap(A[center],A[right]);
    swap(A[center],A[right-1]);
    return A[right - 1];
}

void Qsort(vector<int> &A,int left,int right){
    int pivot;
    int i,j;
    if(right - left >= cutoff){
        pivot = median3(A,left,right);
        median.push_back(pivot);
        i = left;
        j = right -1;
        for(;;){
            while(A[++i] < pivot){}
            while(A[--j] > pivot){}
            if(i < j)
                swap(A[i],A[j]);
            else break;
        }
        swap(A[i],A[right-1]);
        Qsort(A,left,i-1);
        Qsort(A,i+1,right);
    }
    else{
        sort(A.begin() + left,A.begin() + right + 1);
    }
    return;
}

void QuickSort(vector<int> &A,int n){
    Qsort(A,0,n-1);
    cout << "After Sorting:\n";
    for(auto a : A)
        cout << a << " ";
        cout << endl;
    cout << "Median3 Value:\n";
    if(median.size() == 0)
        cout << "none\n";
    else{
        for (auto a :median)
            cout << a << " ";
            cout << endl;
    }
    return;
}

void solve(){
    vector<int> inputs;
    int n =0;
    string input;
    while(1){
        cin >> input;
        if(input[0] == '#')
            break;
        else{
            inputs.push_back(stoi(input));
            n++;
        }
    }
    QuickSort(inputs,n);
    return;
}

int main(){
    // freopen("input/quicksort.txt","r",stdin);

    solve();

    freopen("CON","r",stdin);
    system("pause");
}