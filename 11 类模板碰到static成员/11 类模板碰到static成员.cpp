//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#include<iostream>

using namespace std;

//-----------------------------------------
template<class T>
class Person {
public:
    static int& getA() { return a; }
private:
    static int a;
};

//-----------------------------------------类模板static成员类外初始化也需要加template，派生出来的不同类static成员是不同的
template<class T>
int Person<T>::a = 0;

int main() {
    //-----------------------------------------下面2个static成员，互不干扰
    Person<int> p1, p2, p3;
    Person<char>pp1, pp2, pp3;

    p1.getA() = 10;
    pp1.getA() = 100;
    cout << p1.getA() <<" "<< pp1.getA() << endl;
    return 0;
}

/*
 *
 *
 *
 *
 */

