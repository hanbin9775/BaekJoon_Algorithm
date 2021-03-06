// BOJ2217그리디.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;
int maxn;

int main()
{
	scanf("%d", &n);
	int num;

	for (int i=0; i < n; i++) {
		scanf("%d", &num);
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		if (maxn < v[i] * (n - i)) {
			maxn = v[i] * (n - i);
		}
	}
	
	printf("%d", maxn);

    return 0;
}

