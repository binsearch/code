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
		
		for(int i = 0; i < n; i++) 
			inp(a[i]);

		int b[50] = {0};
		lli sum = 0;
		lli tsum = 0;

		for(int i = n-1; i >= 0; i--){
			for(int j = 0, k = 1; j < 32; j++, k = k*2){
				if((a[i] >> j)%2 == 1){
					tsum = tsum + (lli)k*(n-i-b[j]-b[j]);
					
					b[j] = n-i-b[j];
				}
			}
			sum+= tsum;
		}

		cout << sum << endl;
	}

	return 0;	
}