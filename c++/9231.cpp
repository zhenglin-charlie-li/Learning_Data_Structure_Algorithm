//
// Created by Zhenglin Li on 2020/9/23.
//

#include "iostream"

using namespace std;
//模板
template<typename T>
class Vector {
private:
    T x;
    T y;
public:
    Vector(T x = 0, T y = 0) : x(x), y(y) {

    }

    friend ostream &operator<<(ostream &o, const Vector<T> &v) {
        return o << "<" << v.x << ", " << v.y << ">" << endl;
    }
};

int main9231() {
    //真正的类，要<>
    Vector<int> x(1,2);
    Vector<double> *p = new Vector<double>(1.1,2.2);
    cout << x << endl;
    cout << *p << endl;
    return 0;
}