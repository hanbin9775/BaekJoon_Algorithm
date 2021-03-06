// 기초정렬알고리즘문제.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void quickSort(int *arr, int start, int end) {
	if (start >= end)
		return;

	int key = start, i = start + 1, j = end, temp;

	while (i <= j) {
		while (arr[i] <= arr[key]) {
			i++;
		}
		while (arr[j] >= arr[key] && j > start ) {
			j--;
		}
		if (i > j) { // 교차 되면
			temp = arr[j];
			arr[j] = arr[key];
			arr[key] = temp;
		}
		else {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	quickSort(arr, start, j - 1);
	quickSort(arr, j + 1, end);
}

int main()
{

	int arr[3];

	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}
	
	quickSort(arr, 0, 2);

	for (int i = 0; i < 3; i++) {
		cout << arr[i] << endl;
	}

    return 0;
}

