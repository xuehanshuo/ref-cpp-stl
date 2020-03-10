//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#include<iostream>

using namespace std;

//-----------------------------------------
template<class T>
class MyArray {
public:
    //有参构造
    MyArray(const int& capacity):mCapacity(capacity), mSize(0) {
        this->pAddr = new T[mCapacity];
    }

    //拷贝构造
    MyArray(const MyArray<T>& array) {
        this->mCapacity = array.mCapacity;
        this->mSize = array.mSize;
        this->pAdd = new T[this->mCapacity];
        for (int i = 0; i < this->mSize; ++i) { 
            this->pAdd[i] = array.pAdd[i];
        }
    }

    //成员函数：拷贝赋值
    //传入和返回的都是特定类型的具体的类
    //考虑自我赋值，指针是否为空
    MyArray<T>& operator=(const MyArray<T>& array) {
        if (this->pAddr = array.pAddr)return *this;
        
        if (this->pAddr != NULL)delete[]this->pAddr;

        this->mCapacity = array.mCapacity;
        this->mSize = array.mSize;
        this->pAdd = new T[this->mCapacity];
        for (int i = 0; i < this->mSize; ++i) {
            this->pAdd[i] = array.pAdd[i];
        }
        return *this;
    }
    

    //成员函数：重载[]
    //应该传入下标，返回单个T类型元素
    T& operator[](const int& index) {
        return this->pAddr[index];
    }
    
    //成员函数：添加元素
    //1.调用了“=”操作符，应该注意要拷贝的对象必须支持“=”进行拷贝(防止浅拷贝，不支持等)
    //2.容器都是值寓意，而非引用寓意，向容器中放入元素，都是放入元素的拷贝份
    void PushBack(const T& data) {
        cout << "void PushBack(const T& data)..." << endl;
        if (this->mSize >=this-> mCapacity)return;
        this->pAddr[this->mSize] = data;
        ++this->mSize;
    }
#if 1
    //成员函数：添加元素(重载)
    //对右值取引用&&，优先调用
    void PushBack(const T&& data) {
        cout << "void PushBack(const T&& data)..." << endl;
        if (this->mSize >= this->mCapacity)return;
        this->pAddr[this->mSize] = data;
        ++this->mSize;
    }
#endif
    
    //成员函数：返回mSize
    const int& Get_mSize()const {
        return this->mSize;
    }

    //析构函数
    ~MyArray()
    {
        if (this->pAddr != NULL) {
            delete[]this->pAddr;
            this->pAddr = NULL;
        }
    }

private:
    int mCapacity;
    int mSize;
    T* pAddr;
};



void test12() {
    MyArray<int> a(20);
    const int b = 100;
    //a.PushBack(100);
    //a.PushBack(200);
    a.PushBack(b);
    for (int i = 0; i < a.Get_mSize(); ++i) {
        cout << a[i] << endl;
    }
}

int main() {

    test12();
    return 0;
}

/*
 *
 *
 *
 *
 */

