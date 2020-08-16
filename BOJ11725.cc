#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <set>

using namespace std;


bool visited[100001];

int main () {
    int n;
    cin >> n;
    vector<vector<int>> tree;
    tree.resize(n+1);
    
    for(int i=0; i<n-1; i++){
        int node1, node2;
        cin >> node1 >> node2;
        tree[node1].push_back(node2);
        tree[node2].push_back(node1);
    }
    
    //bfs
    vector<int> parent_record;
    parent_record.resize(n+1);
    
    queue<int> q;
    q.push(1);
    visited[1] = true;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int i=0; i<tree[cur].size(); i++){
            int next = tree[cur][i];
            
            if(!visited[next]){
                visited[next] = true;
                q.push(next);
                parent_record[next] = cur;
            }
        }
    }
    
    for(int i=2; i<=n; i++){
        cout << parent_record[i] << "\n";
    }
    
    return 0;
}


