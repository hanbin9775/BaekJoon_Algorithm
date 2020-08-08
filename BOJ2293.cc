#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <set>

using namespace std;


int n, m;
int dp[10001];

int main () {
    
    cin >> n >> m;
    
    vector<int> v;
    v.resize(n+1);
    
    for(int i=1; i<=n; i++){
        cin >> v[i];
    }
    
    dp[0] =1;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(j>= v[i]){
                dp[j] += dp[j-v[i]];
            }
        }
    }
    
    cout << dp[m];
    
    return 0;
}