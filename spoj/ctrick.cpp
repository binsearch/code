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

int n;
int tree[20010];
void init_t(){
	for(int i = 1; i <= n; i++){
		tree[i] = i&-i;
	}
}

void update(int idx, int val){
	
	while(idx <= n){
		tree[idx] = (tree[idx] + val);
		idx += idx & -idx;  
	}

}

int query(int idx){
	int ans = 0;
	while(idx >= 1){
		ans = (ans + tree[idx]);
		idx -= idx & -idx;
	}
	return ans;
}

int search(int k, int left, int right){
	if(query(left) == k && (query(left) - query(left-1) == 1)) return left;
	if(query(right) == k && (query (right) - query(right-1) == 1)) return right;
	if(right - left <= 1) return -1;
	int mid = (left + right)/2;
	if(query(mid) < k) search(k, mid, right);
	else search(k,left, mid);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		init_t();
		int ord[20010];
		int ind = 0;
		for(int i = 1; i <= n; i++){
			// for(int j = 1; j <= n; j++){
			// 	cout << tree[j] << " ";
			// }
			// cout << " w"<<query(n)<<endl;

			int temp;
			if(query(ind) + i + 1 <= query(n)){
				temp = query(ind)+i + 1;
				// cout << temp << "www " << query(n) << endl;
			}
			else{

				temp = query(ind) + i + 1 - query(n);
				// cout << temp << "www " << query(n) << endl;
				temp %= query(n);
				if(temp == 0) temp = query(n);
			}
			int ans = search(temp, 1, n);
			ord[ans] = i;
			update(ans,-1);
			ind = ans;
		}
		for(int i = 1; i <= n; i++){
			printf("%d ", ord[i]);
		}
		printf("\n");		
	}

	return 0;	
}