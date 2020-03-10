//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std; 
//希望每次打印时传进去固定的参数，但是for_each只支持一个参数的函数，所以采用适配器合并参数
//添加头文件functional，同时需要继承一个父类将参数类型和返回值作为类模板参数，同时重载函数必须加const
//仿函数两个参数用binary_function，一个参数用unary_function
//-----------------------------------------
//仿函数适配器    bind1st bind2nd     绑定适配器
class print :public binary_function<int,int,void>{
public:
    void operator()( int i,int val)const {
        cout << "i= " << i << "val= " << val;
        cout << i + val << endl;
    }
public:
};

void test39_01() {
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    //下面用了匿名对象，也可以实例化一个对象传进去 compare c，之后传进去c，只要保证可以向后面直接加括号传参数即可
    //for_each(v.begin(), v.end(), compare());
    for_each(v.begin(), v.end(), bind2nd(print(), 100));
    cout << endl;
    int addNum = 200;
    for_each(v.begin(), v.end(), bind2nd(print(), addNum));
    //绑定适配器 将一个二元函数对象转变成一元函数对象

    //bind1st和bind2nd的区别：
    //bind1st 将addNum绑定为函数对象的第一个参数
    //bind2nd 将addNum绑定为函数对象的第二个参数
}

//仿函数适配器    not1 not2   取反适配器
class compare:public binary_function<int,int,bool> {
public:
    bool operator()(int a, int b)const {
        return a > b;
    }
public:
};

class print2 {
public:
    void operator()(int i)const {
        cout << i << " ";
    }
public:
};

class greater5 :public unary_function <int,bool> {
public:
    bool operator()(int i)const {
        return i > 5;
    }
public:
};

void test39_02() {
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(rand()%100);
    }

    for_each(v.begin(), v.end(), print2());
    cout << endl;
    sort(v.begin(), v.end(), not2(compare()));
    for_each(v.begin(), v.end(), print2());
    cout << endl;

    //谓词：返回值是bool的仿函数
    //not1和not2区别
    //如果对二元谓词取反，用not2
    //如果对一元谓词取反，用not1

    //发现第一个大于5的进行返回迭代器
    vector<int>::iterator it = find_if(v.begin(), v.end(), greater5());
    cout << *it << endl;
    it = find_if(v.begin(), v.end(), not1(greater5()));
    if (it == v.end()) {
        cout << "没有找到！" << endl;
    }
    else {
        cout << *it << endl;
    }
}

//仿函数适配器    ptr_fun
void print3(int val,int val2) {
    cout << val+val2 << " ";
}
void test39_03() {
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    //for_each(v.begin(), v.end(), print3);
    //cout << endl;

    //把普通函数适配成函数对象
    //for_each(v.begin(), v.end(), ptr_fun(print3));
    //cout << endl;

    //再用前面的适配器，直接添加参数，不用继承
    for_each(v.begin(), v.end(), bind2nd(ptr_fun(print3),100));
}

//成员函数适配器  mem_fun mem_fun_ref 
class Person {
public:
    Person(const int& id,const int& age):mID(id),mAge(age){}
    void Show()const {
        cout << "ID: " << mID << " Age: " << mAge << endl;
    }
public:
    int mID;
    int mAge;
};
void test39_04() {
    //如果容器中存放着对象或者对象指针，我们用for_each算法打印的时候，希望调用自己类中的成员函数进行打印

    //放对象时：mem_fun_ref
    //格式：&类名::函数名
    vector<Person>v{ Person(10, 20), Person(30, 40), Person(50, 60) };
    for_each(v.begin(), v.end(), mem_fun_ref(&Person::Show));

    //放对象指针时：mem_fun
    vector<Person*>v2{ &Person(10, 20), &Person(30, 40), &Person(50, 60) };
    for_each(v2.begin(), v2.end(), mem_fun(&Person::Show));
}

int main() {

    //test39_01();
    //test39_02();
    //test39_03();
    test39_04();
    return 0;
}

/*
 *
 *
 *
 *
 */

