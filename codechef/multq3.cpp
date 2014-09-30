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

int a[1000000];

int query(int r_start, int r_end, int q_start, int q_end, int node, int carry){
	if(r_start == q_start && r_end == q_end){
		if((a[node] + carry) % 3 == 0) return r_end - r_start + 1;
		return 0;
	}
	int r_mid = (r_start + r_end)/2;

	if(q_end <= r_mid){
		return query(r_start, r_mid, q_start, q_end, 2*node, carry + a[node]);
	}
	if(q_start >= r_mid + 1)
		return query(r_mid+1, r_end, q_start, q_end, 2*node + 1, carry + a[node]);

	return query(r_start, r_mid, q_start, r_mid, 2*node, carry + a[node]) + query(r_mid+1, r_end, r_mid + 1, q_end, 2*node + 1, carry + a[node]);
}

void update(int r_start, int r_end, int u_start, int u_end, int node){
	if(r_start == u_start && r_end == u_end)
		a[node]++;
	else {
		int r_mid = (r_start + r_end)/2;

		if(u_end <= r_mid){
			update(r_start, r_mid, u_start, u_end, 2*node);
		}
		else if(u_start >= r_mid+1)
			update(r_mid+1, r_end, u_start, u_end, 2*node + 1);
		else{
			update(r_start, r_mid, u_start, r_mid, 2*node);
			update(r_mid+1, r_end, r_mid + 1, u_end, 2*node + 1);
		}
	}
}

int t_pow(int n){
	int ans = 1;
	while(n/ans != 0 && n != ans)
		ans*=2;
	return ans;
}

int main(){

	memset(a, 0, sizeof a);
	int n,q;
	cin >> n >> q;
	n = t_pow(n);
	for(int i = 0; i < q; i++){
		int t;
		int left, right;
		cin >> t;
		cin >> left >> right;
		if(t == 0){
			update(1, n, left+1, right+1, 1);
		}
		else{
			cout << query(1,n, left+1, right+1, 1, 0) << endl;			
		}
	}

	return 0;
}