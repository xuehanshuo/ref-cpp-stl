//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//-----------------------------------------
class Person {
public:
    Person(const int& id,const int& age):mID(id),mAge(age){}
    void Print()const {
        cout << "ID: " << mID << " Age: " << mAge << endl;
    }
private:
    int mID;
    int mAge;
};
void Print(const int& v) {
    cout << v<<" ";
}

//STL基本语法
void test24_01() {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    //定义迭代器
    vector<int>::iterator pBegin = v.begin();
    vector<int>::iterator pEnd = v.end();
    //通过STL提供的for_each算法
    for_each(pBegin, pEnd, Print);
}

void test24_02() {
    vector<Person*> v;
    Person* p1 = new Person(10, 20);
    Person* p2 = new Person(11, 30);
    Person p3(12, 20);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(&p3);
    for (const auto& c : v) {
        c->Print();
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    for (auto i = v.begin(); i != v.end(); ++i) {
        (*i)->Print();
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    for (auto i = v.begin(); i != v.end(); ++i) {
        (*(*i)).Print();
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    vector<Person*>::iterator pBegin = v.begin();
    vector<Person*>::iterator pEnd = v.end();
    for (; pBegin != pEnd; ++pBegin) {
        (*pBegin)->Print();
    }

}

int main() {

    //test24_01();
    test24_02();
    return 0;
}

/*
 *
 *
 *
 *
 */

