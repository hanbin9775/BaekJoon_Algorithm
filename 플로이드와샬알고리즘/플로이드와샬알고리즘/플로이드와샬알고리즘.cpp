// 플로이드와샬알고리즘.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
// 모든 정점에서 모든 정점으로의 최단 경로. 다익스트라는 한 정점에서 출발했을 때 다른 모든 정점으로 최단 경로를 구함.
//x에서 y로 가는 최소 비용 vs x에서 노드 1로 가는 비용 + 노드 1에서 y로 가는 비용

#include "stdafx.h"
#include <stdio.h>


int num = 4;
int INF = 100000000;

int a[4][4] = {
	{0,5,INF,8},
	{7,0,9,INF},
	{2,INF,0,4},
	{INF,INF,3,0}
};

void floydWarshall() {
	int d[4][4];

	//결과 그래츠 초기화
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			d[i][j] = a[i][j];
		}
	}

	//k = 거쳐가는 노드
	for (int k = 0; k < num; k++) {
		//i = 출발 노드
		for (int i = 0; i < num; i++) {
			//j= 도착 노드
			for (int j = 0; j < num; j++) {
				if (d[i][k] + d[k][j] < d[i][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	//결과를 출력합니다
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}

}

int main()
{
	floydWarshall();
    return 0;
}

