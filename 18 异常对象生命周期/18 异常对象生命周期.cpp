//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

//-----------------------------------------
class MyException {
public:
    MyException() {
        cout << "无参构造！" << endl;
    }
    MyException(const MyException& e) {
        cout << "拷贝构造！" << endl;
    }
    ~MyException() {
        cout << "析构函数！" << endl;
    }
};

void func() {
    //匿名对象 调用构造函数
    //throw &(MyException());

    //使用new则可以保证不自动析构
    throw new MyException();
}

void test18() {
    try {
        func();
    }
    //catch中可以接收普通类型元素 引用 指针
    //普通元素 调用拷贝构造 异常对象catch处理完之后析构
    //引用     调用拷贝构造 异常对象catch处理完之后析构
    //指针     会在捕获之前进行析构，导致不能使用匿名异常对象中的内容，所以应该用new来创建，再手动触发析构
    catch (MyException* e) {
        cout << "异常捕获！" << endl;
        delete e;
    }
}



int main() {

    test18();
    return 0;
}

/*
 *
 *
 *
 *
 */

