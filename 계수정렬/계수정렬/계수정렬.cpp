// 계수정렬.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>

int main()
{
	int temp;
	int count[5]; // 세주는 배열
	int arr[30] = { 1,3,2,4,3,2,5,3,1,2,3,4,4,3,5,1,2,3,5,2,3,1,4,3,5,1,2,1,1,1 };
	
	for (int i = 0; i < 5; i++) {
		count[i] = 0;
	}

	//시간 복잡도 O(N)
	for (int i = 0; i < 30; i++) {
		count[arr[i]-1]++;
	}
	for (int i = 0; i < 5; i++) {
		if (count[i] != 0) {
			for (int j = 0; j < count[i]; j++) {
				printf("%d", i + 1);
			}
		}
	}

    return 0;
}

