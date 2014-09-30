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

int main(){
	int lim = 1000001;
	int s[1000001] = {0};
	for(int i = 2; i*i < lim; i++){
		if(s[i] == 0){
			for(int j = i*i; j < lim ; j = j + i){
				s[j] = 1;
			}
		}
	}
	
	int t;
	inp(t);

	while(t--){
		lli l,r;
		cin >> l;
		cin >> r;
		int a[r-l+1];
		memset(a,0,sizeof a);
		int cnt = 0;
		for(lli i = 2; i < lim; i++){
			if(s[i] == 0){

				int k = 1;
				lli temp = i*i;
				while(temp <= r){
					k++;

					if(temp >= l) {
						if(s[k+1] == 0) cnt++;
					}

					temp = temp*i;
				}

				lli j;
				if(l%i == 0) j = l;
				else j = l + i - (l%i);

				for(j = max(j, i*i); j<= r; j+=i){
					a[j-l] = 1;
				}
			}
		}

		for(lli i = 0; i < r-l+1; i++){
			if(a[i] == 0 && i+l != 1) {
				cnt++;
			}
		}

		cout << cnt << endl;

	}

	return 0;	
}