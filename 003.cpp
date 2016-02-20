#include <bits/stdc++.h>
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
#define DEBUG true
using namespace std;
template <class X>
void input(vector<X>&a,int N){
    X temp;
    rep(i,0,N){
        cin>>temp;
        a.push_back(temp);
    }
}
void solve(){
    ll N=600851475143;
    vector<ll>divisors;
    rep(i,2,N+1){
        if(N%i==0){
            divisors.pb(i);
            while(N%i==0)N/=i;
        }
    }
    cout<<*max_element(all(divisors));
}

int main(){
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}
