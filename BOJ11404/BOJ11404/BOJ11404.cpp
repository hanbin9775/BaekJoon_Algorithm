// BOJ11404.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 10000000

int n;
int m;
int arr[101][101];


void floyd_warshall() {
	//i를 거쳐서
	for (int i = 0; i < n; i++) {
		//j에서
		for (int j = 0; j < n; j++) {
			//k로
			for (int k = 0; k < n; k++) {
				//j->k로 i를 거쳐 갈 수 있는지
				if ((arr[j][i] != INF) && (arr[i][k] != INF)) {
					arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
				}
			}
		}
	}
}

int main()
{
	int from, to, weight;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> from >> to >> weight;
		//만약 같은 노선이 입력되었으면 최소비용으로 초기화
		if (arr[from - 1][to - 1] != INF) {
			arr[from - 1][to - 1] = min(arr[from - 1][to - 1], weight);
		}
		else {
			arr[from - 1][to - 1] = weight;
		}
	}
		
	floydwarshall();

	int value;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			value = arr[i][j];
			if (value == INF || i==j) {
				cout << 0 << " ";
			}
			else {
				cout << value << " ";
			}
			
		}
		cout << "\n";
	}

    return 0;
}

