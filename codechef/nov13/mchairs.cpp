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

lli mypow(lli n){
	if(n == 0) return 1;
	if(n%2 == 1){
		return (2*mypow(n-1))%mod;
	}
	lli ans;
	ans = mypow(n/2);
	ans = (ans * ans)%mod;
	return ans;
}

int main(){

	int t;
	inp(t);
	while(t--){
		lli n;
		cin >> n;
		cout << (mypow(n)-1) << endl;
	}

	return 0;	
}