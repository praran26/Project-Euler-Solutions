#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
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
#define N 80
using namespace std;
int main()
{
    freopen("p082_matrix.txt","r",stdin);
    ll x[N][N];
    rep(i,0,N){
        rep(j,0,N){
            cin>>x[i][j];
        }
    }
    rep(i,1,N){
        ll y[N];
        rep(j,0,N)y[j]=x[j][i];
        rep(j,0,N){
            ll mina=LLONG_MAX;
            rep(k,0,N){
                ll cur=x[k][i-1];
                if(j==k){
                    mina=min(mina,cur);
                }
                else if(j<k){
                    rep(l,j+1,k+1){
                        cur+=y[l];
                    }
                    mina=min(mina,cur);
                }
                else{
                    rep(l,k,j){
                        cur+=y[l];
                    }
                    mina=min(mina,cur);
                }
            }
            x[j][i]+=mina;
        }
    }
    ll mina=LLONG_MAX;
    rep(i,0,N){
        mina=Min(mina,x[i][N-1]);
    }
    cout<<mina;
    return 0;
}
