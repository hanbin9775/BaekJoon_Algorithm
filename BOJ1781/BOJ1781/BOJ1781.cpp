// BOJ1781.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;
vector <pair<int, int>> v;
int ans;
priority_queue<int> pq;


int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v.push_back(make_pair(a, b));
	}

	sort(v.begin(), v.end());

	int lastday = v.back().first;

	for(int i=0 ; i<lastday; i++){
		int d = lastday - i;
		while (!v.empty() && v.back().first == d) {
			pq.push(v.back().second);
			v.pop_back();
		}
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}

	printf("%d", ans);

    return 0;
}

