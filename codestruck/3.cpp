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
lli mod = 1000000007;
inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
	n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

const lli in = 1e15;
double in1 = 1e15;

int main(){

	lli cnt = 0;lli k=sqrt(in1);
	cout<<k<<" "<<k*k<<endl;
	k++;
	lli sum;
	cout<<k<<" "<<k*k<<endl;
	for(lli i = 1; i < sqrt(in1); i++){
		cnt+= in/i - i;
		sum=in/i-i;
		if(sum<=1)
			cout<<i<<endl;
		cnt = cnt % mod;
		k=i;
	}
	cout<<k<<endl;
	cnt = (cnt*2)%mod;
	cnt+=  sqrt(in1);
	cnt = cnt % mod;
	cout << cnt << endl;
	return 0;	
}