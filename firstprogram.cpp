#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define maxll 9223372036854775807
#define maxint 2147483647

using namespace std;

int main() {
    ll x1,x2,y1,y2;
    ll o1,o2,r;
    cin>>x1>>y1>>x2>>y2;
    cin>>o1>>o2>>r;
    ll A,B,C;
    A-=pow((x2-x1),2)+pow((y2-y1),2);
    B=2*((x2-x1)*(x1-o1)+(y2-y1)*(y1-o2));
    C=pow((x1-o1),2)+pow((y1-o2),2)-pow(r,2);
    ll D=pow(B,2)-4*A*C;
    if(D<0)cout<<"No roots";
    else if(D==0)cout<<(-1)*(B/(2*A));
    else if(D>0){
        cout<<(((-1)*B)-D)/(2*A)<<endl;
        cout<<(((-1)*B)+D)/(2*A);
    }
    
    return 0;
}