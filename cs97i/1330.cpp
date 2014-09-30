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

	int t;
	inp(t);
	while(t--){
		int n;
		inp(n);
		int a[10001] = {0};
		int b[10001] = {0};

		for(int i = 0; i < n-1; i++){
			int p,c;
			inp(p);
			inp(c);
			a[c]= p;
		}

		int n1,n2;
		inp(n1);
		inp(n2);

		while(n1 != 0){
			b[n1] = 1;
			n1 = a[n1];
		}

		while(1){
			if(b[n2] == 1) break;
			n2 = a[n2];
		}

		cout << n2 << endl;

	}

	return 0;	
}