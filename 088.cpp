#include "bits/stdc++.h"

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)		cerr<<#a<<" : "<<a<<endl
#else
#define tr(a)    
#endif

#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
#define K 			12000
using namespace std;

vector<vi>factorizations(int a,int b){
	if(a==1)return {{}};
	vector<vi>ans;
	for(int i=2;i*i<=a;i++){
		if(a%i==0){
			if(i<=b){
				vector<vi>vals=factorizations(a/i,i);
				for(auto j:vals){
					j.pb(i);ans.pb(j);
				}					
			}
			if(a/i<=b and i*i!=a){
				vector<vi>vals=factorizations(i,a/i);
				for(auto j:vals){
					j.pb(a/i);ans.pb(j);
				}	
			}
		}
	}
	if(a<=b){
		ans.pb({a});
	}
	return ans;
}

vector<vi>factorizations(int num){
	return factorizations(num,num);
}
int best[K+5];
void solve(){
	int done=K-1;
	for(int i=2;;i++){
		vector<vi>vals=factorizations(i);
		for(auto j:vals){
			if(done==0)break;
			int val=i-accumulate(all(j),0)+sz(j);
			if(val>K or best[val] or val<2)continue;
			best[val]=i;
			done--;
		}
		if(done==0)break;
	}
	set<int>anss;
	rep(i,2,K+1)anss.insert(best[i]);
	cout<<accumulate(all(anss),0LL)<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}