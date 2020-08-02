#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int dp[101][10];

int main () {
   
    int n;
    cin >> n;
    
    dp[1][0]= 0;
    for(int i=1; i<=9; i++){
        dp[1][i] = 1;
    }
    
    for(int i=2; i<=n; i++){
        dp[i][0] = dp[i-1][1];
        dp[i][9] = dp[i-1][8];
        for(int j=1; j<=8; j++){
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%1000000000;
        }
    }
    int answer =0;
    for(int i=0; i<=9; i++){
        answer = (answer+dp[n][i])%1000000000;
    }
    cout << answer;
    return 0;
}
