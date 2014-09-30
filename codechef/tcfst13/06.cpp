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

	int n;
	cin >> n;
	int a[n];
	int b[n];
	int neg[n];
	for(int i = 0; i < n; i++)
		inp(a[i]);
	int tot = 0;
	int ztot = 0;
	int ntot = 0;
	for(int i = 0; i < n; i++){
		if(a[i] > 0){
			tot++;
		}
		if(a[i] == 0)
			ztot++;
		if(a[i] < 0)
			ntot++;
		b[i] = tot;
		neg[i] = ntot;
	}

	int m = n+1;

	for(int i = 0; i < n-1; i++){
		if(b[i]+neg[n-1]-neg[i]+ ztot < m)
			m = b[i]+neg[n-1]-neg[i]+ ztot;
	}

	cout << m << endl;

	return 0;	
}