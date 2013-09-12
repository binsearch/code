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
	int t;
	inp(t);
	for(int i = 0; i < t; i++){
		int n;
		inp(n);
		
		int p[50];
		int a[50];
		int b[50];
		int tot;
		tot = 1;

		for(int i = 0; i < n; i++){
			inp(p[i]);
			inp(a[i]);
			inp(b[i]);
			tot = tot*2;
		}
		double prob = 0;

		if(n > 16){
			cout << 0 << endl;
			continue;
		}

		
		for(int i = 0; i < tot; i++){
			double tempprob = 1;
			int flag[17] = {0};
			for(int j = 0; j < n; j++){
				int bi = i & (1 << j);
				// bi >> j;
				if(bi != 0){
					if(flag[a[j]] == 1){
						tempprob = 0;
						break;
					}

					tempprob = tempprob*p[j]/100.0;
					flag[a[j]] = 1;

				}

				if(bi == 0){
					if(flag[b[j]] == 1){
						tempprob = 0;
						break;
					}

					tempprob = tempprob*(100-p[j])/100.0;
					flag[b[j]] = 1;

				}
				// cout << tempprob << " " ;

			}
			// cout << endl;
			prob = prob + tempprob;
		}
		cout << prob << endl;


	}


	
}