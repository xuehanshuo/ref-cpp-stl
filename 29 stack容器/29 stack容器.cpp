//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>

using namespace std;
//先进后出，压栈push出栈pop，获取元素就用top，栈顶栈底
//栈不能遍历，不能随机存取，只能对栈顶操作，无迭代器
//-----------------------------------------
//初始化和操作
void test29_01() {
    //默认
    stack<int> s1;
    //拷贝构造
    stack<int> s2(s1);

    //操作push，pop，top 
    //10 20 30进 30 20 10出
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(100);
    cout << "栈顶元素：" << s1.top() << endl;
    s1.pop();

    //大小操作
    while (!s1.empty()) {
        cout << s1.top() << endl;
        s1.pop();
    }
    cout << "Size: " << s1.size() << endl;
}
int main() {

    test29_01();
    return 0;
}

/*
 *
 *
 *
 *
 */

