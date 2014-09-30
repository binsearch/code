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
int a[1000010];

int search(int val, int left, int right){
	if(left == right && a[left] != val) return -1;
	int mid = (left + right)/2;
	if(a[mid] > val) return search(val, left, mid);
	if(a[mid] < val) return search(val, mid+1, right);
	return mid;
}

int main(){

	int len;
	
	while(cin >> len){
		len *= 10000000;

		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
		}

		sort(a, a+n);
		int flag = 0;
		int ans;
		// cout << "sort done" << endl;
		for(int i = 0; i < n; i++){
			int temp = search(len - a[i], 0, n-1);
			if( temp != -1 && temp != i){
				flag = 1;
				ans = a[i];
				break;
			}
		}

		if(flag) printf("yes %d %d\n", ans, len - ans);
		else printf("danger\n");
	}

	return 0;	
}