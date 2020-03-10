//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#include<iostream>

using namespace std;

//-----------------------------------------
//-----------------------------------------异常基本语法
int divide(int x, int y) {
    //抛异常
    if (y == 0)throw y;
    return x / y;
}

void test14_01() {
    //试着去捕获异常
    try {
        divide(10, 0);
    }
    //异常通过类型进行匹配，throw出的y是int类型，并且可以接收到throw的值并接着使用
    catch (int e) {
        cout << "除数为"<<e<<"！" << endl;
    }
}

void CallDivide(int x, int y) {
    divide(x, y);
}

//-----------------------------------------异常逐层抛出，抛到顶层main函数还没有被处理，则调用terminate()函数终止程序
//-----------------------------------------C++异常实现了跨函数和必须处理的机制
void test14_02() {
    try {
        CallDivide(10, 0);
    }
    catch (int e) {
        cout << "除数为" << e << endl;
    }
}

int main() {
    
    //test14_01();
    test14_02();
    return 0;
}

/*
 *
 *
 *
 *
 */

