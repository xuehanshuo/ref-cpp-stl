//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdexcept>

using namespace std;

//-----------------------------------------
class Person {
public:
    Person() = default;
    void setAge(const int& age) {
        if (age < 0 || age>1000)throw out_of_range("年龄应在0-1000之间！");
        this->mAge = age;
    }
private:
    int mAge;
};

//自己写的异常类应该继承于标准异常类
class MyOutOfRange:public exception {
public:
    MyOutOfRange(const char* error) {
        this->pError = new char[strlen(error) + 1];
        strcpy(this->pError, error);
    }
    //what()函数重写
    virtual char const* what() const {
        return this->pError;
    }
    ~MyOutOfRange()
    {
        if (this->pError != NULL)delete[]this->pError;
    }
private:
    char* pError;
};

void test19_01() {
    Person p;
    try {
        p.setAge(10000);
    }
    //这里既可以用out_of_range来接收，还可以用更大的类exception来接收
    //catch (out_of_range e) {
    catch(exception e){
        cout<<e.what();
    }
}

void func() {
    throw MyOutOfRange("我自己的out_of_range异常！");
}

void test19_02(){
    try {
        func();
    }
    catch (const exception &e) {
        cout << e.what() << endl;
    }
}

int main() {

    //test19_01();
    test19_02();
    return 0;
}

/*
 *
 *
 *
 *
 */

