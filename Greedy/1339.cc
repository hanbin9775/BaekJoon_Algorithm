#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<string> str_v;
    str_v.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> str_v[i];
    }

    map<char, int> m;
    map<char, int>::iterator it;

    for (int i = 0; i < str_v.size(); i++)
    {
        for (int j = 0; j < str_v[i].size(); j++)
        {
            char letter = str_v[i][j];
            it = m.find(letter);
            int priority = pow(10, str_v[i].size() - j - 1);

            //없으면
            if (it == m.end())
            {
                m.insert(make_pair(letter, priority));
            }
            else
            { // 있으면
                it->second += priority;
            }
        }
    }

    priority_queue<pair<int, char>> pq;

    for (it = m.begin(); it != m.end(); it++)
    {
        pq.push(make_pair(it->second, it->first));
    }

    vector<char> char_v;
    while (!pq.empty())
    {
        char_v.push_back(pq.top().second);
        pq.pop();
    }

    vector<int> int_v;
    for (int i = 0; i < str_v.size(); i++)
    {
        int num = 0;
        for (int j = 0; j < str_v[i].size(); j++)
        {
            char letter = str_v[i][j];
            int letter_value = 0;
            for (int k = 0; k < char_v.size(); k++)
            {
                if (letter == char_v[k])
                {
                    letter_value = 9 - k;
                    break;
                }
            }
            num += letter_value * pow(10, str_v[i].size() - j - 1);
        }
        int_v.push_back(num);
    }
    int answer = 0;
    for (int i = 0; i < int_v.size(); i++)
    {
        answer += int_v[i];
    }
    cout << answer;
    return 0;
}
