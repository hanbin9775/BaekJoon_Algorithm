#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int dp[3][100001];
int arr[3][100001];

int main () {
   
    int T;
    cin >>T;
    while(T-->0){
        int n;
        cin >> n;
        for(int i=1; i<=n; i++) cin >>arr[1][i];
        for(int i=1; i<=n; i++) cin >>arr[2][i];

        dp[0][1] = 0;
        dp[1][1] = arr[1][1];
        dp[2][1] = arr[2][1];
        
        for(int i=2; i<=n; i++){
            dp[0][i] = max(dp[0][i-1],max(dp[1][i-1],dp[2][i-1]));
            dp[1][i] = max(dp[0][i-1],dp[2][i-1])+arr[1][i];
            dp[2][i] = max(dp[0][i-1],dp[1][i-1])+arr[2][i];
        }
        
        cout << max(dp[1][n],dp[2][n]) <<"\n";
        
    }
    
    return 0;
}

