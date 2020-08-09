#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <set>

using namespace std;

void hanoi(int n, int from, int to){
    if(n==0) {
        return;
    }
    
    int intermediate =0;
    
    for(int i=1; i<=3; i++){
        if(i!=from && i!=to) intermediate = i;
    }
    
    hanoi(n-1, from, intermediate);
    cout << from <<" "<< to<< "\n";
    hanoi(n-1, intermediate,to);
}

int main () {
    int n;
    cin >> n;
    int cnt=0;
    for(int i=1; i<=n; i++){
        cnt = 2*cnt+1;
    }
    cout << cnt << "\n";
    hanoi(n,1,3);
    return 0;
}


