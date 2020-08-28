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
    
    unordered_map<int, int> um;
    unordered_map<int, int>::iterator it;
    
    int n, m;
    cin >> n;
    
    for(int i=0; i<n; i++){
        int input;
        scanf("%d", &input);
        
        it=um.find(input);
        
        if(it==um.end()) um.insert(make_pair(input,1));
        else it->second++;
    }
    cin >> m;
    for(int i=0; i<m; i++){
        int input;
        scanf("%d", &input);
        it = um.find(input);
        
        if(it==um.end()) cout << 0 << " ";
        else cout << it->second << " ";
    }
    
    return 0;
    
}



