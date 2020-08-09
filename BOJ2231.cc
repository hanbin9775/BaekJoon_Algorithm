#include <iostream>

using namespace std;

bool ifConstructorNum(int n, int &origin){
    
    int convert=n;
    
    while(n>0){
        convert+= n%10;
        n /=10;
    }
    if(convert==origin) return true;
    else return false;
}

int main () {
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        if(ifConstructorNum(i,n)){
            cout << i;
            break;
        }
        if(i==n){
            cout << 0;
        }
    }
    
    return 0;
}

