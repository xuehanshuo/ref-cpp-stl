//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
using namespace std;
//map具有key和value，键值和实值，元素根据键值自动排序
//pair的第一元素为键值，第二元素为实值。元素以键值对形式存在。
//可以用map的迭代器改变实值，不可改变键值
//-----------------------------------------
//初始化
void test34_01() {
    //map容器模板参数，第一个为key的类型，第二个为value的类型
    map<int, int> mymap;

    //插入数据
    //第一种：匿名对象(insert返回pair，second是bool类型，判断插入是否成功)
    pair<map<int,int>::iterator, bool>ret=mymap.insert(pair<int, int>(10, 10));
    if (ret.second) {
        cout << "Operation 1 succeeded!" << endl;
    }
    else {
        cout << "Operation 1 failed!" << endl;
    }
    
    ret = mymap.insert(pair<int, int>(10, 20));
    if (ret.second) {
        cout << "Operation 2 succeeded!" << endl;
    }
    else {
        cout << "Operation 2 failed!" << endl;
    }
    //第二种：make_pair
    mymap.insert(make_pair(20, 20));
    //第三种：value_type
    mymap.insert(map<int, int>::value_type(30, 30));
    //第四种：类似数组
    //key不存在时正常插入
    //key存在时修改键值，这是上面三种做不到的
    mymap[40] = 40;
    mymap[10] = 20;

    //打印
    for (map<int, int>::iterator it = mymap.begin(); it != mymap.end(); ++it) {
        cout << "Key： " << it->first << " Value: " << (*it).second << endl;
    }

    //如果通过map[]方式去访问一个本来不存在的key
    //map将访问的key插入到map中，并进行默认初始化
    cout << "mymap[50]: " << mymap[50] << endl;
    for (map<int, int>::iterator it = mymap.begin(); it != mymap.end(); ++it) {
        cout << "Key： " << it->first << " Value: " << (*it).second << endl;
    }
}

//用自定义对象创建map
class Person {
public:
    Person(int index, int id) :mIndex(index), mID(id) {};
public:
    int mIndex;
    int mID;
};
class compare {
public:
    bool operator()(const Person& p1, const Person& p2)const {
        return p1.mIndex < p2.mIndex;
    }
public:
};
void test34_02() {
    map<Person, int,compare>mymap;

    mymap.insert(make_pair(Person(10, 20), 40));
    mymap.insert(make_pair(Person(20, 40), 400));
    mymap.insert(make_pair(Person(30, 60), 4000));

    for (map<Person, int, compare>::iterator it = mymap.begin(); it != mymap.end(); ++it) {
        cout << "Index: " << it->first.mIndex << " " << "ID: " << (*it).first.mID << " " << "Value: " << it->second << endl;
    }
}

//equal_range
void test34_03() {
    map<int, int> mymap;
    mymap.insert(make_pair(10, 100));
    mymap.insert(make_pair(20, 200));
    mymap.insert(make_pair(30, 300));

    pair<map<int,int>::iterator,map<int,int>::iterator> ret=mymap.equal_range(20);
    if (ret.first==mymap.end()) {
        cout << "Search failed!" << endl;
    }
    else {
        cout << "Search succeeded!" << endl;
    }
}

int main() {

    //test34_01();
    //test34_02();
    test34_03();
    return 0;
}

/*
 *
 *
 *
 *
 */

