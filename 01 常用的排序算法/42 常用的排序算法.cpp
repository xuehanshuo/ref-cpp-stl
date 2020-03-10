//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#include<list>

using namespace std;
//merge
//sort
//random_shuffle
//reverse

//merge支持不同种容器的合并，如list+vector
//reverse支持list
//其余要考虑是否支持随机访问
//-----------------------------------------
//merge     把两个有序容器的对象合并放到第三个容器中，两个迭代器所指向元素分别比较，迭代器依次后移
class compare {
public:
    bool operator()(const int& a, const int& b)const {
        return a > b;
    }
public:
};

class print {
public:
    void operator()(const int& val)const {
        cout << val << " ";
    }
public:
};

void test01_01() {
    vector<int> v1, v2;
    vector<int>v3;
    srand((unsigned int)time(NULL));
    
    for (int i = 0; i < 10; ++i) {
        v1.push_back(rand() % 10);
    }
    for (int i = 0; i < 19; ++i) {
        v2.push_back(rand() % 100);
    }
    //保证有序
    sort(v1.begin(), v1.end(),compare());
    sort(v2.begin(), v2.end(),compare());
    //必须提前开辟空间
    v3.resize(v1.size() + v2.size());
    
    //merge默认排序规则从小到大，如果两个序列都是从大到小，则需要在最后传进去仿函数
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin(),compare());

    for_each(v1.begin(), v1.end(), print()); cout << endl;
    for_each(v2.begin(), v2.end(), print()); cout << endl;
    for_each(v3.begin(), v3.end(), print()); cout << endl;
}

//random_shuffle    打乱迭代器区间的数据
void test01_02() {
    vector<int>v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    
    for_each(v.begin(), v.end(), print()); cout << endl;
    random_shuffle(v.begin(), v.end());
    for_each(v.begin(), v.end(), print()); cout << endl;
}

//reverse
void test01_03() {
    vector<int>v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    for_each(v.begin(), v.end(), print()); cout << endl;
    reverse(v.begin(), v.end());
    for_each(v.begin(), v.end(), print()); cout << endl;
}

//针对是否能随机访问
//merge可以vector+list，reverse也可以，sort有自带
//random_shuffle可以存到vector中打乱
void test01_04() {
    vector<int> v1,v3;
    list<int>l1;
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 10; ++i) {
        v1.push_back(rand() % 100);
        l1.push_back(rand() % 1000);
    }

    for_each(v1.begin(), v1.end(), print()); cout << endl;
    for_each(l1.begin(), l1.end(), print()); cout << endl;
    //list自带sort算法
    l1.sort(compare());
    sort(v1.begin(), v1.end(), compare());
    
    for_each(v1.begin(), v1.end(), print()); cout << endl;
    for_each(l1.begin(), l1.end(), print()); cout << endl;
    
    v3.resize(v1.size() + l1.size());
    merge(v1.begin(), v1.end(), l1.begin(), l1.end(), v3.begin(), compare());
    for_each(v3.begin(), v3.end(), print()); cout << endl;

    //reverse
    reverse(l1.begin(), l1.end());
    for_each(l1.begin(), l1.end(), print()); cout << endl;
    l1.reverse();
    for_each(l1.begin(), l1.end(), print()); cout << endl;

    //间接打乱
    cout << "--------------------------------------------" << endl;
    for_each(l1.begin(), l1.end(), print()); cout << endl;
    vector<int>vtemp (l1.begin(), l1.end());
    random_shuffle(vtemp.begin(), vtemp.end());
    l1.assign(vtemp.begin(),vtemp.end());
    for_each(l1.begin(), l1.end(), print()); cout << endl;
}
int main() {

    //test01_01();
    //test01_02();
    //test01_03();
    test01_04();
    return 0;
}

/*
 *
 *
 *
 *
 */

