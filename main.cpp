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
    bool b;
    cout << "Введите число n от [1 до 30] = ";
    cin >> n;
    n = message (n, M, m);
    int* array = new int[n];
    cout << "Если хотите заполнить массив вручную введите 1" << endl << "если хотите заполнить числа рандомом введите 0" << endl;
    cin >> b;
    if (b == 1){
        cout << "Введите все числа через пробел ";
        for (int i = 0; i < n; ++i){
            //cout << "Введите число под №" << i + 1 << " ";
            cin >> array[i];
        }
        cout << "Массив из чисел: ";
        for (int i = 0; i < n; ++i){
            cout << array[i] << " ";
        }
    }else {
        int start; 
        int end;
        cout << "Введите нижний диапозон значений = ";
        cin >> start;
        cout << "Введите верхний диапозон значений = ";
        cin >> end;
        srand(time(0));
        cout << "Массив из чисел: ";
        for (int i = 0; i < n; ++i){
            array[i] = rand() % (end - start + 1) + start;
            cout << array[i] << " ";
        }
    }
    
}