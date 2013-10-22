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

int mygcd(int a, int b){
	if(b == 0) return a;

	return mygcd(b, a%b);
}

int main(){

	int t;
	inp(t);
	while(t--){
		int x1,y1,x2,y2;
		inp(x1);
		inp(y1);
		inp(x2);
		inp(y2);
		int dx = x2 - x1;
		int dy = y2 - y1;
		if(dx < 0) 
			dx = -dx;
		if(dy < 0) 
			dy = -dy;
		
		int gc;
		if(dy == 0 || dx == 0){
			cout << 0 << endl;
			continue;
		}

		if(dy > dx) 
			gc = mygcd(dy,dx);
		else 
			gc = mygcd(dx,dy);
		int ans = dx + dy - gc;
		cout << ans << endl;
	}

	return 0;	
}