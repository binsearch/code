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
#define mod 1000000007
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
long long int dp[5010] = {-1};
string s;
long long int recurse(int i){
    if(dp[i] != -1) {
    	// cout << "dp" << endl; 
    	return dp[i];
  	}
    if(i == s.size()) return 1;
    if(s[i] == '0') return 0;
    if(i == (s.size() -1)) return 1;
    if((s[i] == '1') || (s[i] == '2' && s[i+1] < '7')) {
    	// cout << "2 case" << endl;
    	dp[i] = recurse(i+1) + recurse(i+2);
    } 
    else dp[i] = recurse(i+1);
    return dp[i];
}
int main(){
    while(1){
        cin >> s;
        memset(dp, -1, sizeof dp);
        if(s == "0") break;
        long long int ans = recurse(0);
        cout << ans << endl;
    }
	return 0;	
}
