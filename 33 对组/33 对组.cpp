//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
//一对值可以有不同的数据类型
//类模板：template<class T1, class T2>struct pair;
//-----------------------------------------
void test33_01() {
    pair<int, int> pair1(10, 20);
    cout << pair1.first << " " << pair1.second << endl;

    //不可以直接用"="加括号，用make_pair，应该是explicit
    pair<int, string> pair2 = make_pair(10, "abc");
    cout << pair2.first << " " << pair2.second << endl;

    //拷贝构造
    pair<int, string>pair3 = pair2;
    cout << pair3.first << " " << pair3.second << endl;
}

int main() {

    test33_01();
    return 0;
}

/*
 *
 *
 *
 *
 */

