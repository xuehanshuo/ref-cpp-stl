//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<iterator>

using namespace std;

void Print(const vector<int>& v) {
    for (const auto& c : v) {
        cout << c << " ";
    }
    cout << endl;
    for (auto i = v.begin(); i != v.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}
//-----------------------------------------
//初始化
void test26_01() {
    //默认构造
    vector<int> v1;

    //首尾指针，左闭右开
    //针对内置数组，用begin和end取得类似的首位迭代器
    int a[] = { 0,1,2,6,9 };
    vector<int>v2(begin(a), end(a));
    vector<int>v3(v2.begin(), v2.end());
    
    //拷贝构造
    vector<int>v4(v3);
    vector<int>v5 = v4;

    Print(v5);
}

//赋值
void test26_02() {
    int a[] = { 10,20 };
    vector<int>v1(begin(a), end(a));

    //成员函数：assign+迭代器
    vector<int>v2;
    v2.assign(v1.begin(), v1.end());

    //重载'='赋值
    vector<int>v3;
    v3 = v2;

    //成员函数：swap
    //原理是交换指针指向
    int a1[] = { 100,200 };
    vector<int>v4(begin(a1), end(a1));
    v4.swap(v1);

    Print(v1);
    Print(v2);
    Print(v3);
    Print(v4);
}

//大小操作
void test26_03() {
    int a[] = { 10,20,30,40 };
    vector<int>v1(begin(a), end(a));

    //求大小size，是否为空empty
    cout << "Size: " << v1.size() << endl;
    if (v1.empty()) {
        cout << "空！" << endl;
    }
    else {
        cout << "不空！" << endl;
    }

    //resize改变容器大小为2，多余的元素删除
    //增大容器大小，默认初始化，也可指定值
    v1.resize(2);
    Print(v1);
    v1.resize(6,5);
    Print(v1);

    //capacity容量
    for (int i = 0; i < 1000000; ++i) {
        v1.push_back(i);
    }
    cout << "Size: " << v1.size() << endl;  //当前元素的个数
    cout << "Capacity:" << v1.capacity() << endl;   //能容纳的元素个数
}

//访问
void test26_04() {
    int a[] = { 10,20,30,40 };
    vector<int>v1(begin(a), end(a));

    //下标[]和at
    //at抛异常，[]不抛异常
    for (int i = 0; i < v1.size(); ++i) {
        cout << v1[i] << " " << v1.at(i) << endl;
    }

    //front和back得到首尾元素的引用
    cout << v1.front() << endl;
    cout << v1.back() << endl;
}

//插入和删除
void test26_05() {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    
    //insert，使用迭代器作为参数
    //支持数组下标的，一般都支持随机访问
    //迭代器可以+2 +3...
    v.insert(v.begin(), 30);
    v.insert(v.end(), 40);
    v.insert(v.begin() + 2, 100);   //vector支持随机访问的标志
    v.insert(v.begin() + v.size()/2, 500);
    Print(v);

    //删除
    v.erase(v.begin());
    Print(v);
    v.erase(v.begin() + 1, v.end());
    Print(v);
    v.clear();
    cout << "Size: " << v.size() << endl;
}

//收缩空间
void test26_06() {
    //vector随着添加元素会实现自动增长，但是删除元素后容量并不会随之收缩
    vector<int> v;
    for (int i = 0; i < 100000; ++i) {
        v.push_back(i);
    }
    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;

    v.resize(10);
    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;

    //收缩操作
    //使用v去初始化匿名对象，之后把匿名对象里面的数据和v互换，实现收缩操作
    vector<int>(v).swap(v);
    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;
}

//预留空间
void test26_07() {
    //统计申请内存次数
    int num = 0;
    int* add = NULL;
    vector<int> v;
    
    //先使用reserve预留一定空间，减少拷贝次数，但是没有进行初始化，不能直接访问
    //resize会给默认值，可以访问
    v.reserve(1000000);
    for (int i = 0; i < 1000000; ++i) {
        v.push_back(i);
        //&v得到的是对象的地址，&v[0]得到的是元素首地址
        if (add != &v[0]) {
            add = &v[0];
            ++num;
        }
    }
    cout << "Num: " << num << endl;
}

int main() {

    //test26_01();
    //test26_02();
    //test26_03();
    //test26_04();
    //test26_05();
    //test26_06();
    test26_07();
    return 0;
}

/*
 *
 *
 *
 *
 */

