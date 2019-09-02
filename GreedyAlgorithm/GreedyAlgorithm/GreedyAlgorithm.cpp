// GreedyAlgorithm.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;
int sum;

int main()
{
	scanf("%d", &n);

	int num;

	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		v.push_back(num);
	}
	
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			sum += v[j];
		}
	}

	printf("%d", sum);

    return 0;
}

