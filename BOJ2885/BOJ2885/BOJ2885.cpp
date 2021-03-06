// BOJ2885.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int K;

//k 보다 작거나 같은 수 중에 가장 큰 2의 제곱수를 구한다.
int findClosest(int num) {
	int cnt = 1;
	while (cnt <= num) {
		cnt *= 2;
	}
	return cnt / 2;
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> K;

	if (K == findClosest(K)) {
		cout << K << " " << 0;
		return 0;
	}

	int min = 2 * findClosest(K);

	while (findClosest(K) != K) {
		K = K - findClosest(K);
	}
	int cnt = 0;
	while (K != min) {
		K *= 2;
		cnt += 1;
	}
	cout << min << " " << cnt;

    return 0;
}


