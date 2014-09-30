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
	int a[100001];
	a[0] = 0;
	lli cnt = 0;
	for(lli i = 1; i <= 100000; i++){
		lli temp = i*i;
		int flag = 0;
		while(temp != 0){
			if(temp%10 != 0 && temp%10 != 1 && temp%10 !=4 && temp%10 != 9){
				flag = 1;
				break;
			}
			temp = temp/10;
		}
		if(flag == 0) cnt++;
		a[i] = cnt;
	}

	while(t--){
		lli a1,b1;
		cin >> a1;
		cin >> b1;
		int ans;
		lli r = sqrt(b1)+0.5;
		if(r*r == b1){
			ans = a[r];
		}
		else{
			r = sqrt(b1);
			ans = a[r];
		}
		r = sqrt(a1)+0.5;
		if(r*r != a1){
			r = sqrt(a1);
		}
		else{
			r--;
		}
		ans = ans - a[r];
		cout << ans << endl;
	}

	return 0;	
}