// 백준2751.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001];
int N;

int main()
{	
	ios::sync_with_stdio(false);
	
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; i++) {
		cout << arr[i] << "\n";
	}
}

