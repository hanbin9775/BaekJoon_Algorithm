// BOJ1700.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int min_pull = 10000;
int inputs[100];

void getMinPull(int cur_pull_num, vector<int> v, int cur_idx) {
	vector<int>::iterator it;
	int temp;
	for (int i = cur_idx; i < K; i++) {
		it = find(v.begin(), v.end(), inputs[i]);
		//코드 자리 남고 없을 때 새로 꼽음
		if (it == v.end() && v.size()<N) {
			v.push_back(inputs[i]);
		}
		//코드 자리 없고 안 꼽혀 있음
		else if (it == v.end() && v.size() == N) {
			//하나씩 다 빼보고 꼽아봄
			for (int j = 0; j < N; j++) {
				temp = v[j];
				v[j] = inputs[i];
				getMinPull(cur_pull_num + 1, v, i+1);
				v[j] = temp;
			}
			return;
		}
		//이미 꼽혀 있음
		else if (it != v.end()) {
			continue;
		}
	}
	min_pull = min(min_pull, cur_pull_num);
	return;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	vector<int> v;

	for (int i = 0; i < K; i++) {
		cin >> inputs[i];
	}
	getMinPull(0, v, 0);
	
	cout << min_pull;

	return 0;
}

