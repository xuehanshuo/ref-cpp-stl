//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//find
//binary_search
//adjacent_find
//find_if
//count count_if
//-----------------------------------------
//find
//内置类型查找
void test41_01() {
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    //返回迭代器
    vector<int>::iterator ret=find(v.begin(), v.end(), 5);
    if (ret == v.end()) {
        cout << "Search failed!" << endl;
    }
    else {
        cout << "Search succeeded! We found " <<*ret<< endl;
    }
}
//对象查找
//重载相等判断符
class Person {
public:
    Person(const int&id,const int&age):mID(id),mAge(age){}
    bool operator==(const Person& p)const {
        return this->mID == p.mID && this->mAge == p.mAge;
    }
public:
    int mID;
    int mAge;
};
void test41_02() {
    vector<Person> v{ Person(10,20),Person(20,30) };
    vector<Person>::iterator ret= find(v.begin(), v.end(), Person(10, 20));
    if (ret == v.end()) {
        cout << "Search failed!" << endl;
    }
    else {
        cout << "Search succeeded! We found it! " << endl;
    }
}

//binary_search     二分查找法
//返回bool类型，只能判断找没找到，且必须有序
void test41_03() {
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    bool ret = binary_search(v.begin(), v.end(), 5);
    if (!ret) {
        cout << "Search failed!" << endl;
    }
    else {
        cout << "Search succeeded! We found it! " << endl;
    }
}

//adjacent_find     查找相邻重复元素 1223 返回第一个2的迭代器
void test41_04() {
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    v.push_back(9);

    vector<int>::iterator ret = adjacent_find(v.begin(), v.end());
    if (ret == v.end()) {
        cout << "Search failed!" << endl;
    }
    else {
        cout << "Search succeeded! We found "<<*ret<<"! " << endl;
    }
}

//find_if      根据我们传入的函数，返回第一个满足条件元素的迭代器
class Deal {
public:
    bool operator()(const int& val)const {
        return val > 5;
    }
public:
};
void test41_05() {
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    vector<int>::iterator ret=find_if(v.begin(), v.end(), Deal());
    if (ret == v.end()) {
        cout << "Search failed!" << endl;
    }
    else {
        cout << "Search succeeded! We found " << *ret << "! " << endl;
    }
}

//count count_if    返回符合条件的个数
void test41_06() {
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    int num;
    num = count(v.begin(), v.end(), 5);
    cout << num << endl;
    num = count_if(v.begin(), v.end(), Deal());
    cout << num << endl;
}

int main() {

    //test41_01();
    //test41_02();
    //test41_03();
    //test41_04();
    //test41_05();
    test41_06();
    return 0;
}

/*
 *
 *
 *
 *
 */

