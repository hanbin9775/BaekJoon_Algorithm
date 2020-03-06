// BOJ1700.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int arr[100];
vector <int> multitab;

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;

	int ans = 0;

	for (int i = 0; i < K; i++) {
		cin >> arr[i];
	}

	int c = 0;

	while (c<K) {
		//아직 멀티텝에 빈자리가 있으면 멀티텝에 꽂는다.
		if (multitab.size() < N) {
			multitab.push_back(arr[c]);
			c++;
			continue;
		}
		
		//빈자리가 없으면,

		//멀티탭에 꽂을 가전제품이 이미 꽂혀있을 때
		if (find(multitab.begin(), multitab.end(), arr[c]) != multitab.end()) {
			//넘어감
			c++;
			continue;
		}
		//멀티탭에 꽂을 가전제품이 안 꽂혀있을 떄
		else{
			//멀티탭에 앞으로 꽂을 가전제품 덱을 보며 있는지 확인

			for (int i = 0; i < N; i++) {
				//없다면 그거 빼고 새거 꽂음
				
				
				if (find(arr + c, arr + K, multitab[i]) == arr + K) {
					multitab[i] = arr[c];
					c++;
					ans += 1;
					break;
				}
				if (multitab[i] != arr[c + 1]) {
					multitab[i] = arr[c];
					c++;
					ans += 1;
					break;
				}
			
			}
		}
	}

	cout << ans << "\n";

    return 0;
}

