//-----------------------------------------引入对应类的头文件
#include "Person.h"

//-----------------------------------------在类的函数定义部分写函数定义，即实现，并且需要加上类名
//-----------------------------------------类的构造函数上不能加const！
Person::Person(const string& name, const int& id, const int& age)
	:mName(name), mID(id), mAge(age) {};

void Person::Show()const {
	cout << " Age: " << this->mAge 
		<< " ID: " << this->mID 
		<< " Name: " << this->mName << endl;
};