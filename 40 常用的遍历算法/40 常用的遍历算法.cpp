//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//for_each
//transform
//-----------------------------------------
//transform将一个容器中的元素 搬运 到另一个容器中
//目的容器必须提前用resize分配好空间，reserve和不分配编译通过，执行中宕掉
class Deal {
public:
    int operator()(const int& val)const {
        return val + 10;
    }
public:
};

class Print {
public:
    void operator()(const int& val)const {
        cout << val << " ";
    }
public:
};

void test40_01() {
    vector<int>v1;
    vector<int>v2;
    //v2.resize(100);
    

    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    
    //添加完元素后v1.size()才不为空
    v2.resize(v1.size());

    //transform把迭代器区间的值逐个进行Deal处理，放入目的容器中
    transform(v1.begin(), v1.end(), v2.begin(), Deal());
    for_each(v2.begin(), v2.end(), Print());
}
int main() {

    test40_01();
    return 0;
}

/*
 *
 *
 *
 *
 */

