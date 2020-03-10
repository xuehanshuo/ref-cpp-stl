//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#include<iostream>

using namespace std;

//-----------------------------------------
class Animal{};
class Cat :public Animal {};
class Building{};
//-----------------------------------------static_cast类型转换
//用于内置的数据类型，还有具有继承关系的指针或者引用
void test13_01() {
    //支持——基础数据类型转换
    int a = 97;
    char c = static_cast<char>(a);
   
    //支持——具有继承关系的对象指针转换
    //父类转子类
    Animal* ani = NULL;
    Cat* cat = static_cast<Cat*>(ani);
    //子类转父类
    Cat* catt = NULL;
    Animal* anii = static_cast<Animal*>(catt);

    //支持——具有继承关系的对象引用转换
    //父类转子类
    Animal aa;
    Animal& r_a = aa;
    Cat& r_c = static_cast<Cat&>(r_a);
    //子类转父类
    Cat cc;
    Cat& r_cc = cc;
    Animal& r_aa = static_cast<Animal&>(r_cc);

    //不支持基础数据类型指针转换
    //不支持非继承关系对象指针和引用转换
}

//-----------------------------------------dynamic_cast类型转换
//转换具有继承关系的指针或者引用，且在转换前进行对象类型检查，只能子类型转成父类型
void test13_02() {
    //部分支持——具有继承关系的对象指针转换(与多态接收指针要区分开)
    //支持子类指针转换成父类指针(从大到小)，类型安全，不会越界访问到额外的区域
    Cat* c = NULL;
    Animal* a = dynamic_cast<Animal*>(c);
    
    //不支持父类指针转换成子类指针(从小到大)，类型不安全
    //不支持基础数据类型转换
    //不支持非继承关系对象指针和引用转换
}

//-----------------------------------------const_cast类型转换
//用于基础数据类型，指针，引用或者对象指针的增加const和去除const
//这种去除和增加是对于赋值而言的，对被转化的本身对象无影响
void test13_03() {
    //基础数据类型
    int a = 10;
    const int& b = a;
    int& c = const_cast<int&>(b);
    c = 20;

    //指针
    //去除底层const性
    const int* p = NULL;
    int* pp = const_cast<int*>(p);
    //去除顶层const性
    int* const bp = NULL;
    int* bbp = const_cast<int*>(bp);

}

//-----------------------------------------reinterpret_cast类型转换
//任何类型的均可以支持
typedef void(*FUNC1)(int, int);
typedef int(*FUNC2)(int, char*);
void test13_04() {
    //完全无关的对象指针进行转换
    Building* buil = NULL;
    Animal* ani = reinterpret_cast<Animal*>(buil);

    //完全无关的函数指针进行转换
    FUNC1 func1=NULL;
    FUNC2 func2 = reinterpret_cast<FUNC2>(func1);
}

int main() {


    return 0;
}

/*
 *
 *
 *
 *
 */

