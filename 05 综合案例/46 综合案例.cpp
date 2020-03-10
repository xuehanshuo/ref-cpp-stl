//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<array>
#include<algorithm>
#include<numeric>
#include<functional>
#include<deque>
#include<ctime>

using namespace std;
//每一次比赛有抽签，打分得到晋级名单，展示优秀选手三部分组成
//选手有编号，编号不相同，使用map存储，key存编号，value存选手对象，对象包含名字和分数列表，不应该重复存储编号，应该用vector对编号排序
//创建对象存到map容器和vector容器中，实现三轮比赛
//-----------------------------------------
class Player {
public:
public:
    string mName;
    array<int,3> mScore;
};

void CreatePlayer(map<int, Player>& m, vector<int>& v) {
    string seedName = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < 24; ++i) {
        //名字
        Player p;
        p.mName = "Player ";
        p.mName += seedName.at(i);
        //分数
        for (auto& c : p.mScore) {
            c = 0;
        }
        //ID传入vector
        int ID=100+i;
        v.push_back(ID);
        //信息传入map
        m.insert(make_pair(ID, p));
    }
}

void SetGroup(vector<int>& v) {
    random_shuffle(v.begin(), v.end());
}

class compare {
public:
    bool operator()(const int& a, const int& b)const {
        return a > b;
    }
public:
};

void GetScore(const int& num,vector<int>& v, map<int, Player>& m, vector<int>& vnext) {
    //左分数，右编号
    //默认从小到大排序
    //可使用仿函数或者内建函数对象
    //不清楚为什么这里不传函数对象，而是传类名
    multimap<int, int,compare> mGroup;
    //multimap<int, int, greater<int>> mGroup;
    srand((unsigned int)time(NULL));
    //记录是不是到了6个
    int count = 0;
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        deque<int> d;
        //生成随机分
        for (int i = 0; i < 10; ++i) {
            int score = rand() % 41 + 60;
            d.push_back(score);
        }
        //排序
        sort(d.begin(), d.end());
        d.pop_back();
        d.pop_front();
        //总分和平均分
        int total = accumulate(d.begin(), d.end(), 0);
        int avg = total / d.size();
        //保存分数
        m[*it].mScore[num - 1] = avg;
        //利用multimap取得每组前三名，自动排序，分数为key可重复，编号为value
        ++count;
        mGroup.insert(make_pair(avg, *it));
        if (count % 6==0) {
            //不支持迭代器加整数，所以需要额外变量
            int count2 = 0;
            for (multimap<int, int>::iterator it = mGroup.begin(); it != mGroup.end() && count2 < 3; ++it, ++count2) {
                vnext.push_back((*it).second);
            }
            //清空group
            mGroup.clear();
        }
    }
}

void Show(const int& num, map<int, Player>& m, vector<int>& v) {
    cout << "The " << num << " Group of Winners: " << endl;
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << "Name: " << m[*it].mName << " Score: " << m[*it].mScore[num - 1] << endl;
    }
    cout << "————————————————————————————————————————————" << endl;
}

int main() {
    //创建两个容器
    map<int, Player>m;
    vector<int>v1,v2,v3,v4;

    //创建选手
    CreatePlayer(m, v1);
    
    //第一轮比赛
    SetGroup(v1);
    GetScore(1,v1,m,v2);
    Show(1,m,v2);

    //第二轮比赛
    SetGroup(v2);
    GetScore(2, v2, m, v3);
    Show(2, m, v3);

    //第三轮比赛
    SetGroup(v3);
    GetScore(3, v3, m, v4);
    Show(3, m, v4);

    return 0;
}

/*
 *
 *
 *
 *
 */

