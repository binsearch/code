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
	int ch=getchar(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
	while( ch >= '0' && ch <= '9' )
	n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
	n=n*sign;
}

int main(){

	while(1){
		int n,m;
		inp(n);
		inp(m);
		if(n == -1 && m == -1) break;
		int i;
		for(i = 0; i <= n; i++){
			if((i*(i-1))/2 >= m) break;
		}

		i--;
		int k = n-i+m - (i*(i-1))/2;
		for(int j = 1; j <= n-i-1; j++)
			cout << j << " ";
		if(i > -1) cout << k << " ";
		for(int j = n; j >= n-i; j--){
			if(j == k) continue;
			cout << j << " ";
		}
		cout << endl;

	}

	return 0;	
}