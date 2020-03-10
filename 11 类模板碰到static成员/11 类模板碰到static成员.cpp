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

//-----------------------------------------��ģ��static��Ա�����ʼ��Ҳ��Ҫ��template�����������Ĳ�ͬ��static��Ա�ǲ�ͬ��
template<class T>
int Person<T>::a = 0;

int main() {
    //-----------------------------------------����2��static��Ա����������
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

