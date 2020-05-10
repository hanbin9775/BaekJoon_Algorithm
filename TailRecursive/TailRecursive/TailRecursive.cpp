// TailRecursive.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

long long foo(int n, long long result) {
	if (n == 0) {
		return result;
	}
	return foo(n - 1,result*2);
}

long long foo2(int n) {
	if (n == 0) {
		return 1;
	}
	return foo2(n - 1) * 2;
}

int main()
{
	int n;
	cin >> n;
	cout << foo(n,1)<<"\n";
	cout << foo2(n);
    return 0;
}

