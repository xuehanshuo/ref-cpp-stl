//High cohesion & Low coupling
#include<iostream>

using namespace std;

//-----------------------------------------
template<class T>
class Animal {
public:
	Animal() :mAge(0){};
	Animal(const T& a) :mAge(a) {};
	void Print() const{
		cout << "年龄是：" << mAge << endl;
	}
private:
	T mAge;
};

template<class A>
class Cat:public Animal<A>{

};


int main() {

	Cat<int> cat1;

	return 0;
}

