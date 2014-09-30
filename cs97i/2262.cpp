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
#define mil 1000000
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
	while( ch >= '0' && ch <= '9' )
	n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
	n=n*sign;
}

int main(){

	int p[mil+1] = {0};

	for(int i = 2; i < 1001; i++){
		if(p[i] == 0){
			for(int j = i; i*j <= mil; j++){
				p[i*j] = 1;
			}
		}
	}
	
	while(1){
		int n;
		inp(n);
		if(n == 0) break;
		int i;
		for(i = n-3; i > 2; i--){
			if(p[i] == 0 && p[n-i] == 0) break;
		}
		cout << n << " = " << n-i << " + " << i << endl;
	}

	return 0;	
}