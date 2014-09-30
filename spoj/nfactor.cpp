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
#define mod 1000000007
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

int pfact[1000010] = {0};
int nfact[1000010] = {0};
int ans[1000010][11] = {0};

int main(){

	// cout << "came" << endl;

	for(int i = 2; i < 1000; i++){
		if(pfact[i] == 0){
			for(int j = i*i; j <= 1000000; j= j+i){
				pfact[j] = i;
			}
		}
	}
	// cout << "came" << endl;
	for(int i = 2; i <= 1000000; i++){
		if(pfact[i] == 0) nfact[i] = 1;
		else{
			int temp = i/pfact[i];
			if(temp%pfact[i] == 0){nfact[i] = nfact[temp];}
			else nfact[i] = nfact[temp] + 1;
		}
	}
	// cout << ans[0][1] << endl;
	// cout << ans[0][1] << endl;
	// cout << ans[3][1] << endl;

	for(int i = 1; i <= 1000000; i++){
		for(int j = 0; j <= 10; j++){
			if(nfact[i] == j) ans[i][j] = ans[i-1][j]+1;
			else ans[i][j] = ans[i-1][j];
		}
	}

	// cout << ans[0][1] << endl;
	// cout << ans[0][1] << endl;
	// cout << ans[3][1] << endl;

	int t;
	inp(t);
	while(t--){
		int a,b,n;
		cin >> a >> b >> n;
		int sol = ans[b][n] - ans[a-1][n];
		cout << sol << endl;

	}

	return 0;	
}