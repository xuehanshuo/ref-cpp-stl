//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#include<iostream>
#include"Person.hpp"

using namespace std;

//-----------------------------------------

int main() {

	Person<int> p(10);
	p.Show();

	return 0;
}

