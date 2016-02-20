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
    ll sum1=0,sum2=0;
    rep(i,1,101){
        sum1+=i;
        sum2+=i*i;
    }
    cout<<sum1*sum1-sum2;
}

int main(){
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}
