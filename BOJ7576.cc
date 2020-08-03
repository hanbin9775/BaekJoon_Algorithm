#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int n, m;
int arr[1000][1000];
int depth[1000][1000];

int main () {
    cin >> m >> n;
    
    queue<pair<int, int>> q;
    int fresh_tomatoes = n*m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >>arr[i][j];
            if(arr[i][j]==1) q.push(make_pair(i,j));
            if(arr[i][j]==-1 || arr[i][j]==1) fresh_tomatoes--;
        }
    }
    int y, x;
    int cnt=0;
    int max_depth =0;
    while(!q.empty()){
        y=q.front().first;
        x=q.front().second;
        q.pop();

        if(cnt==fresh_tomatoes) break;
        
        if(y>0 && arr[y-1][x]==0) {
            q.push(make_pair(y-1,x));
            arr[y-1][x]=1;
            cnt++;
            depth[y-1][x] = depth[y][x]+1;
        }
        if(x>0 && arr[y][x-1]==0) {
            q.push(make_pair(y,x-1));
            arr[y][x-1]=1;
            cnt++;
            depth[y][x-1] = depth[y][x]+1;
        }
        if(y<n-1 && arr[y+1][x]==0 ) {
            q.push(make_pair(y+1,x));
            arr[y+1][x]=1;
            cnt++;
            depth[y+1][x] = depth[y][x]+1;
        }
        if(x<m-1 && arr[y][x+1]==0) {
            q.push(make_pair(y,x+1));
            arr[y][x+1]=1;
            cnt++;
            depth[y][x+1] = depth[y][x]+1;
        }
        max_depth = max(max_depth, depth[y][x]+1);
    }
    
    if(cnt==fresh_tomatoes) cout<<max_depth <<"\n";
    else cout << -1 <<"\n";
    return 0;
}

