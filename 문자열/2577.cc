#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <unordered_map>

using namespace std;

int cnt[10];

int main(){
    
    int a, b, c;
    cin >> a >> b >> c;
    string total = to_string(a*b*c);
    
    for(int i=total.length()-1; i>=0; i--){
        cnt[total[i]-'0'] +=1;
    }
    for(int i=0; i<10; i++){
        cout << cnt[i] << "\n";
    }
    
    return 0;
    
}



