#include <iostream>
#include <cstdlib> 
#include <ctime>

using namespace std;
int message (int n, int M, int m){
    if ((n <= M) and (n >= m)){
        return n;
    }else {
        cout << "Введите число n от [1 до 30]!!! = ";
        cin >> n;
        message (n, M, m);
    }
}

int main(){
    const int M = 30;
    const int m = 1;
    int n;
    cout << "Введите число n от [1 до 30] = ";
    cin >> n;
    n = message (n, M, m);
    cout << n;
}