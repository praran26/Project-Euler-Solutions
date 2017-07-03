#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)		cerr<<#a<<": "<<a<<endl;
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
using namespace std;
int finalans;
void solve(){
	string s;
	rep(_,0,1000){
		cin>>s;
		int cur=0;
		int number=0;
		while(cur<sz(s)){
			if(s[cur]=='M'){
				number+=1000;
				cur++;
			}
			else if(s[cur]=='C' and s[cur+1]=='M'){
				number+=900;
				cur+=2;
			}
			else if(s[cur]=='D'){
				number+=500;
				cur++;
			}
			else if(s[cur]=='C' and s[cur+1]=='D'){
				number+=400;
				cur+=2;
			}
			else if(s[cur]=='C'){
				number+=100;
				cur++;
			}
			else if(s[cur]=='X' and s[cur+1]=='C'){
				number+=90;
				cur+=2;
			}
			else if(s[cur]=='L'){
				number+=50;
				cur++;
			}
			else if(s[cur]=='X' and s[cur+1]=='L'){
				number+=40;
				cur+=2;
			}
			else if(s[cur]=='X'){
				number+=10;
				cur++;
			}
			else if(s[cur]=='I' and s[cur+1]=='X'){
				number+=9;
				cur+=2;
			}
			else if(s[cur]=='V'){
				number+=5;
				cur++;
			}
			else if(s[cur]=='I' and s[cur+1]=='V'){
				number+=4;
				cur+=2;
			}
			else if(s[cur]=='I'){
				number++;
				cur++;
			}
			else assert(false);
		}
		int cnt=0;
		while(number){
			if(number>=1000){
				number-=1000;
				cnt+=1;
			}
			else if(number>=900){
				number-=900;
				cnt+=2;
			}
			else if(number>=500){
				number-=500;
				cnt+=1;
			}
			else if(number>=400){
				number-=400;
				cnt+=2;
			}
			else if(number>=100){
				number-=100;
				cnt+=1;
			}
			else if(number>=90){
				number-=90;
				cnt+=2;
			}
			else if(number>=50){
				number-=50;
				cnt+=1;
			}
			else if(number>=40){
				number-=40;
				cnt+=2;
			}
			else if(number>=10){
				number-=10;
				cnt+=1;
			}
			else if(number>=9){
				number-=9;
				cnt+=2;
			}
			else if(number>=5){
				number-=5;
				cnt+=1;
			}
			else if(number>=4){
				number-=4;
				cnt+=2;
			}
			else if(number>=1){
				number-=1;
				cnt++;
			}
			else assert(false);
		}
		finalans+=sz(s)-cnt;
	}
	cout<<finalans;
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