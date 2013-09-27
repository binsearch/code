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
#define inf 200010
#define e 1e-9
using namespace std;
typedef long long int lli;
typedef pair<double,int> ii;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
	n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

double g[101][101];
set<ii> cloud;
double cost[101];
int n;
int f[101];
double dijkstra(int v1, int v2){
	//cout << v1 << " " << v2 << endl;
	for(int i = 0; i < 101; i++){
		cost[i] = 0.0;
		f[i]= 0;
	}

	priority_queue<ii> cloud;
	

	cost[v1] = 100.0;
	cloud.push(ii(100.0,v1));

	while(1){


		int next = (cloud.top()).second;
		cloud.pop();

		if(f[next] == 0){
		// cout << next << endl;
			f[next] = 1;
			if(next == v2){
				break;
			} 
			for(int i = 0; i <= n; i++){

				if(cost[i] < cost[next]*g[next][i]/100.0){
					cost[i] = cost[next]*g[next][i]/100.0;
					cloud.push(ii(cost[i],i));
				}
			}

		}
	}

	return cost[v2];	


	return cost[v2];	

}


int main(){

	while(1){
		int m;
		inp(n);
		
		if(n == 0)
			break;
		memset(g,0,sizeof g);
		inp(m);
		while(m--){
			int ui,vi;
			double pi;
			inp(ui);
			inp(vi);
			scanf("%lf",&pi);
			g[ui][vi] = pi;
			g[vi][ui] = pi;
		}
		for(int i = 1; i <= n; i++){
			g[i][i] = 100.0;
		}
		printf("%.6f percent\n", dijkstra(1,n));

	}
	return 0;	
}