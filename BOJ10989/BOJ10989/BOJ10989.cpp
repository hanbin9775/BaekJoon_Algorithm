// BOJ10989.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>

//시간제한 3초, 각 숫자는 10,000보다 작거나 같은 자연수. nlogn 해도 2억이 넘는다. 각 숫자는 10,000보다 작다는 조건이 주어졌으므로 계수정렬로 풀자! 

int sort[10000];
int N;
int x;

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		
		scanf("%d", &x);
		sort[x - 1]++;
	}

	for (int i = 0; i < 10000; i++) {
		if (sort[i] != 0) {
			for (int j = 0; j < sort[i]; j++) {
				printf("%d\n", i + 1);
			}
		}
	}

    return 0;
}

