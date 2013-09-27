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
#define inf 0x3f3f3f3f
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

int dp[1001][22][80];
int volo[1001];
int voln[1001];
int weight[1001];
int totc;
int recurse (int n, int vo, int vn){
	//cout << vo << " " << vn << endl;
	if(vo <= 0 && vn <= 0)
		return 0;
	if(n >= totc)
		return inf;
	if(vo < 0)
		vo = 0;
	if(vn < 0)
		vn = 0;
	if(dp[n][vo][vn] != -1)
		return dp[n][vo][vn];
	dp[n][vo][vn] = min(recurse(n+1,vo,vn), weight[n] + recurse(n+1, vo-volo[n], vn -voln[n]));
	return dp[n][vo][vn];
}


int main(){

	int t;
	inp(t);
	while(t--){
		memset(dp, -1 , sizeof dp);
		// memset(volo,0, sizeof volo);
		// memset(voln, 0 , sizeof voln);
		// memset(weight,0,sizeof weight);
		int vn,vo,n;
		inp(vo);
		inp(vn);
		inp(n);
		totc = n;
		for(int i = 0; i < n; i++){
			inp(volo[i]);
			inp(voln[i]);
			inp(weight[i]);
		}
		cout << recurse(0,vo,vn) << endl;
	}

	return 0;	
}