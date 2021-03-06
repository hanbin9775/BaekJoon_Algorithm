// BOJ2352그리디.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int n, m;

char dna[1000][50];

int T[50];
int A[50];
int G[50];
int C[50];

char HD[50];

int sum;

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> dna[i][j];
			switch (dna[i][j]) {
				case 'T':
					T[j] += 1;
					break;
				case 'A':
					A[j] += 1;
					break;
				case 'G':
					G[j] += 1;
					break;
				case 'C':
					C[j] += 1;
					break;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		int max = A[i];
		char maxchar = 'A';
		if (max < C[i]) {
			max = C[i];
			maxchar = 'C';
		}
		if (max < G[i]) {
			max = G[i];
			maxchar = 'G';
		}
		if (max < T[i]) {
			max = T[i];
			maxchar = 'T';
		}
		
		HD[i] = maxchar;
		
		cout << HD[i];

	}
	cout << "\n";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dna[i][j] != HD[j]) {
				sum += 1;
			}
		}
	}

	cout << sum;

    return 0;
}

