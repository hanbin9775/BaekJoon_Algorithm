// 다익스트라알고리즘.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//
// 대표적인 최단 경로 탐색 알고리즘. 다이나믹 프로그래밍으로 분류되기도 함.
// 현재까지 알고 있던 최단 경로를 계속해서 갱신

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number = 6;
int INF = 1000000000;



int a[6][6] = {
	{0,2, 5,1,INF,INF},
	{ 2,0,3,2,INF,INF },
	{ 5,3,0,3,1,5 },
	{ 1,2,3,0,1,INF },
	{ INF,INF,1,1,0,2 },
	{ INF,INF,5,INF,2,0 }
};

//선형 구현 복잡도 O(N^2)
bool v[6]; // 방문한 노드
int d[6]; // 최단 거리

//heap으로 구현 복잡도 O(NlogN). 
vector <pair<int, int>> ah[7];
int dh[7];

void dijkstraheap(int start) {
	dh[start] = 0; //자기 자신 0
	priority_queue<pair<int, int>> pq; // 힙 구조, 우선 순위 큐와 힙은 같은 방식으로 작동. 배열과 인접리스트로도 구현 가능하지만, 배열의 경우 삽입 및 삭제 과정에서 데이터를 한 칸 씩 당기거나 밀어야함. 또 삽입의 위치를 찾기 위해 배열에 저장된 모든 데이터와 우선 순위를 비교해야 함. 인접리스트의 경우 삽입의 위치릴 찾기 위해 첫번째 노드에서부터 시작해 마지막 노드에 저장된 데이터와 우선순위를 비교를 진행할지도 모른다.
	pq.push(make_pair(start, 0));
	//가까운 순서대로 처리하므로 큐를 사용
	while (!pq.empty()) {
		int current = pq.top().first;
		// 짧은 것이 먼저 오도록 음수화(-), priority_queue는 큰 값을 기준으로 최상단 노드를 만들기 때문. 최대 heap
		int distance = -pq.top().second;
		pq.pop();
		//최단 거리가 아닌 경우 스킵
		if (dh[current] < distance) continue;
		for (int i = 0; i < ah[current].size(); i++) {
			//선택된 노드의 인접 노드
			int next = ah[current][i].first;
			//선택된 노드 거쳐서 인접 노드로 가는 비용
			int nextDistance = distance + ah[current][i].second;
			//기존의 최소 비용보다 더 저렴하다면 교체합니다
			if (nextDistance < dh[next]) {
				dh[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}
		}
	}

}

// 가장 쉽게 다익스트라 알고리즘 구현, 선형탐색
int getSamllIndex() {
	int min = INF;
	int index = 0;
	for (int i = 0; i < number; i++) {
		if (d[i] < min && !v[i]) {
			min = d[i];
			index = i;
		}
	}
	return index;
}

// 다익스트라를 수행하는 함수이다.
void dijkstra(int start) {
	for (int i = 0; i < number; i++) {
		d[i] = a[start][i];
	}
	v[start] = true;
	for (int i = 0; i < number - 2; i++) { // 처음에 2개(시작과 가장 짧은 간선을 가지고 있는 정점)를 빼줌
		int current = getSamllIndex();
		v[current] = true;
		for (int j = 0; j < 6; j++) {
			if (!v[j]) {
				if (d[current] + a[current][j] < d[j]) {
					d[j] = d[current] + a[current][j];
				}
			}
		}
	}
}

int main()
{
	dijkstra(0);
	for (int i = 0; i < number; i++) {
		printf("%d ", d[i]);
	}

	//힙 다익스트라
	for (int i = 1; i <= number; i++) {
		dh[i] = INF;
	}

	ah[1].push_back(make_pair(2, 2));
	ah[1].push_back(make_pair(3, 5));
	ah[1].push_back(make_pair(4, 1));

	ah[2].push_back(make_pair(1, 2));
	ah[2].push_back(make_pair(3, 3));
	ah[2].push_back(make_pair(4, 2));

	ah[3].push_back(make_pair(1, 5));
	ah[3].push_back(make_pair(2, 3));
	ah[3].push_back(make_pair(4, 3));
	ah[3].push_back(make_pair(5, 1));
	ah[3].push_back(make_pair(6, 5));

	ah[4].push_back(make_pair(1, 1));
	ah[4].push_back(make_pair(2, 2));
	ah[4].push_back(make_pair(3, 3));
	ah[4].push_back(make_pair(5, 1));

	ah[5].push_back(make_pair(3, 1));
	ah[5].push_back(make_pair(4, 1));
	ah[5].push_back(make_pair(6, 2));

	ah[6].push_back(make_pair(3, 5));
	ah[6].push_back(make_pair(5, 2));

	dijkstraheap(1);

	for (int i = 1; i <= number; i++) {
		printf("%d ", dh[i]);
	}

    return 0;
}

