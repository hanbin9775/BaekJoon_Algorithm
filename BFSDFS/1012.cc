#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <unordered_map>

using namespace std;

int dir_y[4] = {-1,0,1,0};
int dir_x[4] = {0,1,0,-1};

bool arr[50][50];

void dfs(int y, int x, int n, int m){
    
    stack<pair<int,int>> stk;
    stk.push(make_pair(y,x));
    arr[y][x] = false;
    
    while(!stk.empty()){
        
        int cur_y = stk.top().first;
        int cur_x = stk.top().second;
        stk.pop();
        
        for(int i=0; i<4; i++){
            int next_y = cur_y + dir_y[i];
            int next_x = cur_x + dir_x[i];
            
            if(next_y<0 || next_y==n || next_x < 0 || next_x==m ){
                continue;
            }
            
            if(arr[next_y][next_x]){
                arr[next_y][next_x] = false;
                stk.push(make_pair(next_y, next_x));
            }
        }
        
        
    }
    
    
}

int main(){
    
    int t;
    cin >> t;
    
   
    
    while(t-->0){
        int worm_count = 0;
        int width, height;
        cin >> width >> height;
        
        int lettuceNumber;
        cin >> lettuceNumber;
        
        for(int i=0; i<lettuceNumber; i++){
            int x, y;
            cin >> x >> y;
            
            arr[y][x] = true;
        }
        
        for(int i=0; i<height; i++){
            for(int j=0; j<width; j++){
                if(arr[i][j]){
                    worm_count+=1;
                    dfs(i,j, height, width);
                }
            }
        }
       
        cout << worm_count<< "\n";
        
    
    }
    
    
    return 0;
    
}



