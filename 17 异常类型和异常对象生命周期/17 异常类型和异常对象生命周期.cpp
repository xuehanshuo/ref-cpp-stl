//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

//-----------------------------------------
class MyException {
public:
    MyException(const char* str) {
        this->error = new char[strlen(str) + 1];
        strcpy(this->error, str);
    }
    void what()const {
        cout << "未知异常："<<error << endl;
    }
    ~MyException() {
        if (this->error != NULL) {
            delete[]this->error;
        }
    }
private:
    char* error;
};

void test17(){
    //抛出的是一个匿名对象
    throw MyException("异常");
}

int main() {
    try {
        test17();
    }
    //这个时候如果不用引用，会进行浅拷贝，析构函数会对同一块内存调用两次delete[]，程序宕掉
    catch (const MyException & e) {
        e.what();
    }

    return 0;
}

/*
 *
 *
 *
 *
 */

