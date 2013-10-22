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
	int j = 0;
	while(1){
		j++;
		int n;
		inp(n);
		if( n == 0) break;
		int a[n];
		int tot = 0;
		for(int i = 0; i < n; i++){ 
			inp(a[i]);
			tot = tot + a[i];
		}

		tot = tot/n;
		int ans = 0;
		for(int i = 0; i < n; i++){
			if(a[i] > tot){
				ans = ans + a[i] - tot;
			} 
		}
		cout << "Set #" << j << endl;
		cout << "The minimum number of moves is " << ans << "." << endl;
	}

	return 0;	
}