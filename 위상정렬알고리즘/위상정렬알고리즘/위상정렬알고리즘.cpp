// 위상정렬알고리즘.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
// 사이클이 발생하지 않는 방향 그래프에서만 적용 가능

// 현재 그래프는 위상 정렬이 가능한지, 위상 정렬이 가능하다면 그 결과는 무엇인지
// 스택 or 큐를 이용한 방식이 있음.

//1. 진입차수가 0인 정점을 큐에 삽입
//2. 큐에서 원소를 꺼내 연결된 모든 간선을 제거
//3. 간선 제거 이후에 진입차수가 0이 된 정점을 큐에 삽입
//4. 큐가 빌때가지 2번 ~3번 과정을 반복. 모든 원소를 방문하기 전에 큐가 빈다면
//사이클이 존재하는 것이고, 모든 원소를 방문했다면 꺼낸 순서가 위상정렬의 결과
// 복잡도 O(V+E)  V는 정점의 갯수, E는 간선의 갯수 

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#define MAX 10

using namespace std;

int n, inDegree[MAX];
vector<int> a[MAX];

void topologySort() {
	int result[MAX];
	queue<int> q;

	// 진입 차수가 0인 노드를 큐에 삽입합니다.
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i);
	}

	for (int i = 1; i <= n; i++) {
		
		//다 돌기전에 빈다면 사이클이 발생
		if (q.empty()) {
			printf("사이클이 발생했습니다.");
			return;
		}

		int x = q.front();
		q.pop();
		result[i] = x;
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if (--inDegree[y] == 0) {
				q.push(y);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", result[i]);
	}

}

int main()
{
	n = 7;
	a[1].push_back(2);
	inDegree[2]++;
	a[1].push_back(5);
	inDegree[5]++;
	a[2].push_back(3);
	inDegree[3]++;
	a[1].push_back(4);
	inDegree[4]++;
	a[1].push_back(6);
	inDegree[6]++;
	a[2].push_back(6);
	inDegree[6]++;
	a[2].push_back(7);
	inDegree[7]++;
	topologySort();
    return 0;
}

