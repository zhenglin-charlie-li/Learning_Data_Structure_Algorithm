//
// Created by Zhenglin Li on 2020/9/23.
//

#include "iostream"

using namespace std;

template<typename T>
T sum(T array[], int size) {
    T s = 0;
    for (int i = 0; i < size; ++i) {
        s += array[i];
    }
    return s;
}

template<typename T>
T sum(T array[], int from, int to) {
    T s = 0;
    for (int i = from - 1; i <= to - 1; ++i) {
        s += array[i];
    }
    return s;
}

int main923() {
    int a1[5] = {1, 2, 3, 4, 5};
    double a2[3] = {1.1, 2.2, 3.3};
    cout << sum(a1, 5) << endl;
    cout << sum(a2, 3) << endl;
    cout << sum(a2, 1, 3) << endl;
    return 0;
}