//-----------------------------------------�����Ӧ���ͷ�ļ�
#include "Person.h"

//-----------------------------------------����ĺ������岿��д�������壬��ʵ�֣�������Ҫ��������
//-----------------------------------------��Ĺ��캯���ϲ��ܼ�const��
Person::Person(const string& name, const int& id, const int& age)
	:mName(name), mID(id), mAge(age) {};

void Person::Show()const {
	cout << " Age: " << this->mAge 
		<< " ID: " << this->mID 
		<< " Name: " << this->mName << endl;
};