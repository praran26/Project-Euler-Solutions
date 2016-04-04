#include <bits/stdc++.h>
#define gcd(a,b) __gcd(a,b)
#define ll long long int
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vvi vector<vi>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define all(a) a.begin(),a.end()
#define sum(a) accumulate(all(a),0)
#define endl '\n'
#define hell 1000000007
#define N 99999999
using namespace std;
bool mysieve[N+1];
ll expo(ll base, ll exponent, ll mod) {								//return base^exponent modulo modulus
	ll ans = 1;
	while(exponent !=0 ) {
		if((exponent&1) == 1) {
			ans = ans*base ;
			ans = ans%mod;
		}
		base = base*base;
		base %= mod;
		exponent>>= 1;
	}
	return ans;
}
int main()
{
	for(int i = 0; i <= N;++i){
		mysieve[i] = true;
	}
	mysieve[0] = false;
	mysieve[1] = false;
	for(int i = 2; i * i <= N; ++i) {
		if(mysieve[i] == true) {
			for(int j = i * i; j <= N ;j += i)
				mysieve[j] = false;
		}
	}
    ll ans=0;
    rep(i,5,N+1){
        if(mysieve[i]){
            ll a=expo(i-2,i-2,i);
            ll b=expo(i-3,i-2,i);
            ll c=expo(i-4,i-2,i);
            ll d=(a*b)%i;
            ll e=(d*c)%i;
            ans+=(a+d+e)%i;
        }
    }
    cout<<ans;
    return 0;
}
