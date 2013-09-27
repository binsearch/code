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
typedef long long int lli;
using namespace std;
inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
	n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

string s1;
string s2;
int k;
int dp[2][1001][1001];
int sub[1001][1001];

// int recurse(int flag, int in1, int in2){

// 	if(dp[flag][in1][in2] != -1)
// 		return dp[flag][in1][in2];
// 	if(flag == 0){
// 		if(s1.size() - in1 < k || s2.size() - in2 < k){
// 			dp[flag][in1][in2] = 0;
// 			return dp[flag][in1][in2];
// 		}
// 		int ta,tb,tc;
// 		ta = -1;
// 		if(sub[in1][in2] >= k){
// 			ta = k+recurse(1,in1+k,in2+k);
// 		}
// 		tb = recurse(0,in1,in2+1);
// 		tc = recurse(0,in1+1,in2);
// 		dp[flag][in1][in2] = max(ta,max(tb,tc));
// 		return dp[flag][in1][in2];
// 	}
// 	if(flag == 1){
// 		if(in1 >= s1.size() || in2 >= s2.size()){
// 			dp[flag][in1][in2] = 0;
// 			return dp[flag][in1][in2];
// 		}
// 		int ta,tb,tc;
// 		ta = -1;
// 		if(s1[in1] == s2[in2]){
// 			ta = 1+recurse(1,in1+1,in2+1);
// 		}

// 		tb = recurse(0,in1+1,in2);
// 		tc = recurse(0,in1,in2+1);
// 		dp[flag][in1][in2] = max(ta,max(tb,tc));
// 		return dp[flag][in1][in2];

// 	}

// }

int main(){



	while(1){
		
		inp(k);
		if(k == 0)
			break;
		
		cin >> s1 >> s2;

		if(k > s1.size() || k > s2.size()){
			cout << 0 << endl;
			continue;
		}
		int i1 = s1.size();
		int j1;
		for(j1 = 0; j1 <= s2.size(); j1++){
			dp[1][i1][j1] = 0;
			dp[0][i1][j1] = 0;
			sub[i1][j1] = 0;
		}
		j1 = s2.size();
		for(i1 = 0; i1 <= s1.size(); i1++){
			dp[1][i1][j1] = 0;
			dp[0][i1][j1] = 0;
			sub[i1][j1] = 0;
		}
		


		for(int i = s1.size()-1; i >= 0; i--){
			for(int j = s2.size()-1; j>= 0; j--){
				if(s1[i] == s2[j]){

					sub[i][j] = 1+sub[i+1][j+1];

				}
				else{
					sub[i][j] = 0;
				}
				//cout<<sub[i][j]<<" ";
			}
			//cout<<endl;
		}

		for(int i = s1.size()-1; i >= 0; i--){
			for(int j = s2.size()-1; j >= 0; j--){
				if(sub[i][j] >= k){
					dp[0][i][j] = max(k+dp[1][i+k][j+k],max(dp[0][i][j+1],dp[0][i+1][j]));

				}
				else{
					dp[0][i][j] = max(dp[0][i][j+1],dp[0][i+1][j]);
				}

				if(sub[i][j] != 0){
					dp[1][i][j] = max(1+dp[1][i+1][j+1],max(dp[0][i][j+1],dp[0][i+1][j]));
				}
				else{
					dp[1][i][j] = max(dp[0][i][j+1],dp[0][i+1][j]);
				}
			}
		}



		int ans = dp[0][0][0];
		cout << ans << endl;
	}


	return 0;	
}