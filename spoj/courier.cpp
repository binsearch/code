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
#define inf 100000000
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

int graph[101][101];
map<std::vector<int> , long long int> dp;
int src[5];
int dst[5];
int ncour[5];
int cc;
long long int recurse(std::vector<int> state){
	
	// for(int i = 0; i < 6; i++){
	// 	cout << state[i] << " ";
	// }
	// cout << endl;

	if(dp.find(state) != dp.end()){
		return dp.find(state)->second;
	}

	std::vector<long long int> mins;
	int start = state[5];
	for(int i = 0; i < 5; i++){
		if(state[i] != 0){
			std::vector<int> nstate;
			nstate = state;
			nstate[i]--;
			nstate[5] = dst[i];
			mins.push_back(graph[start][src[i]] + graph[src[i]][dst[i]] + recurse(nstate) );
		}
	}
	if(mins.empty())
		return graph[state[5]][cc];
	sort(mins.begin(),mins.end());

	dp[state] = mins[0];
	return mins[0];
}

int main(){

	int t;
	inp(t);
	while(t--){
		int nc, nr;
		inp(nc);
		inp(nr);
		inp(cc);
		for(int i = 0; i <= nc; i++){
			for(int j = 0; j <= nc; j++){
				graph[i][j] = inf;
			}
		}
		for(int i = 0; i <= nc; i++)
			graph[i][i] = 0;
		while(nr--){
			int ui,vi,di;
			inp(ui);
			inp(vi);
			inp(di);
			graph[ui][vi] = di;
			graph[vi][ui] = di;
		}

		for (int k = 1; k <= nc; k++){
			for (int i = 1; i <= nc; i++){
		  		for (int j = 1; j <= nc; j++){
		   			graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
		  		}
		  	}
		}
		int z;
		inp(z);
		memset(ncour,0,sizeof ncour);
		std::vector<int> temp;
		temp.assign(6,0);
		for(int i = 0; i < z; i++){
			inp(src[i]);
			inp(dst[i]);
			inp(temp[i]);
		}
		temp[5] = cc;
		dp.clear();

		long long int ans = recurse(temp);
		printf("%lld\n", ans);

	}

	return 0;	
}