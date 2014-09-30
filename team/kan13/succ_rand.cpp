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

int a[1050000];


int main(){

	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		memset(a,0,sizeof a);
		int len = s.size();
		int k = 0;
		while(len != 1){
			if(len %2 != 0){ k = -1; break;}
			len = len / 2;
			k++;
		}
		if(k == -1 || k == 0) cout << "INVALID" << endl;
		else{
			int tab = 0;
			for(int i = 0; i < k; i++){
				if(s[i] == '0') tab = tab*2;
				else tab = tab * 2 + 1;
			}
			a[tab] = 1;
			for (int i = 1; i < s.size(); ++i)
			{
				if(s[i-1] == '1') tab = tab - s.size()/2;
				tab = tab * 2 + (s[(i+k-1)%s.size()] == '1');
				if(a[tab] == 1){
					tab = -1;
					break;
				}
				a[tab] = 1;
			}
			if(tab == -1) cout << "INVALID" << endl;
			else cout << "VALID" << endl;
		}
	}

	return 0;	
}