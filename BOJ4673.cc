#include <iostream>

using namespace std;

bool arr[10001];

void checkSelfNum(int n){
    int next=n;
    while(n>0){
        next+=n%10;
        n/=10;
    }
    if(next>10000) return;
    arr[next] = true;
    checkSelfNum(next);
}

int main () {
    for(int i=1; i<=10000; i++){
        if(!arr[i]) checkSelfNum(i);
    }
    for(int i=1; i<=10000; i++){
        if(!arr[i]) cout << i <<"\n";
    }
    return 0;
}