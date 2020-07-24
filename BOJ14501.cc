#include <vector>
#include <iostream>

using namespace std;

int N;
vector<pair<int,int>> info;

int dp[16][16];

int main () {
    cin >> N;
    int a, b;
    for(int i=0; i<N; i++){
        cin >> a>> b;
        info.push_back(make_pair(a,b));
    }
    int cache =0;
    //i번째 날의 일까지, j번째 날까지
    for(int i=1; i<=N; i++){
        bool first = true;
        for(int j=i; j<=N; j++){
            if(i+info[i-1].first-1 > j) dp[i][j] = dp[i-1][j];
            else{
                if(first) {
                    cache = dp[i-1][j-info[i-1].first];
                    first = false;
                }
                dp[i][j] = max(dp[i-1][j], info[i-1].second + cache);
            }
        }
    }
    cout << dp[N][N];
    return 0;
}
