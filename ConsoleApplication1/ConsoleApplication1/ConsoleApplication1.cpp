// ConsoleApplication1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int arr[6] = { 3,1,2,3,1,2 };

	int C;
	cout << "test case : ";
	cin >> C;

	int *narr = new int[C];
	int *larr = new int[C];

	for (int i = 0; i < C; i++) {
		
		for (int j = 0; j < narr[j]; j++) {
			cout << C << "번째 case의 대여할 수 있는 날들의 수 : ";
			cin >> narr[j];
		}
		
		cout << C << "번째 case의 이미 섭외한 공연 팀의 수 : ";
		cin >> larr[i];

	}

    return 0;
}

