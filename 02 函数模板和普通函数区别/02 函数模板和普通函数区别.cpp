//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#include<iostream>

using namespace std;

//-----------------------------------------函数模板不能进行自动类型转化
template<class T>
int myAdd(const T& a, const T& b) {
	cout << "int myAdd(const T& a, const T& b)..." << endl;
	return a + b;
}

int myAdd(const int& a, const int& b) {
	cout << "int myAdd(const int& a, const int& b)..." << endl;
	return a + b;
}

void test02() {
	int a = 10, b = 20;
	char c = 'c', d = 'd';
	//-----------------------------------------函数模板和普通函数之间发生重载, 编译器优先匹配普通函数
	//-----------------------------------------如果非要调用模板函数，用<>符号强制调用
	cout << myAdd<>(a, b) << endl;
	//cout << myAdd(a, c) << endl;
	//cout << myAdd(c, a) << endl;
}

//-----------------------------------------函数模板之间发生重载
template<class T>
void print(const T& a,const T &b) {

}

template<class T>
void print(const T& a) {

}

int main() {

	test02();
	return 0;
}