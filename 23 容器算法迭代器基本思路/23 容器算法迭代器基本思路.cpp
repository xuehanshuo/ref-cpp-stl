//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

//-----------------------------------------
int count(const int* begin, const int* end, int num) {
    int times = 0;
    while (begin != end) {
        if (*begin == num)++times;
        ++begin;
    }
    return times;
}

int main() {

    int a[] = { 0,7,6,8,5,9,3 };
    int* pBegin = a;
    int* pEnd = &a[sizeof(a) / sizeof(int)];
    cout << count(pBegin, pEnd, 0) << endl;
    return 0;
}

/*
 *
 *
 *
 *
 */

