//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#include<iostream>

using namespace std;

//-----------------------------------------
//-----------------------------------------代表这个函数只能抛出int char float三种类型异常，抛出其他的异常可能报错
void func()throw(int,float,char ){
    throw "abc";
}

//-----------------------------------------代表不能抛出任何类型异常
void func02()throw() {
    throw - 1;
}

//-----------------------------------------代表可以抛出任何类型异常
void func03() {

}

int main() {
    try {
        func();
    }
    //-----------------------------------------可以接多个catch语句
    //throw出来的类型是const char*，所以不能用char*来接收字符串字面值，否则就会跳到(...)中
    catch (const char* str) {
        cout << str << endl;
    }
    catch (const int& e) {
        cout << "异常！" << endl;
    }
    //-----------------------------------------捕获所有异常
    catch (...) {
        cout << "未知类型异常" << endl;
    }

    return 0;
}

/*
 *
 *
 *
 *
 */

