#include"Person.h"


template<class T>
Person<T>::Person(const T& age) :mAge(age) {};

template<class T>
void Person<T>::Show()const {
	cout << "Age: " << mAge << endl;
}



/*
 * 1.C++中的函数模板编译过程是分成2步，先对模板进行一次处理，再根据有没有调用生成函数
 * 2.C++中文件是单独编译，遇到声明则跳过留给链接器处理
 * 3.如果说单纯引入Person.h，Person.cpp中的函数模板进行单独编译，不会受到调用，则不会根据类型生成指定类型具体函数，这样在main调用构造函数的时候
 *   就找不到具体的函数定义，于是报错。然而如果不调用构造，则不会报错。
 * 4.解决方法：引入文件从Person.h变成Person.cpp，则相当于拷贝进来有调用，能生成具体函数，为了方便认知改成hpp，表明里面写的是类模板需要引入。
 */
