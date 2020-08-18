#include <iostream>

using namespace std;

int main () {
    
    long long n;
    cin >> n;
    
    long long a,b,c,d,e,f;
    cin >>a>>b>>c>>d>>e>>f;

    
    long long block1 = min(a,min(b,min(c,min(d,min(e,f)))));
    long long block2 = min(min(a,f)+min(b,min(c,min(d,e))), min(b+c, min(c+e, min(e+d,d+b))));
    long long block3 = min(a,f) + min(b+c, min(c+e, min(e+d,d+b)));
    
    if(n==1){
        cout << a+b+c+d+e+f - max(a,max(b,max(c,max(d,max(e,f)))));
    }
    else{
        cout << block3*4 + block2*4*(2*(n-1)-1) + block1*(4*(n-2)*(n-1)+(n-2)*(n-2));
    }
    
    
    return 0;
}



