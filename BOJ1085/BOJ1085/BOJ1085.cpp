// BOJ1085.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

int x, y, w, h;

int main()
{
	cin >> x >> y >> w >> h;

	cout << min(x, min(y, min(w - x, h - y)));


    return 0;
}

