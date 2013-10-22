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
inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
	n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int main(){

	int t;
	inp(t);

	while(t--){
		stack<char> s;
		int n;
		inp(n);
		string in;
		cin >> in;
		s.push(in[0]);
		int si = 1;
		lli ans = 0;
		for(int i = 1; i < n; i++){
			if(in[i] == '7' && s.top() == '4'){
				s.pop();
				ans = ans + si;
				si--;
			}
			else {
				s.push(in[i]);
				si++;
			}
		}



		cout << ans << endl;
	}

	return 0;	
}