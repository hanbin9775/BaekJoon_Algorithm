// BOJ1449그리디.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, l;
vector <pair<int, bool>> arr;


int tape;


int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> l;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back(make_pair(num, false));
	}

	sort(arr.begin(), arr.end());

	int x = 0;
	

	while (arr[x].second == false) {
		int temp = 0;
		for (int i = x+1; i < n; i++) {
			if (arr[x].first + l - 1 >= arr[i].first) {
				arr[i].second = true;
				temp++;
			}
		}
		x += temp;
		tape += 1;
		if (x == n - 1) {
			break;
		}
		x += 1;
	}

	cout << tape;

	return 0;
}

