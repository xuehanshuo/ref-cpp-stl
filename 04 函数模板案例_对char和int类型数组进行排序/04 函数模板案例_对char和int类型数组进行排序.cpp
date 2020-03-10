//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#include<iostream>

using namespace std;

//-----------------------------------------
template<class T>
void print(const T* arr, const int& len) {
	//-----------------------------------------不能使用范围for因为不知道什么时候到底
	for (int i = 0; i < len; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

template<class T>
void mySort(T* arr, const int& len) {
	for (int i = 0; i < len-1; ++i) {
		for (int j =  0; j < len - 1-i; ++j) {
			if (arr[j] > arr[j + 1]) {
				T temp = arr[j];
				arr[j] = arr[j+1];
				arr[j + 1] = temp;
			}
		}
	}
}


int main() {
	int a[] = { 3,8,2,6,4,5,1,0 };
	int lenA = sizeof(a) / sizeof(int);
	print(a, lenA);
	mySort(a, lenA);
	print(a, lenA);

	cout << "-----------------" << endl;

	char b[] = "good";
	int lenB = sizeof(b) / sizeof(char);
	print(b,lenB);
	mySort(b, lenB);
	print(b, lenB);

	return 0;
}

