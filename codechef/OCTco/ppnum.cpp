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

int modsum (lli a, lli b){
	lli ans;
	ans = b * (b+1);
	ans = ans / 2;
	lli temp = a * (a+1);
	temp = temp / 2;
	ans = ans - temp;
	ans = ans + a;
	ans = ans % mod;
	return ans ;
}

int main(){

	int t;
	inp(t);
	while(t--){
		lli l,r;
		cin >> l;
		cin >> r;

		lli pt = 1;
		lli ans = 0;
		while(1){
			if(l >= pt){
				ans =  ans + modsum(l,r);
				ans = ans % mod;
			}
			else if (pt <= r){
				ans = ans + modsum(pt,r);
				ans = ans % mod;
			}
			else if(pt > r){
				break;
			}
			pt = pt*10;
		}
		cout << ans << endl;
	}

	return 0;	
}