#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <unordered_map>

using namespace std;

int main(){
    
    int t;
    cin >> t;
    
    while(t-->0){
        int h,w,n;
        
        cin >> h >> w >> n;
        
        int row = n/h+1;
        int col = n%h;
        if(col==0) {
            col = h;
            row-=1;
        }
        cout << col*100+row<< "\n";
        
    }
    
    
    return 0;
    
}



