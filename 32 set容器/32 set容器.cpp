//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>

using namespace std;
//关联容器，set中无重复元素，multiset有重复元素
//基于红黑树(一种平衡搜索树)，自动排序，不支持利用迭代器修改结点，可以删除增加
//插入方法只有insert
//-----------------------------------------
class compare {
public:
    bool operator()(int a, int b)const {
        return a > b;
    }
private:
};
//初始化，赋值，删除
void test32_01() {
    //自动进行排序，默认从小到大
    set<int,compare> s1{ 2,7,8,9 },s2(s1);
    s1.insert(5);
    multiset<int>s3{ 1,1,1,2 };
#if 0
    //赋值
    s2 = s1;
    s1.swap(s2);

    //删除
    s1.erase(s1.begin());
    s1.erase(7);
#endif
    for (set<int>::iterator it = s1.begin(); it != s1.end(); ++it) {
        cout << *it << " " ;
    }
    cout << endl;
    //先序遍历 中序遍历 后序遍历
    //改变默认排序方式——使用仿函数(类重载括号操作符作为第二个参数)
}

//查找
void test32_02() {
    set<int> s1{ 2,3,4,5,1,6,9 };
    //find(key)，查找键key是否存在，存在则返回该键元素迭代器，否则返回map.end()
    decltype(s1.begin())it = s1.find(14);
    if (it == s1.end()) {
        cout << "没有找到！" << endl;
    }
    else {
        cout << *it << endl;
    }

    //lower_bound(keyElem)，返回第一个大于等于keyElem元素的迭代器
    it = s1.lower_bound(2);
    if (it == s1.end()) {
        cout << "没有找到！" << endl;
    }
    else {
        cout << *it << endl;
    }

    //upper_bound(keyElem)，返回第一个大于keyElem元素的迭代器
    it = s1.upper_bound(2);
    if (it == s1.end()) {
        cout << "没有找到！" << endl;
    }
    else {
        cout << *it << endl;
    }

    //equal_range 返回lower_bound和upper_bound值
    //返回pair对组，pair是一个模板类pair<iterator,iterator>，用first和second返回lower和upper
    pair<set<int>::iterator, set<int>::iterator> pa1 = s1.equal_range(2);
    if (pa1.first == s1.end()) {
        cout << "没有找到！" << endl;
    }
    else {
        cout << *pa1.first<< endl;
    }
    if (pa1.second == s1.end()) {
        cout << "没有找到！" << endl;
    }
    else {
        cout << *pa1.second << endl;
    }
}

//放入对象(由于不知道怎么排序，所以需要写仿函数)
class Person {
public:
    Person(const int& id, const int& age) :mID(id), mAge(age) {};
public:
    int mID;
    int mAge;
};

class compare2 {
public:
    bool operator()(const Person& p1, const Person& p2)const {
        return p1.mID > p2.mID;
    }
private:
};  //类后面得有分号

void test32_03() {
    set<Person,compare2> s1;
    Person p1(10, 20), p2(20, 30), p3(30, 40);
    s1.insert(p1);
    s1.insert(p2);
#if 0
    for (set<Person, compare2>::iterator it = s1.begin(); it != s1.end(); ++it) {
        cout << "ID: " << it->mID << "Age: " << it->mAge << endl;
    }
    cout << "-------------------------------------" << endl;
    for(decltype(s1.cbegin())it=s1.begin(); it != s1.end(); ++it) {
        cout << "ID: " << it->mID << "Age: " << it->mAge << endl;
    }
    cout << "-------------------------------------" << endl;
    for(auto it=s1.begin(); it != s1.end(); ++it) {
        cout << "ID: " << it->mID << "Age: " << it->mAge << endl;
    }
#endif
    //查找
    //不是按set容器中有没有，而是根据容器开始设定中的仿函数比较标准作为关键字，如s1按照age排序
    //查找也是按照传入对象的age为关键字，age匹配即被认为是匹配成功，找到了该对象
    Person p4(10, 30);
    if (s1.find(p4) != s1.end()) {
        cout << "s1 does have such a element: " << endl
            << "ID: " << s1.find(p4)->mID
            << "Age: " << s1.find(p4)->mAge << endl;
    }
    else {
        cout << "No such element!" << endl;
    }
}


int main() {

    //test32_01();
    //test32_02();
    test32_03();
    return 0;
}

/*
 *
 *
 *
 *
 */

