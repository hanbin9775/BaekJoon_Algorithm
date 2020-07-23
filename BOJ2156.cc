#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int dp[3][10001];
int arr[10001];

int main(){
    int N;
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }
    dp[0][1] = 0;
    dp[1][1] = arr[1];
    dp[2][1] = arr[1];

    for(int i=2; i<=N; i++){
        dp[0][i] = max(dp[0][i-1],max(dp[1][i-1],dp[2][i-1]));
        dp[1][i] = dp[0][i-1]+arr[i];
        dp[2][i] = dp[1][i-1]+arr[i];
    }
    
    cout << max(dp[0][N],max(dp[1][N],dp[2][N]));
    return 0;
}
