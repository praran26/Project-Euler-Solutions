#include <bits/stdc++.h>
#define M 100
#define gcd(a,b) __gcd(a,b)
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
bool isSqr(ll n){
	float x=sqrt(n);
	ll t=floor(x);
	ll p=ceil(x);
	return (t*t==n || p*p==n);
}
int main()
{
    ll counter=0;
    rep(a,1,M+1){
        rep(b,1,M+1){
            rep(c,1,M+1){
                rep(d,1,M+1){
                    ll x=(b+d)*(a+c)+2-gcd(a,b)-gcd(b,c)-gcd(c,d)-gcd(a,d);
                    if(x&1)continue;
                    x/=2;
                    if(isSqr(x))counter++;
                }
            }
        }
    }
    cout<<counter;
    return 0;
}
