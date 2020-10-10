
#include "iostream"
using namespace std;

int *func() {
    int *a = new int(10);  //指针a指向的是new出来的对象的地址
    return a;  //即使函数（在栈中）的空间被回收，依然返回了new出来的对象的地址
}

int main924() {

    int *p = func();  //指针p指向new出来的对象的地址

    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;

    return 0;
}