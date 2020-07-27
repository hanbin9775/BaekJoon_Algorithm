#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int N;
int dp[1001][1001];

bool comp(pair<int, int> a, pair<int,int> b){
    return (float)(a.first)/(float)(a.second) > (float)(b.first)/(float)(b.second);
}

int main () {
    cin >> N;
    vector<pair<int,int>> v;
    int input;
    for(int i=0; i<N; i++){
        cin >> input;
        v.push_back(make_pair(input,i+1));
    }
    
    sort(v.begin(), v.end(), comp);
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            
            if(v[i-1].second <= j){
                dp[i][j] = max(dp[i-1][j],
                               max(dp[i-1][j-v[i-1].second]+v[i-1].first,
                                   dp[i][j-v[i-1].second]+v[i-1].first));
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[N][N];
    return 0;
}
