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
#define inf 1e15
using namespace std;
typedef long long int lli;
typedef pair<long long int,int> ii;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
	n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

vector<int> g[10010];
std::vector<int> c[10010];
long long int cost[10010];
int f[10010];
int nc;
map <string, int> names;

long long int primmst(int v1){
	// cout << v1 << " " << v2 << endl;
	priority_queue<ii> cloud;
	

	for(int i = 0; i <= nc; i++){
		cost[i] = inf;
		f[i] = 0;
	}
	cost[v1] = 0;
	cloud.push(ii(0,v1));
	int count = 0;
	long long int mcost = 0;
	while(1){

		int tcost = (cloud.top()).first;
		int next = (cloud.top()).second;
		cloud.pop();

		if(f[next] == 0){
			// cout << next << endl;
			mcost+= tcost;
			for(int i = 0; i < g[next].size(); i++){
				int tv = g[next][i];
				// cout << tv << endl;
				if(cost[tv] > c[next][i]){
					cost[tv] = c[next][i];
					cloud.push(ii(-cost[tv],tv));
				}
			}
			f[next] = 1;
			count++;
		}
		if(count == nc)
			break;
	}

	return -mcost;	

}


int main(){

	int t;
	inp(t);
	while(t--){
		
		names.clear();

		
		inp(nc);
		for(int i = 0; i < nc ; i++){

			string name;
			cin >> name;
			names[name] = i+1;
			int neigh;
			inp(neigh);
			std::vector<int> neighs;
			std::vector<int> ecost;
			for(int j = 0; j < neigh; j++){
				int nr,ncost;
				inp(nr);
				inp(ncost);
				neighs.push_back(nr);
				ecost.push_back(ncost);

			} 
			g[i+1] = neighs;
			c[i+1] = ecost;
		}

		printf("%lld\n", primmst(1));
	}

	return 0;	
}
