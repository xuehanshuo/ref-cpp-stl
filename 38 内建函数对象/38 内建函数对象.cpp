//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<functional>

using namespace std;

//-----------------------------------------
//算术类函数对象
void test38_01() {
    //二元
    plus<int> myplus;                   //加
    minus<int>myminus;                  //减
    multiplies<int>mymultipulies;       //乘
    divides<int>mydivides;              //除
    modulus<int>mymodulus;              //取模
    //一元
    negate<int>mynegate;                //取反

    cout << myplus(10, 20) << endl;
    cout << minus<int>()(5, 6) << endl;
}

//关系运算类函数对象
void test38_02() {
    //二元
    equal_to<int>f1;                    //等于
    not_equal_to<int>f2;                //不等于
    greater<int>f3;                     //大于
    greater_equal<int>f4;               //大于等于
    less<int>f5;                        //小于
    less_equal<int>f6;                  //小于等于
}

//逻辑运算类函数对象
void test38_03() {
    //二元
    logical_and<int>f1;                 //逻辑与
    logical_or<int>f2;                  //逻辑或
    //一元
    logical_not<int>f3;                 //逻辑非
}

int main() {

    test38_01();
    return 0;
}

/*
 *
 *
 *
 *
 */

