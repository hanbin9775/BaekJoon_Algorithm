#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    priority_queue<long long> pq;

    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        pq.push(-input);
    }

    while (m-- > 0)
    {
        long long first = pq.top();
        pq.pop();
        long long second = pq.top();
        pq.pop();

        pq.push(first + second);
        pq.push(first + second);
    }
    long long answer = 0;
    while (!pq.empty())
    {
        answer += -pq.top();
        pq.pop();
    }
    cout << answer;
    return 0;
}
