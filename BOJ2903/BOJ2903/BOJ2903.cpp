// BOJ2903.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int n;

int main()
{
	//ios_base::sync_with_stdio(false);
	cin >> n;

	int temp = 3;

	for (int i = 1; i < n; i++) {
		
		temp = 2 * temp - 1;
	}

	cout << temp*temp;

    return 0;
}

