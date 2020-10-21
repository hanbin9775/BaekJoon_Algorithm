#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <queue>

using namespace std;

int main()
{
    string str;

    getline(cin, str);

    char arr[4] = {'U', 'C', 'P', 'C'};
    int idx = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == arr[idx])
        {
            idx++;
        }
        if (idx == 4)
            break;
    }

    if (idx == 4)
        cout << "I love UCPC"
             << "\n";
    else
        cout << "I hate UCPC"
             << "\n";

    return 0;
}
