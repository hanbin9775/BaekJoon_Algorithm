#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <set>

using namespace std;

bool visited[1001];
vector<vector<int>> v;

void dfs(int start){
    
    stack<int> stk;
    stk.push(start);
    
    while(!stk.empty()){
        int cur = stk.top();
        stk.pop();
        
        for(int i=0; i<v[cur].size(); i++){
            int next = v[cur][i];
            if(!visited[next]){
                visited[next] = true;
                stk.push(next);
            }
        }
    }
    
}

int main () {
    int n, m;
    cin >> n >> m;
     
    v.resize(n+1);
    
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int cnt=0;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            cnt++;
            dfs(i);
        }
    }
    cout << cnt;
    return 0;
}

