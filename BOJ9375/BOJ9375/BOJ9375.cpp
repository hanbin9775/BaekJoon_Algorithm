// BOJ9375.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n; // testcase
int k; // 의상의 수

vector<pair<string, string>> v[100];
int arr[30];

int cntsame(int index) {
	
	if (v[index].size() == 0) {
		return 0;
	}
	
	int cnt = 0;
	int indexcnt = 0;
	
	string temp = v[index][0].first;
	for (int i = 0; i < v[index].size(); i++) {
		if (v[index][i].first == temp) {
			cnt++;
		}
		else {
			temp = v[index][i].first;
			arr[indexcnt++] = cnt;
			cnt = 1;
		}

		if (i == v[index].size() - 1) {
			arr[indexcnt++] = cnt;
		}
	}
	int result = 1;
	for (int i = 0; i < indexcnt; i++) {
		result *= arr[i] + 1;
	}
	return result - 1;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> n;
	
	string temp1;
	string temp2;


	for (int i = 0; i < n; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> temp1 >> temp2;
			v[i].push_back(make_pair(temp2, temp1));
		}
	}

	for (int i = 0; i < n; i++) {
		sort(v[i].begin(), v[i].end());
	}

	for (int i = 0; i < n; i++) {
		cout << cntsame(i) <<"\n";
	}

    return 0;
}

