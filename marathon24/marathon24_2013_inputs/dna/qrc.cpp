#include <vector>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#define mod 1000000007
using namespace std;
typedef long long int lli;
typedef pair<int,int> ii;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
	n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int main() {
	lli n,m,a,b,ans[20001][20001];
	bool A[20001][20001];

	inp(n);
	inp(m);

	return 0;
}