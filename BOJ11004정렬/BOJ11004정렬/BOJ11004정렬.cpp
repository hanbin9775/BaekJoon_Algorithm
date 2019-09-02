// BOJ11004정렬.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int k;

int arr[5000001];

int main()
{
	scanf_s("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}

	sort(arr, arr + n);

	printf("%d", arr[k-1]);

    return 0;
}

