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
    int suma=0;
    rep(i,1,1000){
        if(i%3==0 || i%5==0){
            suma+=i;
        }
    }
    cout<<suma;
}

int main(){
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}
