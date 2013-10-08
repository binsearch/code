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
typedef long long int lli;
using namespace std;
inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
	n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}
int dp[2][31];
int recurse(int type, int n){
	if(dp[type][n] != -1)
		return dp[type][n];
	if(type == 0){
		dp[0][n] = recurse(0,n-2)+2*recurse(1,n-2); 
		return dp[0][n;]
	}
	dp[1][n] = recurse(0,n)+recurse(1,n-2); 
	return dp[1][n];
}
int main(){

	while(1){
		int n;
		inp(n);
		if( n == -1) break;
		memset(dp,-1,sizeof dp);
		dp[0][0] = 1;
		dp[0][1] = 0;
		dp[1][1] = 0;
		dp[1][0] = 1;
		printf("%d\n", recurse(0,n));

	}

	return 0;	
}