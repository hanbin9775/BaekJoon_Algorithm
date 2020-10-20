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

    vector<int> v;
    v.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int idx = n - 2;
    int prev_lev_score = v[n - 1];
    int ans = 0;

    while (idx >= 0)
    {
        int cur_lev_score = v[idx];
        if (prev_lev_score <= cur_lev_score)
        {
            ans += cur_lev_score - (prev_lev_score - 1);
            v[idx] = prev_lev_score - 1;
        }
        prev_lev_score = v[idx];
        idx--;
    }
    cout << ans;

    return 0;
}
