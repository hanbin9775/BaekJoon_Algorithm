// BOJ9576.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;

int checkbook[1001];

bool compare(const pair<pair<int, int>, int> a, const pair<pair<int, int>, int> b) {
	return a.first.second < b.first.second;
}

int main()
{
	cin >> T;

	for (int i = 0; i < T; i++) {

		for (int i = 0; i < 1001; i++) {
			checkbook[i] = 0;
		}

		vector <pair<pair<int, int>,int>> v;

		int N, M;
		cin >> N >> M;

		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			v.push_back(make_pair(make_pair(a, b),b-a));
		}

		sort(v.begin(), v.end(),compare);
		
		int ans = 0;
		for (int i = 0; i < M; i++) {
			for (int j = v[i].first.first-1; j <= v[i].first.second-1; j++) {
				if (checkbook[j]==0) {
					checkbook[j] = 1;
					ans += 1;
					break;
				}
			}
		}
		cout << ans << "\n";
		
	}

    return 0;
}

