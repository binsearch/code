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
#define MOD 5000000
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
#define vvi vector<vector<int> > 
#define vi vector<int>
//intializing ---- vvi res(k, vi(k,0))
#define rep(i,a,b) for(int i = a; i < b; i++)

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
	n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int tree[100010][60];
int n;

void update(int idx, int val, int tn){
	
	while(idx <= 100010){
		tree[idx][tn] = (tree[idx][tn] + val)%MOD;
		idx += idx & -idx;  
	}

}

int query(int idx, int tn){
	int ans = 0;
	while(idx >= 1){
		ans = (ans + tree[idx][tn])%MOD;
		idx -= idx & -idx;
	}
	return ans;
}



int f[10010][55];

int fac(int m, int k){
	if(f[m][k] != -1) return f[m][k];
	if(k == 0 || m == k) return 1;
	f[m][k] = (fac(m-1,k-1) + fac(m-1,k))%MOD;
	return f[m][k];
}


int main(){
	memset(f, -1, sizeof f);
	memset(tree, 0, sizeof tree);
	int n,k;
	inp(n);
	inp(k);
	int s[100010] = {0};
	int cnt = 0;
	int t;
	for(int i = 0; i < n; i++){
		cin >> t;
		// if(query(t+1) - query(t) == 0)
		// 	update(t+1, 1);
		// int m = query(t);
		// if(m >= k-1){
		// 	cnt = (cnt + fac(m,k-1))%MOD;
		// }
		for(int j = 1; j <= k; j++){
			if(j == 1) update(t+1,1,1);
			else{
				update(t+1, query(t,j-1), j);
			}
		}
	}
	// cout << query(3,2) << endl;
	printf("%d\n", query(100005,k));

	return 0;	
}