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
bool myfunction (int i,int j) { return (i>j); }
int a_bit[300010][35];
int a[300010];
int n;
int first_one(int x){
	int j = 0;
	while(x != 0){
		x = x >> 1;
		j++;
	}
	return j-1;
}
void find_pos(){
	// cout << "find_pos" << endl;
	for(int i = 0; i < n; i++){
		int temp = a[i];
		int j = 0;
		while(temp != 0){
			a_bit[i][j] = first_one(temp);
			// cout << a_bit[i][j] << endl;
			temp = temp - (1 << a_bit[i][j]);
			j++;
		}
	}
}
pii crux(int x, int y, int pos){
	int flag = 0;
	int prev = a_bit[x][pos];
	int start,end;
	for(int i = x+1; i <= y; i++){
		// cout << a_bit[i][pos] << " " << prev << endl;
		if((a_bit[i][pos] == prev) && (prev != -1)){
			// cout << "match" << endl;
			if(flag == 0){
				start = i-1;
				flag = 1;
				end = i;
			}
			else{
				end++;
			}
		}
		else if((a_bit[i][pos] != prev) && flag == 1) break; 
		prev = a_bit[i][pos];
	}
	if(flag == 1) return pii(start, end);
	return pii(0,0);
}

int main(){
	memset(a_bit, -1, sizeof a_bit);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a+n, myfunction);
	find_pos();
	int start = 0,end = n-1;
	int pos = 0;
	while(1){
		// cout << "main while" << endl;
		if(start == end - 1) break;
		pii range = crux(start,end,pos);
		// cout << range.first << " " << range.second << endl;
		if(range == pii(0,0)) break;
		start = range.first;
		end = range.second;
		pos++;
	}

	cout << (a[start] & a[start+1]) << endl;

	return 0;	
}