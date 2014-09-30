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

int tree[30010];
int n;

void update(int idx, int val){
	
	while(idx <= n){
		tree[idx] += val;
		idx += idx & -idx;  
	}

}

int query(int idx){
	int ans = 0;
	while(idx >= 1){
		ans += tree[idx];
		idx -= idx & -idx;
	}
	return ans;
}

int main(){

	memset(tree, 0, sizeof tree);
	inp(n);
	int a[30010];
	for(int i = 1; i <= n; i++){
		inp(a[i]);
	}
	// cout << "first input" << endl;
	int q;
	inp(q);

	pair<pii, int> d[200010];
	int ans[200010];

	for(int k = 0; k < q; k++){
		int i,j;
		inp(i);
		inp(j);
		d[k] = pair<pii, int> (pii(j,i), k);
	}
	// cout << "second inp" << endl;
	sort(d,d+q);
	int pocc[1000010];
	memset(pocc, -1, sizeof pocc);
	// cout << "inp done" << endl;
	int prev = 0;

	for(int i = 0; i < q; i++){
		// cout << d[i].first.second << " " << d[i].first.first << endl;
		for(int j = prev+1; j <= d[i].first.first; j++){
			if(pocc[a[j]] != -1){
				// cout << "before update" << endl;
				// cout << pocc[a[j]] << " " << j << endl;
				update(pocc[a[j]], 1);
				// cout << "after update" << endl;
			}
			pocc[a[j]] = j;
		}
		// cout << "one build" << endl;
		prev = d[i].first.first;
		ans[d[i].second] = d[i].first.first - d[i].first.second + 1 - query(d[i].first.first) + query((d[i].first.second) - 1);

	}

	for(int i = 0; i < q; i++){
		printf("%d\n",ans[i]);
	}


	return 0;	
}