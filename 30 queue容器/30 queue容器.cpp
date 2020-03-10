//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>

using namespace std;
//queue容器 队列容器 先进先出 只能一端插入另一端删除
//不能遍历，不提供迭代器，不支持随机访问
//-----------------------------------------
//队尾back，push入队
//队头front，pop出队
void test30_01() {
    queue<int> q;
    //10 20 30 40进 10 20 30 40出
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    while (q.size() > 0) {
        cout << q.front() << endl;
        q.pop();
    }
}

int main() {


    return 0;
}

/*
 *
 *
 *
 *
 */

