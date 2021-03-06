// BOJ2012.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int n;

//vector로 예상 등수 입력받음
vector <int> predict;

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;

	for (int i = 0; i < n; i++) {
		//vector에 push할 data temp로 입력받음
		int temp;
		cin >> temp;
		predict.push_back(temp);
	}

	sort(predict.begin(), predict.end());

	// worst case를 대비한 자료형 설정
	long long result = 0;

	for (int i = 1; i <= n; i++) {
		result += abs(i - predict[i - 1]);
	}

	cout << result;

    return 0;
}

