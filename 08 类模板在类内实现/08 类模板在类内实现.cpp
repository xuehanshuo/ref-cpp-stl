//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#include<iostream>
#include<string>

using namespace std;

//-----------------------------------------多类型逗号隔开，记得关键字class
template<class T1,class T2>
class Person {
public:
	Person(const T1& name, const T2& age)
		:mName(name), mAge(age) {};
	void Show()const {
		cout << "void Show()const..." << endl;
	}
private:
	T1 mName;
	T2 mAge;
};

void test08() {
	Person<string, int> p("Hodor", 18);
	p.Show();
}

int main() {
	test08();

	return 0;
}

