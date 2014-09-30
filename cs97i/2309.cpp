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
#define mil 1000000
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
	while( ch >= '0' && ch <= '9' )
	n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
	n=n*sign;
}

lli recurse(int n){
	lli p = 1;

	while(1){
		if(n/p == 1 && n%p == 0) return n-1;
		if(n/p == 0) return recurse(n - p/2);
		p = p*2;
	}
}

int main(){

	int t;
	inp(t);
	while(t--){
		int n;
		inp(n);
		lli ans = recurse(n);
		cout << n-ans << " " << n+ans << endl;
	}
	return 0;	
}