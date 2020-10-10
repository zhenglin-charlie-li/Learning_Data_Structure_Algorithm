#include "iostream"
#include <string>
using namespace std;

class Person
{
    //1、全局函数配合友元   类内实现
    friend void printPerson(Person & p)
    {
        cout << "姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
    }


    //全局函数配合友元  类外实现
    friend void printPerson2(Person & p);

public:

    Person(char* name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }


private:
    char* m_Name;
    int m_Age;

};

void printPerson2(Person & p)
{
    cout << "类外实现 ---- 姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
}

//1、全局函数在类内实现
void test01()
{
    Person p("Tom", 20);
    printPerson(p);
}


//2、全局函数在类外实现
void test02()
{
    Person p("Jerry", 30);
    printPerson2(p);
}

int main() {

    //test01();

    test02();

    return 0;
}