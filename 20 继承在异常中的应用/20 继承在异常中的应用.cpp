//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

//-----------------------------------------
//异常基类——抽象类
class MyException {
public:
    //两个多态，一个是期望派生类重写what内容，一个是标准的抽象基类构造函数为虚函数
    virtual void what()const = 0;
    //虚析构函数必须有定义，哪怕函数体为空，否则报错。且构造函数不能为虚函数。
    //无论如何基类的构造和析构都需要执行自己的part，(包含在子类多态中的一部分，默认调用)，所以函数体是必要的。
    virtual ~MyException() = 0 {};
private:
};

class DesNULL :public MyException {
public:
    virtual void what()const {
        cout << "目标空间空" << endl;
    }
    virtual ~DesNULL(){}
private:
};

class SourceNULL :public MyException {
public:
    virtual void what()const {
        cout << "源空间空" << endl;
    }
    virtual ~SourceNULL(){}
private:
};

void CopyStr(char* des, const char* source) {
    if (des == NULL) {
        throw DesNULL();
        return;
    }
    if (source == NULL) {
        throw SourceNULL();
        return;
    }
    while (*source != '\0') {
        *des = *source;
        ++des;
        ++source;
    }
}

int main() {
    
    const char*source = "abcdef!";
    char des[1024] = { 0 };
    try {
        CopyStr(des, NULL);
    }
    catch (const MyException & e) {
        e.what();
    }
    cout << des << endl;

    return 0;
}

/*
 *
 *
 *
 *
 */

