#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <set>

using namespace std;

bool visited[1001];

int main(){
    
    int t;
    cin >> t;
    
    while(t-->0){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> btree;
        btree.resize(n+1);
        for(int i=0; i<m; i++){
            int a, b;
            cin >> a >> b;
            btree[a].push_back(b);
            btree[b].push_back(a);
        }
        
        queue<int> q;
        q.push(1);
        visited[1] = true;
        int v_cnt =0;
        
        while(!q.empty()){
            
            int cur = q.front();
            q.pop();
            
            for(int i=0; i<btree[cur].size(); i++){
                int next = btree[cur][i];
                
                if(!visited[next]){
                    visited[next] = true;
                    q.push(next);
                    v_cnt++;
                }
            }
            
        }
        cout << v_cnt << "\n";
        for(int i=1; i<=n; i++){
            visited[i] = false;
        }
    }
    
    
    
    return 0;
    
}



