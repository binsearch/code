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

lli dp[160];
lli recurse(int n){
	
	if(dp[n] != -1) return dp[n];

	lli tot = 0;
	for(int i = 0; i < n; i++){
		tot+= recurse(i)*recurse(n-1-i);
	}
	dp[n] = tot;
	return tot;

}

int main(){
	
	while(1){
		int n;
		inp(n);
		if(n == -1){
			break;
		}
		memset(dp, -1, sizeof dp);
		dp[0] = 1;
		dp[1] = 1;
		printf("%lld\n",recurse(n));

	}


	return 0;	
}