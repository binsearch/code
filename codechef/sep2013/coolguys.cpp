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
typedef long long int lli;
using namespace std;
lli gcd (lli a, lli b) {
    return (b == 0) ? a : gcd (b, a%b);
}
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
	for(int i = 0; i < t; i++){
		int n;
		inp(n);
		lli count = 0;
		lli j = 1;
		while(j <= n){
			lli temp;
			temp = n/j;
			count = count+(lli)(n/temp + 1 - j)*(lli)temp;
			j = n/temp + 1;
		}

		lli tot;
		tot = (lli)n*(lli)n;
		lli g = gcd(tot,count);
		tot = tot/g;
		count = count/g;
		cout << count << "/" << tot << endl;

	}

	return 0;
}