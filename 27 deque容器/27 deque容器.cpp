//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<deque>

using namespace std;
void Print(deque<int>& d) {
    for (deque<int>::iterator i = d.begin(); i != d.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;
}

//-----------------------------------------
//��ʼ��
void test27_01() {
    deque<int>d1;
    deque<int>d2(10, 5);
    deque<int>d3{ 10,5,1 };
    deque<int>d4(d3.begin(), d3.end()-1);
    deque<int>d5 = d4;
    deque<int>d6(d5);

    Print(d6);
}


//��ֵ�ʹ�С����
void test27_02() {
    deque<int>d1;
    deque<int>d2;
    deque<int>d3;
    d1.assign(10, 5);
    d2.assign(d1.begin() + 1, d1.end() - 4);    //������ָ������
    d3 = d2;    //���صȺ�
    swap(d1, d2);
    d1.swap(d2);

    //deque�����п����Ͷ����ͬ��С�ڴ���д洢���Լ�ά���ռ��С�������ֶ�����
    //����deque�ڲ�ʵ�ֹ��ڸ��ӣ�����ʱ�࿽����vector�������ٿ�����deque
    if (d1.empty()) {
        cout << "�գ�" << endl;
    }
    else {
        cout << "Size: " << d1.size() << endl;
    }
    d1.resize(10);
    d1.resize(15, 5);
}

//deque���������˲����ɾ��
void test27_03() {
    deque<int>d1;
    d1.push_back(100);
    d1.push_front(10);

    //ɾ�������޷���ֵ��ʹ��front��backȡ�ü�����ɾ����Ԫ��
    int front = d1.front();
    int back = d1.back();
    d1.pop_back();
    d1.pop_front();
}

int main() {

    test27_01();
    return 0;
}

/*
 *
 *
 *
 *
 */

