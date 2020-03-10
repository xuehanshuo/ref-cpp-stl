//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#include<iostream>

using namespace std;

//----------------------------------------- 可以用class或者typename都可 template<typename T>
//-----------------------------------------  一个template头只对template后的第一个函数有效
//----------------------------------------- 可以template<class T1,class T2, class T3> 即写多个类型
template<class T>            
void mySwap(T &a,T &b) {
	T temp = a;
	a = b;
	b = temp;
}



void test01() {
	int a = 10, b = 20;
	cout << "a = " << a << " " << "b = " << b << endl;
	//-----------------------------------------01自动类型推导
	mySwap(a, b);
	cout << "a = " << a << " " << "b = " << b << endl;
	//-----------------------------------------02指定类型推导
	mySwap<int>(a, b);
	cout << "a = " << a << " " << "b = " << b << endl;

}

int main() {

	test01();
	return 0;
}