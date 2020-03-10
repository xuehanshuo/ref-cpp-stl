//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#include<iostream>

using namespace std;

//-----------------------------------------
class Person {
public:
    Person() {
        cout << "开始构造！" << endl;
    }
    ~Person() {
        cout << "开始析构！" << endl;
    }
private:
};
int divide(int x, int y) {
    Person p1, p2;
    if (y == 0)throw y;
    return x / y;
}

void test15() {
    //栈解旋指的是发生异常捕获时自动调用之前在try中运行的函数中生成的类对象的析构函数
    try {
        divide(10, 0);
    }
    catch (int e) {
        cout << "异常捕获" << endl;
    }
}

int main() {
    Person p3;
    test15();
    return 0;
}

/*
 *
 *
 *
 *
 */

