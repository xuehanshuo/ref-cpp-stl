//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

//-----------------------------------------
//初始化
void test25_01() {
    //无参
    string s1;
    
    //构造
    string s2(10, 'a');
    
    //C风格字符串
    string s3("abcdefg");
    
    //拷贝
    string s4(s3);
}

//赋值
void test25_02() {
    string s1;
    string s2("abc");
    //重载'='，接收C风格字符串
    s1 = "abcdef";
    
    //重载'='，接收string类型
    s2 = s1;
    
    //重载'='，接收char类型
    s1 = 'A';
    
    //成员函数assign
    s1.assign("abc");
}

//访问
void test25_03() {
    //要么用迭代器+begin+end，要么用int+size，迭代器不能作为下标
    string s1 = "abcdef";

    //重载[]操作符
    for (int i = 0; i < s1.size(); ++i) {
        cout << s1[i] << " ";
    }

    //成员函数at
    for (int i = 0; i < s1.size(); ++i) {
        cout << s1.at(i) << " ";
    }

    //区别：at可以针对越界访问抛出out_of_range异常，[]只会宕掉
    try {
        //cout << s1[100] << endl;
        cout << s1.at(100) << endl;
    }
    catch(...){
        cout << "越界！" << endl;
    }
}

//拼接
void test25_04() {
    string s1 = "abcd";
    string s2 = "efg";
    //重载 += 操作符，接收string类型，C风格字符串和字符类型。不可链式编程。
    s1 += s2;
    s1 += "hijk";
    s1 += 'l';

    //重载 + 操作符
    string s3 = s1 + s2;

    //成员函数append
    string s4 = "3333";
    s2.append(s4);
}

//查找
void test25_05() {
    string s1 = "abcdefghijklmn";
    //查找第一次出现的位置
    int pos = s1.find("fg");
    cout << "pos: " << pos << endl;

    //查找最后一次出现的位置
    pos = s1.rfind("fg");
    cout << "pos: " << pos << endl;
}

//替换
void test25_06() {
    string s1 = "abcdefg";
    //替换从0开始的2个字符，把它们替换成123
    s1.replace(0, 2, "123");
    cout << s1;
}

//比较
void test25_07() {
    string s1 = "abcd";
    string s2 = "abce";
    //字典序比较，大写A小于小写a，返回1，0，-1
    if (s1.compare(s2) == 0) {
        cout << "s1和s2相等！" << endl;
    }
    else cout << "s1和s2不相等！" << endl;
}

//子串
void test25_08() {
    string s1 = "abcdefg";
    //从第1个位置截取3个字符
    string s2 = s1.substr(1, 3);
    cout << s2 << endl;
}

//插入和删除
void test25_09() {
    string s1 = "abcdefg";
    //在位置3的前面插入字符串111，重载了string类型，C风格字符串，n个字符类型
    s1.insert(3, "111");
    cout << s1 << endl;

    //从0号位置删除2个字符
    s1.erase(0, 2);
    cout << s1 << endl;
}

//string转换为char*
void test25_10() {
    string s1 = "abcdefg";
    const char* str = s1.c_str();
    cout << str << endl;
}

int main() {

    //test25_03();
    //test25_05();
    //test25_06();
    //test25_07();
    //test25_08();
    //test25_09();
    test25_10();
    return 0;
}

/*
 *
 *
 *
 *
 */

