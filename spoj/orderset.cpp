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
typedef pair<char,int> pci;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
	n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int n;
int tree[200010];

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

int search(int k, int left, int right){
	if(query(left) == k && (query(left) - query(left-1) == 1)) return left;
	if(query(right) == k && (query (right) - query(right-1) == 1)) return right;
	if(right - left <= 1) return -1;
	int mid = (left + right)/2;
	if(query(mid) < k) search(k, mid, right);
	else search(k,left, mid);
}


int main(){

	scanf("%d", &n);
	memset(tree, 0, sizeof tree);

	int a[200010];
	pci p[200010];
	std::map<int, int> m;

	int cnt = 0;

	for(int i = 0; i < n; i++){
		char c; int t;
		char op[32];
		scanf(" %c %d", &c, &t);
		// if(!strcmp(op, "I")) c = 'I';
		// if(!strcmp(op, "D")) c = 'D';
		// if(!strcmp(op, "K")) c = 'K';
		// if(!strcmp(op, "C")) c = 'C';

		p[i] = pci(c,t);
		if(c != 'k'){
			a[cnt] = t;
			cnt++;
		}
		m[t]=1;
	}

	// int cnt=1;
	// for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
	// 	it->second=cnt++;


	sort(a, a+cnt);
	int cnt1 = 1;
	for(int i = 0; i < cnt; i++){
		m[a[i]] = i+1;
	}

	m[3]=3;

	for(int i = 0; i < n; i++){
		pci op = p[i];
		if(op.first == 'C') printf("%d\n", query(m[op.second]-1));
		if(op.first == 'I') {
			if(query(m[op.second]) == query(m[op.second]-1)){
				update(m[op.second], 1);
			}
		}

		if(op.first == 'D'){
			if(query(m[op.second]) != query(m[op.second]-1)){
				update(m[op.second], -1);
			}
		}

		if(op.first == 'K'){
			int t = search(op.second, 1, cnt);
			if(t == -1) printf("invalid\n");
			else printf("%d\n", a[t-1]);
		}

	}



	return 0;	
}