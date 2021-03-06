// ConsoleApplication4.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//퀵정렬 - 내림차순
void  quickSort(int *data, int start, int end) {
	if (start >= end) {
	 	return;
	}

	int key = start;
	int i = start + 1;
	int j = end;
	int temp;

	while (i <= j) {
		while (data[i] >= data[key] && i<=end) {
			i++;
		}
		
		while (data[j] <= data[key] && j >start) {
			j--;
		}
		
		if (i > j) {
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else {
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
		//i++, j--;
	}

	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end);
}

int main()
{
	int i, j, temp, min;
	int arr[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

	// 선택 정렬
	int index =0;

	for (int i = 0; i < 10; i++) {
		temp = arr[i];
		for (int j = i; j < 10; j++) {
			if (temp > arr[j]) {
				temp = arr[j];
				index = j;
			}
		}
		arr[index] = arr[i];
		arr[i] = temp;
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i]<<" ";
	}
	cout << endl;


	//버블 정렬 - 자리를 바꾸는 연산을 계속하기 때문에 선택보다 더 비효율적, 선택 정렬은 바꾸고자 하는 곳의 인덱스를 저장해서 한번만 교체 연산
	int arr2[10] = { 1,10, 5, 8, 7, 6, 4, 3, 2, 9 };
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9-i; j++) {
			if (arr2[j] > arr2[j+1]) {
				temp = arr2[j];
				arr2[j] = arr2[j + 1];
				arr2[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		cout << arr2[i] << " ";
	}
	cout << endl;

	// 삽입 정렬
	int arr1[10] = {1,10, 5, 8, 7, 6, 4, 3, 2, 9 };
	for (i = 0; i < 9; i++) {
		j = i;
		while (arr1[j] > arr1[j + 1]) {
			temp = arr1[j];
			arr1[j] = arr1[j + 1];
			arr1[j + 1] = temp;
			j--;
		}
	}
	for (int i = 0; i < 10; i++) {
		cout << arr1[i] << " ";
	}
	cout << endl;



	//퀵 정렬
	int arr3[10] = { 10,7, 8, 1, 5, 9, 6, 3, 2, 4 };
	quickSort(arr3, 0, 9);
	for (int i = 0; i < 10; i++) {
		cout << arr3[i] << " ";
	}
	cout << endl;
    return 0;
}

