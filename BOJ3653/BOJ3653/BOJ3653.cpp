// BOJ3653.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

//세그먼트 트리로 푸는거..

#include "stdafx.h"
#include  <iostream>
using namespace std;

int tc;
int n,m,k;
int marr[100000];
int arr[100][100000];
int dvds[100][100000];

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> tc;
	
	for (int i = 0; i < tc; i++) {
		cin >> n >> m;
		marr[i] = m;
		for (int j = 0; j < n; j++) {
			dvds[i][j] = j;
		}
		for (int j = 0; j < m; j++) {
			cin >> k;
			arr[i][j] = k;
		}
	}

	for (int i = 0; i < tc; i++) {
		for (int j = 0; j < marr[i]; j++) {
			cout << dvds[i][arr[i][j] - 1] << " ";
			dvds[i][arr[i][j] - 1] = 0;
			for (int x = 0; x < arr[i][j] - 1; x++) {
				dvds[i][x] += 1;
			}
		}
		cout << "\n";
	}

    return 0;
}

