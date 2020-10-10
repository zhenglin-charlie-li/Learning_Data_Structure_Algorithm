//
// Created by Zhenglin Li on 2020/10/10.
//
#include "iostream"
#include "cstring"
using namespace std;

class Person {
private:
    int age;
    char name[10];
public:
    Person() {}
    Person(int age,char name[]):age(age){
        strcpy(this->name,name);
    }
    friend ostream &operator<<(ostream &os,const Person &p){
        return os<<"[Person] age = "<<p.age<<", name = "<<p.name;
    }
    Person operator+(Person &add){
        Person result(0,"");
        result.age = add.age+this->age;
        strcat(result.name,strcat(this->name,add.name));
        return result;
    }
    bool operator>(Person &toCompare){
        return this->age>toCompare.age;
    }
    Person operator++(){
        ++this->age;
        return Person(this->age,this->name);
    }
    Person operator++(int ){
        Person person(this->age,this->name);
        ++this->age;
        return person;
    }
};


int mainslft() {
    Person p1(123,"aaa");
    Person p2(1234,"bbb");
    cout<<p1<<endl;
    cout<<p2<<endl;
    Person p3 = p1+p2;
    cout<<p3<<endl;
    cout<<(p1>p2)<<endl;
    return 0;
}
