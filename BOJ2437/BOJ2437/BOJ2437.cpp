// BOJ2437.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1000];


int main()
{
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr,arr+N);

	int currentSum = 0;
	
	int arrcnt = 0;
	int nextWeight = arr[arrcnt];


	for (int i = 0; i < N; i++) {
		if (currentSum + 1 >= nextWeight) {
			currentSum += nextWeight;
			nextWeight = arr[++arrcnt];
		}
		else {
			break;
		}
	}

	cout << currentSum + 1 << "\n";

    return 0;
}

