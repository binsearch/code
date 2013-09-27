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
map<string,int> dp;

int recurse(int flag, int in1, int in2){

	stringstream ss;
	ss << flag;
	ss << " ";
	ss << in1;
	ss << " ";
	ss << in2;	
	string quer = ss.str();
	//cout << quer << endl;
	if(dp.find(quer) != dp.end())
		return dp.find(quer)->second;
	if(flag == 0){
		if(s1.size() - in1 < k || s2.size() - in2 < k){
			dp[quer] = 0;
			return 0;
		}
		int ta,tb,tc;
		ta = -1;
		if(s1.substr(in1,k) == s2.substr(in2,k)){
			ta = k+recurse(1,in1+k,in2+k);
		}
		tb = recurse(0,in1,in2+1);
		tc = recurse(0,in1+1,in2);
		dp[quer] = max(ta,max(tb,tc));
		return max(ta,max(tb,tc));
	}
	if(flag == 1){
		if(in1 >= s1.size() || in2 >= s2.size()){
			dp[quer] = 0;
			return 0;
		}
		int ta,tb,tc;
		ta = -1;
		if(s1[in1] == s2[in2]){
			ta = 1+recurse(1,in1+1,in2+1);
		}

		tb = recurse(0,in1+1,in2);
		tc = recurse(0,in1,in2+1);
		dp[quer] = max(ta,max(tb,tc));
		return max(ta,max(tb,tc));

	}

}

int main(){



	while(1){
		
		inp(k);
		if(k == 0)
			break;
		
		cin >> s1 >> s2;
		dp.clear();

		int ans = recurse(0,0,0);
		cout << ans << endl;
	}


	return 0;	
}