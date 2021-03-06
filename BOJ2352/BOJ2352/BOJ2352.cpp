// BOJ2352.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[40000];

int main()
{
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
		if (idx == v.size()) v.push_back(arr[i]);
		else v[idx] = arr[i];
	}

	cout << v.size();

    return 0;
}

