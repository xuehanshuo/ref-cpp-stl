//-----------------------------------------����ͷ�ļ��Ĳ���д��������

//-----------------------------------------����ʽ����д��1
//-----------------------------------------Ctrl+Shift+U ��ɴ�д
/*
#ifndef PERSON_H
#define PERSON_H

#endif PERSON_H
*/

//-----------------------------------------����ʽ����д��2(c++)����ֹͷ�ļ����ظ�����
#pragma once
#include<iostream>
#include<string>

using namespace std;

class Person {
public:
	//-----------------------------------------����д������ԭ�ͣ����������������б�ͷ���ֵ���Լ�const��
	//-----------------------------------------��ʼ���б�Ҳ���ڶ����һ����
	Person(const string& name, const int& id, const int& age) ;
	//-----------------------------------------const�ؼ���Ҳ���ں���ԭ�͵�һ���֣�
	void Show()const;
private:
	string mName;
	int mID;
	int mAge;
};
