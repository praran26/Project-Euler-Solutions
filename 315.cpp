#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
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
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;

string to_string(string s) {
	return '"' + s + '"';
}

string to_string(const char* s) {
	return to_string((string) s);
}

string to_string(bool b) {
	return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
	bool first = true;
	string res = "{";
	for (const auto &x : v) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(x);
	}
	res += "}";
	return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug_out(T...);
}

template <typename A, typename B>
istream& operator>>(istream& input,pair<A,B>& x){
	input>>x.F>>x.S;
	return input;
}

template <typename A>
istream& operator>>(istream& input,vector<A>& x){
	for(auto& i:x)
		input>>i;
	return input;
}


#ifdef PRINTERS
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
#define MAXSIEVE 300000000 // All prime numbers up to this in 842 ms, 18348 KB
#define MAXSIEVEHALF (MAXSIEVE/2)
#define MAXSQRT 8670 // sqrt(MAXSIEVE)/2
char a[MAXSIEVE/16+2];
#define isprime(n) (((n)%2)?(a[(n)>>4]&(1<<(((n)>>1)&7))):(n)==2)

void sieve(){
    int i,j;
    memset(a,255,sizeof(a));
    a[0]=(char)0xFE;
    for(i=1;i<MAXSQRT;i++)
        if (a[i>>3]&(1<<(i&7)))
            for(j=2*i*(i+1);j<MAXSIEVEHALF;j+=i+i+1)
                a[j>>3]&=~(1<<(j&7));
}

int sum(int x){
	if(x<10)return x;
	return x%10+sum(x/10);
}

vi alpha={127-4,3,127-16-2,127-16-8,127-104,127-9,127-1,127-76,127,127-8};


int get(int x,int y,bool start=1){
	if(x==0 or y==0)return start?__builtin_popcount(alpha[x%10]&alpha[y%10]):0;
	return __builtin_popcount(alpha[x%10]&alpha[y%10])+get(x/10,y/10,0);
}

void solve(){
	sieve();
	ll res=0;
	for(int i=10000001;i<20000001;i+=2){
		if(isprime(i)){
			vi temp={i};
			while(temp.back()>9)temp.pb(sum(temp.back()));
			rep(j,1,sz(temp)){
				res+=get(temp[j-1],temp[j]);
			}
		}
	}
	cout<<res*2<<endl;
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