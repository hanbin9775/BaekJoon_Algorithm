#include <iostream>


using namespace std;

int dp[2][301];
int arr[301];

int main(){
    int N;
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }
    dp[0][1] = arr[1];
    dp[1][1] = arr[1];
    dp[0][2] = dp[0][1]+arr[2];
    dp[1][2] = arr[2];
    
    for(int i=3; i<=N; i++){
        dp[0][i] = dp[1][i-1] + arr[i];
        dp[1][i] = max(dp[0][i-2], dp[1][i-2]) + arr[i];
    }
    cout << max(dp[0][N],dp[1][N]);
    return 0;
}
