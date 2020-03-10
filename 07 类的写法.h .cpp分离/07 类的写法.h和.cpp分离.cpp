//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#include<iostream>
//-----------------------------------------需要引入类的头文件，才能使用这个类
#include"Person.h"

using namespace std;

//-----------------------------------------

int main() {
	Person p("Hodor", 13, 18);
	p.Show();

	return 0;
}

