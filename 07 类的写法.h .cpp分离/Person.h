//-----------------------------------------类在头文件的部分写函数声明

//-----------------------------------------防卫式声明写法1
//-----------------------------------------Ctrl+Shift+U 变成大写
/*
#ifndef PERSON_H
#define PERSON_H

#endif PERSON_H
*/

//-----------------------------------------防卫式声明写法2(c++)，防止头文件被重复包含
#pragma once
#include<iostream>
#include<string>

using namespace std;

class Person {
public:
	//-----------------------------------------仅仅写出函数原型，即函数名，参数列表和返回值，以及const。
	//-----------------------------------------初始化列表也属于定义的一部分
	Person(const string& name, const int& id, const int& age) ;
	//-----------------------------------------const关键字也属于函数原型的一部分！
	void Show()const;
private:
	string mName;
	int mID;
	int mAge;
};
