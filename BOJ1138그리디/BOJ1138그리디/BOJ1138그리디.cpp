// BOJ1138그리디.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int n;
int arr[11];
int ans[11];

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		int k = 0;
		for (int j = 0; j <= arr[i] + k; j++) {
			if (ans[j] != 0) {
				k += 1;
			}
		}

		ans[arr[i]+k] = i+1;
	}
	
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}

    return 0;
}

