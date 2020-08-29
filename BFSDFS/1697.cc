#include <iostream>
#include <queue>

using namespace std;

bool visited[100001];

int main(){
    int n, m;
    cin >> n >> m;
    
    queue<pair<int,int>> q;
    q.push(make_pair(n,0));
    visited[n] = true;
    
    while(!q.empty()){
        
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(cur==m){
            cout << cnt;
            break;
        }
        
        if(cur-1>=0 && !visited[cur-1]) {
            q.push(make_pair(cur-1,cnt+1));
            visited[cur-1] = true;
        }
        if(cur+1<=100000 && !visited[cur+1]){
            q.push(make_pair(cur+1,cnt+1));
            visited[cur+1] = true;
        }
        if(cur*2<=100000 && !visited[cur*2]){
            q.push(make_pair(cur*2,cnt+1));
            visited[cur*2] = true;
        }
    }
    
    
    return 0;
    
}