#include <iostream>

using namespace std;

struct MetaHeap
{
    int Size;
    int* Heap;
};

void PercolateDown(int* H, int parent, int Size) {
    int temp = H[parent];
    int child;
    
    for (; parent * 2 <= Size; parent = child) {
        child = parent * 2;
        
        if (child != Size && H[child] < H[child + 1])
            child++;
        
        if (temp < H[child]) {
            H[parent] = H[child];
        }
        else {
            break;
        }
    }
    H[parent] = temp;
}

void deleteMax(int* H, int& Size) {
    int Last = H[Size--];
    H[1] = Last;
    PercolateDown(H, 1, Size);
}

int* BuildHeap(int Size) {
    int* H = new int[Size + 1];
    for (int i = 1; i <= Size; i++)
        cin >> H[i];
    
    for (int i = Size / 2; i >= 1; i--) {
        PercolateDown(H, i, Size);
    }
    return H;
}

void output(int* H, int Size) {
    for (int i = 1; i <= Size; i++) {
        cout << H[i] << " ";
    }
    cout << endl;
    return;
}

void solve() {
    MetaHeap MH;
    cin >> MH.Size;
    MH.Heap = BuildHeap(MH.Size);
    output(MH.Heap, MH.Size);
    
    deleteMax(MH.Heap, MH.Size);
    output(MH.Heap, MH.Size);
    
    deleteMax(MH.Heap, MH.Size);
    output(MH.Heap, MH.Size);
    
    delete[] MH.Heap;
    return;
}

int main() {
    // freopen("input/heapsort.txt","r",stdin);

    solve();

    freopen("CON", "r", stdin);
    system("pause");
    return 0;
}