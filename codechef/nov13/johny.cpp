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

int main(){

	int t;
	inp(t);
	while(t--){
		int n;
		inp(n);
		int a[n];
		for(int i = 0; i < n; i++) inp(a[i]);
		int k;
		inp(k);
		int jo = a[k-1];
		int cnt = 0;
		for(int i = 0; i < n; i++){
			if(a[i] < jo) cnt++;
		}
		cout << cnt+1 << endl;
	}
	return 0;	
}