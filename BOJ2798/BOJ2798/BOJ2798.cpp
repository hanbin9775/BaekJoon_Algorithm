// BOJ2798.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int n, m;
int arr[101];

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	int max=0;
	
	for (int i = 0; i < n-2; i++) {
		int temp=0;
		for (int j = i+1; j < n-1; j++) {
			for (int k = j+1; k < n; k++) {
				temp = arr[i] + arr[j] + arr[k];
				if (temp == m) {
					max = temp;
					break;
				}
				if (temp > max && temp < m) {
					max = temp;
				}
			}
		}
	}

	cout << max;

    return 0;
}

