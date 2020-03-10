//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>

using namespace std;
//copy swap
//replace replace_if
//-----------------------------------------
//copy swap
class print {
public:
    void operator()(const int& val)const {
        cout << val << " ";
    }
public:
};
void test02_01() {
    vector<int> v1, v2, v3;
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 10; ++i) {
        v1.push_back(rand() & 100);
    }

    //在copy之前要确保有足够的空间
    v2.resize(v1.size());
    copy(v1.begin(),v1.end(),v2.begin());
    for_each(v1.begin(), v1.end(), print()); cout << endl;
    for_each(v2.begin(), v2.end(), print()); cout << endl;
    cout << "----------------------------" << endl;
    
    for (int i = 0; i < 10; ++i) {
        v3.push_back(rand() & 100);
    }
    for_each(v2.begin(), v2.end(), print()); cout << endl;
    for_each(v3.begin(), v3.end(), print()); cout << endl;
    cout << "----------------------------" << endl;

    swap(v2, v3);
    for_each(v2.begin(), v2.end(), print()); cout << endl;
    for_each(v3.begin(), v3.end(), print()); cout << endl;
}

//replace replace_if
//找不到就不替换
//replace_if需要传谓词
class compare {
public:
    bool operator()(const int& val)const {
        return val > 5;
    }
public:
};
void test02_02() {
    vector<int>v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), print()); cout << endl;
    replace(v.begin(), v.end(), 5, 100);
    for_each(v.begin(), v.end(), print()); cout << endl;
    replace_if(v.begin(), v.end(), compare(), 200);
    for_each(v.begin(), v.end(), print()); cout << endl;
}

int main() {

    //test02_01();
    test02_02();
    return 0;
}

/*
 *
 *
 *
 *
 */

