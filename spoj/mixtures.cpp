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

int main(){


	int n;
	while(!(std::cin >> n).eof()) {
		// int n;
		// inp(n);
		int mix[100];
		for(int j = 0; j < n; j++)
			inp(mix[j]);
		int sm[100][100] = {0};
		int co[100][100];
		for(int j = 0; j < n; j++){
			co[j][j] = mix[j];

		}
		for(int len = 2; len <= n; len++){
			for(int j = 0; j < n-len+1; j++){
				int tco = mix[j];
				int tsmo = -1;
				for(int k = 1; k < len; k++){
					tco = (tco + mix[j+k])%100;
					int temp = sm[j][j+k-1]+sm[j+k][j+len-1] + co[j][j+k-1]*co[j+k][j+len-1];
					if(tsmo == -1)
						tsmo = temp;
					if(temp < tsmo){
						tsmo = temp;
					}

				}
				sm[j][j+len-1] = tsmo;
				co[j][j+len-1] = tco;
			}
		}

		cout << sm[0][n-1] << endl;

	}

	return 0;	
}