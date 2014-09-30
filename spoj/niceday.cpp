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

int tree[100010];
int n;
int inf = 1000000;
void update(int idx, int val){
	
	while(idx <= n){
		tree[idx] = min(tree[idx],val);
		idx += idx & -idx;  
	}

}

int query(int idx){
	int ans = 1000000;
	while(idx >= 1){
		ans = min(ans, tree[idx]);
		idx -= idx & -idx;
	}
	return ans;
}

void init_t(){
	for(int i = 0; i < 100010; i++){
		tree[i] = inf;
	}
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		init_t();
		scanf("%d", &n);
		int a[2][100010];
		pii f[100010];
		for(int i = 0; i < n; i++){
			int temp;
			scanf("%d %d %d", &temp, &a[0][i], &a[1][i]);
			f[i] = pii(temp,i);
		}
		
	

		sort(f, f+n);

		int cnt = 0;
		for(int i = 0; i < n; i++){
			int ind = a[0][f[i].second];
			if(query(ind-1) > a[1][f[i].second])
				cnt++;
			update(ind, a[1][f[i].second]);
		}
		printf("%d\n", cnt);

	}

	return 0;	
}