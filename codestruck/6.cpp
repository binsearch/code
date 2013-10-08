#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>
#define mod 1000000007
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
	n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}
map<pii,lli> m1;
lli recurse(int n, int m){
	// cout << n << " " << m << endl;
	if(n < 0){
		return 0;
	}
	if(n == 0){
		return 1;
	}
	if(m == 1){
		return 1;
	}
	if(m1.find(pii(n,m))!=m1.end())
		return m1[pii(n,m)];

	lli ans;
	ans = recurse(n,m-1) + recurse(n-m,m);
	ans = ans%mod;
	m1[pii(n,m)]=ans;
	return ans;

}

int A[90001][10001];
int main(){

	// lli ans = recurse(90000,10000);
	cout << ans << endl;

	for(lli i=1;i<90001;i++) {
		for(lli j=i;j<10001;j++) {
			A[i][j]=1;
		}
	}
	return 0;	
}