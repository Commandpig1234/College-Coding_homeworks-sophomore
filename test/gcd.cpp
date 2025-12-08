#include <iostream>


int gcd_recursion(int m,int n){
    if(n == 0)  return m;
    return gcd_recursion(n,m%n);
}

int gcd_iteration(int m,int n){
    while(n!=0){
        int temp = m;
        m = n;
        n = temp % n;
    }
    return m;
}

int main(){
    int m,n;
    std::cin >> m >> n;
    std::cout << gcd_recursion(m,n) << std::endl;
    std::cout << gcd_iteration(m,n) << std::endl;
    system("pause");
    return 0;
}