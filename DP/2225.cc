#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <unordered_map>

#define mod 1000000000

using namespace std;

int dp[201][201];

int N, K;
int main(){

    cin >> N >> K;

    for(int i=0; i<=N; i++){
        dp[1][i] = 1;
    }
    for(int i=2; i<=K; i++){
        dp[i][0] = 1;
    }

    for(int i=2; i<=K; i++){
        for(int j=1; j<=N; j++){
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
        }
    }

    cout << dp[K][N];

    return 0;

}