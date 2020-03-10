//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>

using namespace std;
//双向链表
//链表是由一系列的结点组成，结点包括两个域，一个数据域，一个指针域
//链表内存非连续，添加删除元素时间复杂度都是常数项，效率高，不需要移动元素
//链表只有在需要的时候才分配内存
//链表需要额外的空间保存结点关系 前驱后继关系
//-----------------------------------------
void Print(list<int>l) {
    for (const auto& c : l) {
        cout << c << " ";
    }
    cout << endl;
}
//初始化
void test31_01() {
    list<int>l1;
    list<int>l2(10, 10);
    list<int>l3{ 10,10 };
    list<int>l4(l2);
    list<int>l5(l2.begin(), l2.end());

    Print(l5);
}

//插入和删除
void test31_02() {
    list<int>l1;
    l1.push_back(100);
    l1.push_front(200);
    l1.insert(l1.begin(), 300);
    l1.insert(l1.end(), 400);
    //list的迭代器不支持加int个，支持++和--
    //如果想实现，应该使用advance和distance
    list<int>::iterator it = l1.begin();
    ++it;
    ++it;
    advance(it, 1);
    auto num = distance(l1.begin(), it);
    l1.insert(it, 500);
    
    //删除
    l1.pop_back();
    l1.pop_front();
    l1.erase(l1.begin(), l1.end()); //l1.clear();

    //删除匹配的所有值
    l1.remove(100);
}

//赋值
void test31_03() {
    list<int> l1,l2,l3;
    l1.assign(10, 10);
    l2.assign(10, 12);
    l1.assign(l2.begin(), l2.end());
    l3 = l2;
    l3.swap(l1);
}

//反转
void test31_04() {
    list<int>l1;
    for (int i = 0; i < 10; ++i) {
        l1.push_back(i);
    }
    Print(l1);
    l1.reverse();
    Print(l1);
}

bool compare(int a,int b) {
    return a > b;
}
//排序(成员函数sort)
void test31_05() {
    list<int>l1{ 1,2,7,5,3,2,6,1 };
    Print(l1);
    //默认从小到大
    l1.sort();
    Print(l1);
    //传回调函数参数
    l1.sort(compare);
    Print(l1);

    //算法sort只支持可随机访问的容器
}
int main() {

    //test31_01();
    //test31_04();
    test31_05();
    return 0;
}

/*
 *
 *
 *
 *
 */

