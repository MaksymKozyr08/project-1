#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
    ll x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    ll dx=x2-x1;
    ll dy=y2-y1;
    double cos60=0.5;
    double sin60=sqrt(3)/2.0;
    double x3=x1+dx*cos60-dy*sin60;
    double y3=y1+dx*sin60+dy*cos60;
    cout<<x3<<" "<<y3;
    return 0;
}