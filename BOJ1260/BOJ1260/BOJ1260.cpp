// BOJ1260.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N, M, start;
int c, d;
int bgraph[1001];
int dgraph[1001];
vector<int> a[1001]; 

void dfs(int x) {
	if (dgraph[x]) return;
	dgraph[x] = true;
	printf("%d ", x);
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		dfs(y);
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	bgraph[start] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		printf("%d ", x);
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if (!bgraph[y]) {
				q.push(y);
				bgraph[y] = true;
			}
		}
	}
}

int main()
{
	//scanf_s("%d &d %d", &N, &M,&start);
	cin >> N >> M >> start;

	for (int i = 0; i < M; i++) {
		cin >> c >> d;
		a[c].push_back(d);
		a[d].push_back(c);
	}

	for (int i = 0; i < N; i++) {
		sort(a[i + 1].begin(),a[i+1].end());
	}

	dfs(start);
	printf("\n");
	bfs(start);



    return 0;
}

