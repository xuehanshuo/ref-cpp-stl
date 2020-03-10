//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#include<iostream>

using namespace std;

//-----------------------------------------
//-----------------------------------------谨记：类模板在类外实现一定要避免滥用友元

template<class T>class Person;
template<class T>void Print(const Person<T>& p);

template<class T>
class Person {
public:
	//-----------------------------------------编译器碰到声明不编译，链接时找不到函数报：无法解析的外部符号
	//-----------------------------------------尝试使用重载操作符输出，必须函数模板对应函数模板，需要在声明处也加template
	//-----------------------------------------但是在Linus下编译不通过，所以更普遍的是在操作符后面加<T>
	//template<class T>
	friend ostream& operator<< <T> (ostream& os, const Person<T>& p);

	//-----------------------------------------普通友元函数可以使用template
	//-----------------------------------------但是更多的情况下我们把对类的template声明放在外面，对友元函数的声明同时放在外面，之后在函数名和参数列表之间加<T>
	//template<class T>
	friend void Print <T>(const Person<T>&p);
	Person(const T& age, const T& id);
	void Show()const;
private:
	T mAge;
	T mID;
};

//-----------------------------------------类模板中函数在外部实现，需要加上：template<class T>以及类名
//-----------------------------------------并且类名需要加上<T>，表示是T类型的Person类，一个成员函数只能属于一个具体的类
template<class T>
Person<T>::Person(const T& age, const T& id)
	:mAge(age), mID(id) {};

//-----------------------------------------即使函数体内没有显式的T，是模板类中的函数，就必须加template<class T>
template<class T>
void Person<T>::Show()const {
	cout << "void Show()const..." << endl;
}


template<class T>
ostream& operator<< (ostream& os, const Person<T>& p) {
	os << "ID: " << p.mID << " Age:" << p.mAge << endl;
	return os;
}

template<class T>
void Print(const Person<T>&p) {
	cout<< "ID: " << p.mID << " Age:" << p.mAge << endl;
}


void test09() {
	Person<int> p(10, 20);
	//p.Show();
	cout << p;
}

int main() {

	test09();
	return 0;
}

