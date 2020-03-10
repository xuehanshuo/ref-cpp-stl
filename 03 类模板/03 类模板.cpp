//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#include<iostream>

using namespace std;

template<class T>
class Person {
public:
	Person(const T& id, const T& age) :mId(id), mIge(age) {};
	void Show()const {
		cout << "ID: " << mId << " Age: " << mIge << endl;
	}
private:
	T mId;
	T mIge;
};

//-----------------------------------------函数模板可以自动类型推导
//-----------------------------------------类模板必须指定类型
void test03(){
	Person<int> p(10, 20);
	p.Show();
}

int main() {
	
	test03();
	return 0;
}