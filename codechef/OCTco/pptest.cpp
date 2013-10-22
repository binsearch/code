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
int n;
int dp[111][111];
int c[101];
int p[101];
int t[101];

int recurse(int ind, int ti){
	
	if(dp[ind][ti] != -1) return dp[ind][ti];

	if(ind == n) return 0;
	if(ti < t[ind]){
		dp[ind][ti] = recurse(ind+1,ti);
		return dp[ind][ti];
	}

	dp[ind][ti] = max(recurse(ind+1,ti), p[ind]*c[ind] + recurse(ind+1,ti-t[ind]));
	return dp[ind][ti];

}

int main(){

	int tc;
	inp(tc);
	while(tc--){
		memset(dp, -1, sizeof dp);
		int w;
		inp(n);
		inp(w);

		for(int i = 0; i < n; i++){
			inp(c[i]);
			inp(p[i]);
			inp(t[i]);
		}

		cout << recurse(0,w) << endl;
	}

	return 0;	
}