// 세숫자정렬.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int arr[3];
int temp, index;

int main()
{
	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 3; i++) {
		temp = arr[i];
		index = i;
		for (int j = i; j < 3; j++) {
			if (temp > arr[j]) {
				index = j;
				temp = arr[j];
			}
		}
		arr[index] = arr[i];
		arr[i] = temp;	
	}

	for (int i = 0; i < 3; i++) {
		cout << arr[i] << " ";
	}

    return 0;
}

