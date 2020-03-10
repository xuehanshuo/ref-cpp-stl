//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<numeric>
#include<vector>
#include<algorithm>

using namespace std;
//accumulate
//fill

//numeric头文件中
//fill，transform，copy都需要提前开空间
//-----------------------------------------
//accumulate
//范围内值+参数
void test03_01() {
    vector<int>v{ 1,2,3,4,5 };
    int sum = accumulate(v.begin(), v.end(), 100);
    cout << sum << endl;
}

//fill
//提前分配大小
//抹去迭代器范围内的所有值，并用fill中的值填充
class print {
public:
    void operator()(const int& val)const {
        cout << val << " ";
    }
public:
};
void test03_02() {
    vector<int>v{ 1 };
    v.resize(10);
    fill(v.begin(), v.end(), 100);
    for_each(v.begin(), v.end(), print()); cout << endl;
}

int main() {

    //test03_01();
    test03_02();
    return 0;
}

/*
 *
 *
 *
 *
 */

