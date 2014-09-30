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
string a,b;
int n;
int lps[1000010];

int comp_lps(int i){
	int j = i;
	while(1){
		if(a[lps[j-1]] ==a[i]) return lps[j-1]+1;
		if(lps[j-1] == 0) return 0;
		j = lps[j-1];
	}
}


int main(){
	cin  >> n;
	cin >> a >> b;

	int max_len = 0;
	int temp_len = 0;
	int max_ind = 0;
	int temp_ind = 0;
	int a_i = 0;
	int b_i = 0;

	lps[0] = 0;
	for(int i = 1; i < n; i++)
		comp_lps(i);


	while(a_i < n){
		if(max_len < temp_len){
			max_len = temp_len;
			max_ind = temp_ind;
		}
		if(temp_ind >= n) break;
		if(a[a_i] == b[b_i % n]){
			a_i++;
			b_i++;
			temp_len++;
		}

		else{
			if(a_i == 0){ 
				b_i++;
				temp_ind = b_i;
				temp_len = 0;
			}
			else{
				a_i = lps[a_i-1];
				temp_ind = temp_ind + a_i - lps[a_i-1];
				temp_len = lps[a_i-1];
			}
		}
	}

	cout << max_ind << endl;



	return 0;	
}