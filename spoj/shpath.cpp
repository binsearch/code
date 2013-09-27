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
#define inf 200010
using namespace std;
typedef long long int lli;
typedef pair<int,int> ii;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
	n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

std::vector<vector<int> > g;
std::vector<std::vector<int> > c;
set<ii> cloud;
int cost[10010];
map <ii, int> dp;
map <string, int> names;

int dijkstra(int v1, int v2){
	// cout << v1 << " " << v2 << endl;
	if(dp.find(ii(v1,v2)) != dp.end()){ 
		return (dp.find(ii(v1,v2)))->second;
	}

	if(dp.find(ii(v2,v1)) != dp.end()){
		return (dp.find(ii(v2,v1)))->second;
	}

	cloud.clear();
	for(int i = 0; i < 10010; i++){
		cost[i] = inf;
	}
	cost[v1] = 0;
	cloud.insert(ii(0,v1));
	while(1){


		int next = (cloud.begin())->second;
		// cout << next << endl;
		cloud.erase(cloud.begin());
		dp[ii(next,v1)] = (cloud.begin())->first;
		if(next == v2){
			break;
		} 
		for(int i = 0; i < g[next-1].size(); i++){
			int tv = g[next-1][i];
			// cout << "i " << i << endl;
			if(cost[tv] > cost[next] + c[next-1][i]){
				cloud.erase(ii(cost[tv],tv));			
				cost[tv] = cost[next] + c[next-1][i];
				cloud.insert(ii(cost[tv],tv));
			}
		}
	}

	return cost[v2];	

}


int main(){

	int t;
	inp(t);
	while(t--){
		
		dp.clear();	
		g.clear();
		c.clear();
		names.clear();

		int nc;
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
			g.push_back(neighs);
			c.push_back(ecost);
		}

		int paths;
		inp(paths);
		while(paths--){
			string name1,name2;
			cin >> name1;
			cin >> name2;
			int cost = dijkstra(names.find(name1)->second, names.find(name2)->second);
			printf("%d\n", cost);
		}
	}

	return 0;	
}