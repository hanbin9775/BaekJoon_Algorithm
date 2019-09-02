// BOJ2352.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int n; 
int maxn;

int arr[40001];


int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		int tempi = i;
		int maxtemp;
		while (tempi <= n) {
			if (tempi ==i){
				maxtemp = 1;
			}
			for (int j = tempi; j <= n; j++) {
				if (arr[tempi] < arr[j]) {
					tempi = j;
					maxtemp += 1;
				}
			}
			tempi += 1;
			while (tempi<=n) {
				if (arr[i]<arr[tempi]) {
					break;
				}
				tempi += 1;
			}
			if (maxn < maxtemp) {
				maxn = maxtemp;
			}
		}		
	}

	cout << maxn << "\n";

    return 0;
}

