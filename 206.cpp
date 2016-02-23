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

using namespace std;

template <class X>
void input(vector<X>&a,ll N){
    X temp;
    rep(i,0,N){
        cin>>temp;
        a.push_back(temp);
    }
}
bool isGood(ll a){
    a*=a;
    string mynum;
    stringstream p;
    p<<a;
    p>>mynum;
    for(int i=0;i<9;i++){
        if(mynum[2*i]!=i+'1')return false;
    }
    return true;
}
void solve(){
    ll a=1010101030;
    while(!isGood(a)){
        if(a%100==30)a+=40;
        else a+=60;
    }
    cout<<a;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}
