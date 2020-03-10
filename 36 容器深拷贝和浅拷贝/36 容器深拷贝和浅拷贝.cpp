//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

//容器的添加元素是拷贝进去，所以如果成员数据中含有指针，就必须提供Big Three三大函数来解决浅拷贝的问题
//STL都是值寓意，并非拷贝寓意
//除了queue和stack之外，每个容器都提供返回迭代器的函数，begin()和end()
//都提供了size()和empty()
//-----------------------------------------
class Person {
public:
    Person(const char* name, int age) :mAge(age) {
        this->mName = new char[strlen(name) + 1];
        strcpy(this->mName, name);
    }

    Person(const Person& person) {
        this->mAge = person.mAge;
        this->mName = new char[strlen(person.mName) + 1];
        strcpy(this->mName, person.mName);
    }

    Person& operator=(const Person& person) {
        this->mAge = person.mAge;

        if (this->mName = person.mName) {
            return *this;
        }
        if (this->mName!= NULL) {
            delete[]this->mName;
        }

        this->mName = new char[strlen(person.mName) + 1];
        strcpy(this->mName, person.mName);
        return *this;
    }

    ~Person(){
        if (this->mName != NULL) {
            delete[] this->mName;
            this->mName = NULL;
        }
    }
public:
    char* mName;
    int mAge;
};

void test36_01() {
    Person p("A", 28);
    vector<Person> vPerson;
    vPerson.push_back(p);

    for (const auto& c : vPerson) {
        cout << "Name: " << c.mName << " Age: " << c.mAge << endl;
    }
}

int main() {

    test36_01();
    return 0;
}

/*
 *
 *
 *
 *
 */

