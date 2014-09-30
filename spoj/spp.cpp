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
// #define mod 1000000000

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
lli mod;

vvi matrix_mult(vvi a, vvi b){
	vvi res(k+1, vi(k+1, 0));
	
	#if 0
	rep(i,0,k)
		rep(j,0,k)
			cout << res[i][j];
	#endif


	rep(i,0,k+1){
		rep(j,0,k+1){
			rep(l,0,k+1){
				res[i][j]+= (a[i][l]*b[l][j])%mod;
				res[i][j]%= mod;
			}
		}
	}


	return res;
}

//compute a^n 'a' is a kxk matrix.
vvi matrix_pow(vvi a, lli n){
	if(n == 1) return a;
	if(n%2){
		return matrix_mult(matrix_pow(a, n-1), a);
	}
	vvi ans = matrix_pow(a, n/2);
	return matrix_mult(ans,ans);
}

//make main matrix
vvi make_matrix(vi c){
	vvi res(k+1, vi(k+1,0));
	res[0][0] = 1;
	rep(i,0,k){
		res[0][i+1] = c[i];
		res[1][i+1] = c[i];
	}
	rep(i,1,k)
		res[i+1][i] = 1;
	return res;
}

lli ret_ans(vvi main_mat, vi base_mat, lli n){
	if(n <= k){
		lli ans = 0;
		rep(i,0,n){
			ans+= base_mat[i]%mod;
			ans%= mod;
		}
		return ans;
	}
	
	vvi final_mat = matrix_pow(main_mat, n-k);
	lli ans = 0;
	rep(i,1,k+1){
		ans+= (final_mat[0][i]*base_mat[k-i])%mod;
		ans%=mod;
	}
	ans+= (final_mat[0][0] * ret_ans(main_mat, base_mat, k))%mod;
	ans%= mod;
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
		lli m,n;
		cin >> m >> n >> mod;
		lli ans = ret_ans(main_mat, b, n);
		ans-= ret_ans(main_mat,b,m-1);
		ans%=mod;
		if(ans < 0) ans+=mod;
		cout << ans << endl; 
	}

	return 0;	
}