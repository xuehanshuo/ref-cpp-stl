#pragma once

#include<iostream>
using namespace std;

template<class T>
class Person {
public:
	Person(const T& age);
	void Show()const;
private:
	T mAge;
};