// BOJ5567.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 500

int n, m;

vector<pair<int, int>> a[501];
int d[501];
int x, y;

void dijkstra(int start) {

	d[start] = 0;
	priority_queue<pair<int,int>> pq;
	pq.push(make_pair(start,0));

	while (!pq.empty()) {
		int current = pq.top().first;
		int distance = -pq.top().second;
		pq.pop();
		if (d[current] <distance) continue;
		for (int i = 0; i < a[current].size(); i++) {
			int next = a[current][i].first;
			int nextDistance = distance + a[current][i].second;
			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}
		}
	}	
}

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		d[i] = INF;
	}

	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		a[x].push_back(make_pair(y, 1));
		a[y].push_back(make_pair(x, 1));
	}

	dijkstra(1);

	int ans = 0;

	for (int i = 2; i <= n; i++) {
		if (d[i] < 3 ) {
			ans += 1;
		}
	}

	cout << ans;

    return 0;
}

