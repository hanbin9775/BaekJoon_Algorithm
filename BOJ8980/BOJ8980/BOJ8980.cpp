// BOJ8980.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C;
int M;

vector <pair<pair<int, int>,pair<int,float>>> v;
int capv[2001];

bool compare(const pair<pair<int, int>, pair<int, float>> a, const pair<pair<int, int>, pair<int, float>> b) {
	
	return a.second.second > b.second.second;
}

int main()
{
	cin >> N >> C >> M;

	for (int i = 0; i < M; i++) {
		
		float a, b, c;
		cin >> a >> b >> c;
		v.push_back(make_pair(make_pair(a, b),make_pair(c,c/(b-a))));
	}

	//효율 순으로 정렬
	sort(v.begin(), v.end(),compare);

	int ans = 0;

	for (int i = 0; i < M; i++) {
		int check = true;
		int min = 10001;
		for (int j = v[i].first.first; j < v[i].first.second; j++) {
			//하나라도 이미 꽉 차 있으면
			if (capv[j] == C) {
				check = false;
				break;
			}
			if (capv[j] + v[i].second.first > C) {
				//안넘치게만 넣는다.
				if (min > C - capv[j]) {
					min = C - capv[j];
					v[i].second.first = min;
				}
			}
		}
		if (check) {
			int first = true;
			for (int j = v[i].first.first; j < v[i].first.second; j++) {

				capv[j] += v[i].second.first;
				if (first) {
					ans += v[i].second.first;
					first = false;
				}
			}
		}

	}

	cout << ans << "\n";

    return 0;
}

