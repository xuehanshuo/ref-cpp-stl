//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>   //文件读写引入头文件

using namespace std;

//-----------------------------------------
//文本文件读写
void test22_01() {
    const char* filename = "C:\\Users\\HP\\Desktop\\C++ STL\\Source.txt";   //字符串中'\'写两个
    const char* targetname = "C:\\Users\\HP\\Desktop\\C++ STL\\Target.txt";
    //构造函数中打开文件
    ifstream ifs(filename, ios::in);    //只读方式打开文件，默认文本文件
    ofstream ofs(targetname, ios::out|ios::app);    //app表示追加

    //成员函数打开文件
    //ifstream ifs;
    //ifs.open(filename, ios::in);

    //判断打开文件是否成功，重载了'!'操作符
    if (!ifs) {
        cout << "打开文件失败！" << endl;
    }

    //读文件
    char ch;
    while (ifs.get(ch)) {
        cout << ch;
        ofs.put(ch);
    }

    //关闭文件
    ifs.close();
    ofs.close();
}

//二进制文件操作 对象序列化
class Person {
public:
    Person() = default;
    Person(const int& id,const int& age):mID(id),mAge(age){}
    void Show()const {
        cout << "void Show()const..." << endl;
        cout << "ID: " << mID << " Age: " << mAge << endl;
    }
private:
    int mID;
    int mAge;
};

void test22_02() {
    //文本模式和二进制模式的差异只存在于是否需要进行Windows下的\r\n和Linus下的\n转换
    //实际文件均存储为二进制模式

    //把p1，p2写进文件里
    Person p1(10, 20), p2(30, 40);
    const char* targetname = "C:\\Users\\HP\\Desktop\\C++ STL\\Target.txt";
    //二进制方式打开文件
    ofstream ofs(targetname, ios::out | ios::binary);

    //二进制方式写文件 write(char* p, sizeof())
    ofs.write((char*)&p1, sizeof(Person));
    ofs.write((char*)&p2, sizeof(Person));

    //关闭文件
    ofs.close();

    //二进制方式打开文件
    ifstream ifs(targetname, ios::in | ios::binary);

    //二进制方式读文件
    Person p3, p4;
    ifs.read((char*)&p3, sizeof(Person));
    ifs.read((char*)&p4, sizeof(Person));

    p3.Show();
    p4.Show();

    //关闭文件
    ifs.close();
}

int main() {

    //test22_01();
    test22_02();
    return 0;
}

/*
 *
 *
 *
 *
 */

