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

	int n;
	inp(n);
	int px,py,mx,my;
	char g[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> g[i][j];
			if(g[i][j] == 'p'){px = i; py = j;}
			if(g[i][j] == 'm'){mx = i; my = j;}
		}
	}

	int dx,dy;
	dx = px - mx;
	dy = py - my;
	if(dx > 0){
		for(int i = 0; i < dx; i++){
			cout << "DOWN" << endl;
		}
	}
	else{
		dx = -dx;
		for(int i = 0; i < dx; i++){
			cout << "UP" << endl;
		}
	}

	if(dy > 0){
		for(int i = 0; i < dy; i++){
			cout << "RIGHT" << endl;
		}
	}
	else{
		dy = -dy;
		for(int i = 0; i < dy; i++){
			cout << "LEFT" << endl;
		}
	}



	return 0;	
}