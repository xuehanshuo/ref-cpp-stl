//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;
//set_intersection  交集
//set_union 并集
//set_difference 差集
//-----------------------------------------
//set_intersection  交集
//set_union 并集
//set_difference 差集
//第三容器必须提前预留出第一第二容器的最小size容量
class print {
public:
    void operator()(const int& val)const {
        cout << val << " ";
    }
public:
};
void test04_01() {
    vector<int>v1, v2, v3,v4,v5;

    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    for (int i = 5; i < 15; ++i) {
        v2.push_back(i);
    }

    v3.resize(min(v1.size(), v2.size()));
    //返回最后一个交集元素后一位的迭代器，end位置
    vector<int>::iterator it=set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    for_each(v1.begin(), v1.end(), print()); cout << endl;
    for_each(v2.begin(), v2.end(), print()); cout << endl;
    cout << "————————————————————————————————————" << endl;
    for_each(v3.begin(), v3.end(), print()); cout << endl;
    for_each(v3.begin(), it, print()); cout << endl;
    cout << "————————————————————————————————————" << endl;
    //set_union
    v4.resize(v1.size()+v2.size());
    vector<int>::iterator it2=set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v4.begin());
    for_each(v4.begin(), v4.end(), print()); cout << endl;
    for_each(v4.begin(), it2, print()); cout << endl;
    cout << "————————————————————————————————————" << endl;
    //set_difference
    //写前面的差后面的
    v5.resize(v1.size());
    it = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v5.begin());
    for_each(v5.begin(), it, print());
}

int main() {

    test04_01();
    return 0;
}

/*
 *
 *
 *
 *
 */

