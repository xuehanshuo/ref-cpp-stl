//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#include<iostream>

using namespace std;

//----------------------------------------- ������class����typename���� template<typename T>
//-----------------------------------------  һ��templateͷֻ��template��ĵ�һ��������Ч
//----------------------------------------- ����template<class T1,class T2, class T3> ��д�������
template<class T>            
void mySwap(T &a,T &b) {
	T temp = a;
	a = b;
	b = temp;
}



void test01() {
	int a = 10, b = 20;
	cout << "a = " << a << " " << "b = " << b << endl;
	//-----------------------------------------01�Զ������Ƶ�
	mySwap(a, b);
	cout << "a = " << a << " " << "b = " << b << endl;
	//-----------------------------------------02ָ�������Ƶ�
	mySwap<int>(a, b);
	cout << "a = " << a << " " << "b = " << b << endl;

}

int main() {

	test01();
	return 0;
}