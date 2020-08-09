#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <set>

using namespace std;

bool visited[101];

int main () {
    
    int n, m;
    
    cin >> n >> m;
    
    vector<vector<int>> v;
    
    v.resize(n+1);
    
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    //bfs
    queue<int> q;
    q.push(1);
    visited[1] = true;
    int answer =0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int i=0; i<v[cur].size(); i++){
            int next = v[cur][i];
            if(!visited[next]){
                visited[next] = true;
                q.push(next);
                answer++;
            }
            
        }
    }
    
    cout << answer;
    return 0;
}

