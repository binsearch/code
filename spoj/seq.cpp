// Author: Rohith Kishan
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
#define mod 1000000000

#define vvi vector<vector<long long int> > 
#define vi vector<long long int>
//intializing ---- vvi res(k, vi(k,0))
#define rep(i,a,b) for(int i = a; i < b; i++)




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

int k;//size of matrices.

vvi matrix_mult(vvi a, vvi b){
	vvi res(k, vi(k, 0));
	
	#if 0
	rep(i,0,k)
		rep(j,0,k)
			cout << res[i][j];
	#endif


	rep(i,0,k){
		rep(j,0,k){
			rep(l,0,k){
				res[i][j]+= (a[i][l]*b[l][j])%mod;
				res[i][j]%= mod;
			}
		}
	}


	return res;
}

//compute a^n 'a' is a kxk matrix.
vvi matrix_pow(vvi a, int n){
	if(n == 1) return a;
	if(n%2){
		return matrix_mult(matrix_pow(a, n-1), a);
	}
	vvi ans = matrix_pow(a, n/2);
	return matrix_mult(ans,ans);
}

//make main matrix
vvi make_matrix(vi c){
	vvi res(k, vi(k,0));
	rep(i,0,k)
		res[0][i] = c[i];
	rep(i,1,k)
		res[i][i-1] = 1;
	return res;
}

lli ret_ans(vvi main_mat, vi base_mat, int n){
	if(n <= k)
		return base_mat[n-1];
	
	vvi final_mat = matrix_pow(main_mat, n-k);
	lli ans = 0;
	rep(i,0,k){
		ans+= (final_mat[0][i]*base_mat[k-1-i])%mod;
		ans%=mod;
	}
	return ans;
}

int main(){
	
	int t;
	cin >> t;
	
	while(t--){

		cin >> k;
		vi c(k,0);
		vi b(k,0);
		rep(i,0,k)
			cin >> b[i];
		rep(i,0,k)
			cin >> c[i];

		vvi main_mat = make_matrix(c);
		int n;
		cin >> n;
		lli ans = ret_ans(main_mat, b, n);
		cout << ans << endl; 
	}

	return 0;	
}