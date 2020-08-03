#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

bool arr[100][100];
int check[100][100];

int main () {
    int n, m;
    
    cin >> n >> m;
    string input;
    for(int i=0; i<n; i++){
        cin >> input;
        for(int j=0; j<m; j++){
            if(input[j]=='1') arr[i][j]=true;
        }
    }
    
    //bfs
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    pair<int,int> cur;
    int cur_y;
    int cur_x;
    int cnt;
    
    while(!q.empty()){
        
        cur = q.front();
        cur_y = cur.first;
        cur_x = cur.second;
        cnt = check[cur_y][cur_x];
        q.pop();
        
        if(cur_y==n-1 && cur_x==m-1){
            cout << check[n-1][m-1]+1;
            break;
        }
        
        if(cur_y>=1 && arr[cur_y-1][cur_x] && check[cur_y-1][cur_x]==0){ q.push(make_pair(cur_y-1,cur_x));
            check[cur_y-1][cur_x] = cnt+1;
        }
        if(cur_x>=1 && arr[cur_y][cur_x-1] && check[cur_y][cur_x-1]==0){ q.push(make_pair(cur_y,cur_x-1));
            check[cur_y][cur_x-1] = cnt+1;
        }
        if(cur_y+1<n && arr[cur_y+1][cur_x] && check[cur_y+1][cur_x]==0){
            q.push(make_pair(cur_y+1,cur_x));
            check[cur_y+1][cur_x] = cnt+1;
        }
        if(cur_x+1<m && arr[cur_y][cur_x+1] && check[cur_y][cur_x+1]==0){ q.push(make_pair(cur_y,cur_x+1));
            check[cur_y][cur_x+1] = cnt+1;
        }
    }

    return 0;
}

