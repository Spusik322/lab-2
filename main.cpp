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
    int pos = -1;
    for (int i = 0; i < n; ++i){
        if (array[i] == 0){
            pos = i;
        }
    }
    if (pos == -1){
        cout << "В этом массиве нет нулевоого элемента" << endl;
    }else{
        for (int i = pos; i < n; ++i){
            sum += array[i];
        }
        cout << "Сумма после последнего нулевого члена = " << sum << endl;
    }    
    int evenindex = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            int temp = array[i];
            int j = i;
            while (j > evenindex) {
                array[j] = array[j - 1];
                --j;
            }
            array[evenindex] = temp;
            ++evenindex;
        }
    }
    cout << "Новый масиив: ";
    for(int i = 0; i < n; ++i){
        cout << array[i] << " ";
    }
    delete []array;
    return 0;
}