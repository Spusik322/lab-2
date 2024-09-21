#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <cmath>

using namespace std;
int message (int n, int M, int m){
    if ((n <= M) and (n >= m)){
        return n;
    }else {
        cout << "Введите число n от [1 до 30]!!! = ";
        cin >> n;
        return message (n, M, m);
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
    cout << endl;
    int min = fabs(array[0]);
    for (int i = 0; i < n; ++i){
        if (fabs(array[i]) < min){
            min = fabs(array[i]);
        }
    }
    cout << "Наименьшее по модулю число = " << min << endl;
    int sum = 0;
    for (int i = 0; i < n; ++i){
        if (array[i] == 0){
            for (int k = i; k < n; ++k){
                sum += array[k];
            }
            cout << "Одна из сумм = " << sum << " ";
            sum = 0;
        }
    }
    int* array1 = new int[n];
    int i1 = 0;
    int i2 = 0;
    for(int i = 0; i < n; ++i){
        int mesto = i % 2;
        if(mesto == 0){
            array1[i2] = array[i];
            i2 += 1;
            i1 += 1;
            array[i]=0;
        }
    }
    for(int i = 0; i < n; ++i){
        if(array[i] != 0){
        array1[i1] = array[i]; 
        i1 += 1;
        }
    }
    cout << "Новый масиив: ";
    for(int i = 0; i < n; ++i){
        cout << array1[i] << " ";
    }
    return 0;
}