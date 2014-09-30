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
		int t2 = n;
		int ntwo = 0;
		while(t2%2 == 0){
			ntwo++;
			t2 = t2/2;
		}
		t2 = n;
		int nfive = 0;
		while(t2%5 == 0){
			nfive++;
			t2 = t2/5;
		}

		if(nfive+2 > ntwo){
			ntwo = nfive+2;
		}

		else if(nfive+2 < ntwo){
			nfive = ntwo -2;
		}

		while(n%2 == 0){
			n = n/2;
		}

		while(n%5 == 0){
			n = n/5;
		}

		lli k = 1;
		int nfour;
		for(int i = 0; i < 18; i++){
			if(k%n == 0){
				nfour = i+1;
				break;
			}
			k = k*10+1;
		}

		cout << 2*nfour+nfive << endl;

	}
	

	return 0;	
}