//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>

using namespace std;
#if 0
cout;   //全局流对象 输出数据到显示器
cin;
//cerr没有缓冲区 clog有缓冲区
cerr;   //标准错误 输出数据到显示器
clog;   //标准日志 输出数据到显示器
#endif
//-----------------------------------------
//标准输入流
void test21_01() {
#if 0
    //cin.get() 从标准input读取一个字符，返回读到的字符
    //getchar()
    char ch;
    while ((ch = cin.get())!= EOF) {
        cout << ch << endl;
    }

    //cin.get(char c) 从标准input中读取一个字符，写到c中
    //getchar(c)
    char ch2;
    cin.get(ch2);
    cout << ch2 << endl;

    //cin.get(char* p, int length) 从缓冲区读一个字符串，写到buf里面，且读换行符
    char buf[1024] = { 0 };
    cin.get(buf, 1024);
    cout << buf << endl;

    //cin.getline(char* p, int length) 从缓冲区读一行字符串，写到buf里面，且不读换行符
    //gets()
    cin.getline(buf, 1024);
    cout << buf << endl;
#endif
}

void test21_02() {
    //cin.ignore(int n，char c) 在没找到字符c的前提下，忽略缓冲区中前面n个字符
    char ch;
    cin.get(ch);
    cout << ch << endl;
    cin.ignore();
    cin.get(ch);
    cout << ch << endl;
    
}

void test21_03() {
    //cin.peek() 仅仅看看缓存区第一个字符是什么，返回它但不取走
    cout << "输入一个数字或者字符串！"<<endl;
    char ch;
    ch = cin.peek();  
    if (ch >= '0' && ch <= '9') {
        int num;
        cin >> num;
        cout << "您输入的是数字：" << num<<endl;
    }
    else {
        char buf[1024] = { 0 };
        cin >> buf;
        cout << "您输入的是字符串：" << buf << endl;
    }
}

void test21_04() {
    //cin.putback(char c) 把字符c放回到缓冲区第一个位置
    cout << "输入一个数字或者字符串！" << endl;
    char ch;
    cin.get(ch);
    if (ch >= '0' && ch <= '9') {
        cin.putback(ch);
        int num;
        cin >> num;
        cout << "您输入的是数字：" << num << endl;
    }
    else {
        cin.putback(ch);
        char buf[1024] = { 0 };
        cin >> buf;
        cout << "您输入的是字符串：" << buf << endl;
    } 
}

//标准输出流
void test21_05() {
    //cout.flush() 没有endl时手动刷新缓冲区
    cout << "Hello World!" << endl;
    cout.flush();
    
    //cout.put(char c) 将字符c写入缓冲区，支持链式编程
    //putchar()
    cout.put('H').put('e')<<endl;

    //cout.write("str", int length) 将一个字符串写入缓冲区
    cout.write("Hello!", strlen("Hello!"));
}

//格式化输出
void test21_06() {
    //通过成员函数的方法
    //设置进制
    int num = 10;
    cout << num << endl;
    cout.unsetf(ios::dec);      //卸载当前默认的十进制输出方式
    cout.setf(ios::oct);        //八进制输出
    cout.setf(ios::showbase);   //显示八进制的格式 0+数字
    cout << num << endl;
    cout.unsetf(ios::oct);
    cout.setf(ios::hex);        //十六进制输出
    cout << num << endl;
    //设置位宽
    cout.width(10);
    cout.fill('*');             //位宽其余空位用fill()中的符号代替
    cout.setf(ios::left);       //左对齐
    cout << num << endl;

    //通过控制符
    int num2 = 10;
    cout << hex
        << setiosflags(ios::showbase)
        << setw(10)
        << setfill('~')
        << setiosflags(ios::left)
        << num2
        << endl;
}

int main() {

    //test21_01();
    //test21_02();
    //test21_03();
    //test21_04();
    //test21_05();
    test21_06();
    return 0;
}

/*
 *
 *
 *
 *
 */

