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
typedef long long int lli;
using namespace std;
typedef pair<int, int> ii;
int g[1001][1001];
inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
	n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}
int n;
priority_queue<ii> desc;
int visit[1001];
int timer;
int scc[1001];
void dfs(int v){
	visit[v] = 1;
	for(int i = 1; i <= n; i++){
		if(g[v][i] == 1 && visit[i] == 0){
			dfs(i);
		}
	}

	timer++;
	desc.push(ii(timer,v));
}

void redfs(int v, int c){
	scc[v] = c;
	visit[v] = 1;
	for(int i = 1; i <= n; i++){
		if(g[i][v] == 1 && visit[i] == 0){
			redfs(i,c);
		}
	}
}

int main(){

	int t;
	inp(t);
	while(t--){
		memset(g,0, sizeof g);
		memset(visit,0, sizeof visit);
		inp(n);
		for(int i = 1; i <= n; i++){
			int nv;
			inp(nv);
			for(int j = 0; j < nv; j++){
				int neigh;
				inp(neigh);
				g[neigh][i] = 1;
			}
		}
		
		while(!desc.empty())
			desc.pop();
		
		timer = 0;
		
		for(int i = 1; i <= n; i++){
			if(visit[i] == 0)
				dfs(i);
		}

		memset(scc,0,sizeof scc);
		memset(visit,0,sizeof visit);
		int count = 0;
		while(!desc.empty()){
			int i = (desc.top()).second;
			desc.pop();
			if(visit[i] == 0){
				count++;
				redfs(i, count);
			}
		}

		int inedge[1001];
		memset(inedge,0,sizeof inedge);
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(g[i][j] == 1 && scc[i] != scc[j]){
					inedge[scc[j]] = 1;
				}
			}
		}
		// for(int i = 1; i <= n; i++)
		// 	cout << scc[i] << endl;
		int zin = 0;
		int cone;
		for(int i = 1; i <= count; i++){
			if(inedge[i] == 0){
				zin++;
				cone = i;
			}
		}

		if(zin == 1){
			int setpl = 0;
			for(int i = 1; i <= n; i++){
				if(scc[i] == cone){
					setpl++;
				}
			}
			printf("%d\n", setpl);
		}
		else{
			printf("0\n");
		}

	}

	return 0;	
}