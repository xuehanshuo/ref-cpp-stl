//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//函数对象(仿函数)可以像普通函数一样接收参数并被调用，但同时又可保存函数调用的状态
//可以有返回值
//-----------------------------------------
class Print {
public:
    Print() :num(0) {};
    void operator()(const int& a) {
        ++num;
        cout << a << endl;
    }
public:
    int num;
};

void test37_01() {
    Print p1;
    p1(10);
}

//真正开发中，尽量避免去使用全局变量
int num = 0;
void PrintFunc(const int& val) {
    ++num;
    cout << val << endl;
}
void test37_02() {
    vector<int> v{ 10,20,30,40 };
    Print p1;
    //for_each调用是by value，改变的是拷贝，返回值是第三个参数的类型，所以如果需要用函数对象统计次数，就要再用p1接收返回值
    p1=for_each(v.begin(), v.end()-1, p1);
    cout << "Times: " << p1.num;
}

int main() {

    //test37_01();
    test37_02();
    return 0;
}

/*
 *
 *
 *
 *
 */

