#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

#define INF 50010

int n, m;

vector<vector<int>> graph_v;
int dist[20001];
typedef pair<int,int> P;

void dijkstra(int start){
    
    priority_queue<P> pq;
    
    for(int i=0; i<graph_v[start].size(); i++){
        pq.push(make_pair(-1*dist[graph_v[start][i]], graph_v[start][i]));
    }
    
    while(!pq.empty()){
        int cur = pq.top().second;
        int distance = -1 * pq.top().first;
        pq.pop();
        
        if(distance > dist[cur]) continue;
        
        for(int i=0; i<graph_v[cur].size(); i++){
            if(1 + distance < dist[graph_v[cur][i]]){
                dist[graph_v[cur][i]] = distance + 1;
                pq.push(make_pair(-1*dist[graph_v[cur][i]], graph_v[cur][i]));
            }
        }
    }
}

int main () {
    cin >> n >> m;
   
    graph_v.resize(n+1);
    
    int y,x;
    for(int i=0; i<m; i++){
        cin >> y >> x;
        graph_v[y].push_back(x);
        graph_v[x].push_back(y);
    }
    for(int i=2; i<=n; i++){
        dist[i] = INF;
    }
    for(int i=0; i<graph_v[1].size(); i++){
        dist[graph_v[1][i]]=1;
    }
    
    dijkstra(1);
    
    int max_dist =0;
    int idx=0;
    int cnt=0;
    for(int i=2; i<=n; i++){
        if(max_dist < dist[i]){
            idx = i;
            max_dist = dist[i];
            cnt=1;
        }
        else if(max_dist==dist[i]){
            cnt++;
        }
    }
    
    
    cout << idx << " " << max_dist << " " << cnt;
    
    return 0;
}

