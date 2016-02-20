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
    vector<int>a;
    a.pb(0);
    a.pb(1);
    int i=0;
    cout<<"Generating fibonacci numbers less than 4 million..."<<endl;
    while(a.back()<4000000){
        a.pb(a[i]+a[i+1]);
        i+=1;
    }
    cout<<"Fibonacci numbers generated..."<<endl;
    cout<<"Calculating sum..."<<endl;
    ll suma=0;
    for(int i=0;i<a.size();i+=3){   //Even fibonacci numbers are at indexes which are multiples of 3
        suma+=a[i];
    }
    cout<<"Sum calculated..."<<endl;
    cout<<"The answer is: "<<suma;
}

int main(){
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}
