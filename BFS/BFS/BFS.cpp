// BFS.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 너비를 우선으로 탐색. 가까운걸 먼저 탐색. 맹목적인 탐색. 최단 경로를 찾아줌. 최단 길이 보장

int number = 7;
int c[7];
vector<int> a[8]; // 별 의미는 없음. 그냥 보기 편하게

void bfs(int start) {
	queue<int> q;
	q.push(start);
	c[start] = true; // 순회한 노드는 true로 기록
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		printf("%d ", x);
		for (int i = 0; i < a[x].size(); i++) { // a[x]와 연결되어 있는 노드 모두 순회
			int y = a[x][i];
			if (!c[y]) { // 아직 순회하지 않은 노드라면 
				q.push(y); // 큐에 push 해 후에 순회하도록한다
				c[y] = true; // 그리고 이 노드는 순회했으므로 true로 기록
			}
		}
	}
}

int main()
{
	//1과 2를 연결
	a[1].push_back(2);
	a[2].push_back(1);
	
	//1과 3을 연결
	a[1].push_back(3);
	a[3].push_back(1);

	//2과 3을 연결
	a[2].push_back(3);
	a[3].push_back(2);

	//2과 4을 연결
	a[2].push_back(4);
	a[4].push_back(2);

	//2과 5을 연결
	a[2].push_back(5);
	a[5].push_back(2);

	//3과 6을 연결
	a[3].push_back(6);
	a[6].push_back(3);

	//3과 7을 연결
	a[3].push_back(7);
	a[7].push_back(3);


	bfs(1);

    return 0;
}

