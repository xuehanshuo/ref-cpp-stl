//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#include<iostream>

using namespace std;

//-----------------------------------------
template<class T>
class People {
public:
	People() :mAge(0) {};
private:
	T mAge;
};

//-----------------------------------------类模板派生出来的普通类必须写出明确的类型，否则无法分配内存
class SubPeople :public People <int>{
};

int main() {


	return 0;
}

