// 병합정렬.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>

int num = 8;
int sorted[8]; // 항상 전역변수로 선언해주어야함. 기존의 배열 뿐만 아니라 추가적인 배열이 필요. 필요할 때마다 배열을 새로 생성한다면 비효율적


//병합 정렬. 항상 반으로 나누기 때문에 최악의 경우에도 O(nlogn)의 시간 복잡도를 갖는다. 평균적으로 quicksort 보다 빠른 속도를 갖진 않는다.
void merge(int a[], int m, int middle, int n) {
	int i = m;
	int j = middle + 1;
	int k = m;

	while (i <= middle && j <= n) { // i는 m까지, j는 n까지 
		if (a[i] <= a[j]) { 
			sorted[k] = a[i];
			i++;
		}
		else {
			sorted[k] = a[j];
			j++;
		}
		k++;
	}
	// 남은 데이터도 삽입
	if (i > middle) { // j가 끝까지 못갔으면 남은 j를 넣어줌
		for (int t = j; t <= n; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	else {
		for (int t = i; t <= middle; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	//정렬된 배열 삽입
	for (int t = m; t <= n; t++) {
		a[t] = sorted[t];
	}
}

void mergeSort(int a[], int m, int n) {
	if (m < n) {
		int middle = (m + n) / 2;
		mergeSort(a, m, middle);
		mergeSort(a, middle+1, n);
		merge(a, m, middle, n);
	}
}


int main()
{
	int arr[8] = { 7,6,5,8,3,5,9,1 };
	mergeSort(arr, 0, num - 1);
	for (int i = 0; i < num; i++) {
		printf("%d ", arr[i]);
	}

    return 0;
}

