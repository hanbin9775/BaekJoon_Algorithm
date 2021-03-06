// BOJ11403.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int n;
vector<int> v[101];
queue<int> q;
int arr[101][101];

void clear(queue<int> &q) {
	queue<int>().swap(q);
}

void bfs(int start, int end) {
	q.push(start);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			if (v[x][i] != 0) {
				if (i == end) {
					clear(q);
					arr[start][end] = 1;
					return;
				}
				if(i!=start)
					q.push(i);
			}
		}
	}
	return;
}


int main()
{
	scanf_s("%d", &n);
	
	int a=0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%d", &a);
			v[i].push_back(a);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			bfs(i, j);
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

    return 0;
}

/* 플로이드-워샬 알고리즘
#include <iostream>
using namespace std;

int main() {
	bool map[100][100] = { 0, };
	int n;
	cin >> n;
	for (int h = 0; h < n; h++) {
		for (int w = 0; w < n; w++)
			cin >> map[h][w];
	}

	for (int k = 0; k < n; k++) {
		for (int h = 0; h < n; h++) {
			for (int w = 0; w < n; w++) {
				if (map[h][k] && map[k][w])
					map[h][w] = true;
			}
		}
	}

	for (int h = 0; h < n; h++) {
		for (int w = 0; w < n; w++) {
			cout << map[h][w] << " ";
		}
		cout << endl;
	}

	return 0;
}
*/