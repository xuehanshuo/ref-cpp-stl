//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>

using namespace std;
//框架搭设后需要调用判断是否通过
//每个选手是一个对象->Person类
//分别进行创建选手，打分，排名三个部分，且选手应该存放在容器中->以vector为参数的三个架构函数
//-----------------------------------------
//选手类
class Person {
public:
    Person() = default;
    Person(const string& name,const int&score): mName(name),mScore(score){}
    string& getName() { return mName; }
    int& getScore() { return mScore; }
private:
    string mName;
    int mScore;
};

//创建选手函数——创建对象存到容器中
void CreatePlayer(vector<Person>& v) {
    string name = "ABCDE";
    for (int i = 0; i < 5; ++i) {
        Person p;
        p.getName() = "选手";
        p.getName() += name[i];
        p.getScore() = 0;
        
        v.push_back(p);
    }
}

//打分函数——经过一系列操作给选手打分
void SetScore(vector<Person>& v) {
    //对每个选手打随机分60-100之间，存在deque里
    for (auto& c : v) {
        deque<int>dScore;
        for (int i = 0; i < 10; ++i) {
            int score = rand() % 41 + 60;
            dScore.push_back(score);
        }

        //排序去除最大最小
        sort(dScore.begin(), dScore.end());
        dScore.pop_front();
        dScore.pop_back();

        //求平均值
        int totalScore = 0;
        for (const auto& c : dScore) {
            totalScore += c;
        }
        int avgScore = totalScore / dScore.size();

        //保存分数
        c.getScore() = avgScore;
    }   
}

//排名函数——得出最后排名
bool compare(Person& p1, Person& p2) {
    return p1.getScore() > p2.getScore();
}
void GetRank(vector<Person>& v) {
    //泛型算法，回调函数
    sort(v.begin(), v.end(), compare);
    for (auto& c : v) {
        cout << c.getName() << " " << c.getScore() << endl;
    }
}

int main() {

    vector<Person> vPlayer;
    CreatePlayer(vPlayer);
    SetScore(vPlayer);
    GetRank(vPlayer);
    return 0;
}

/*
 *
 *
 *
 *
 */

