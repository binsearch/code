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

lli recurse(int n){
	if(n == 0) return 1;
	if(n%2 == 1){
		return (2*recurse(n-1))%mod;
	}

	lli temp = recurse(n/2);
	lli ans = 1;
	for(int i = 0; i < 10; i++){
		ans = (ans * temp)%mod;
	}
	return ans;

}

int main(){

	int t;
	inp(t);
	while(t--){
		int n;
		inp(n);
		lli ans = recurse(n);
		ans = (ans*ans)%mod;
		printf("%lld\n", ans);
	}

	return 0;	
}