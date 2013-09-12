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
using namespace std;

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

	
	vector< vector<int> > grid;
	int n,m;
	std::vector<int> crap;
	inp(n);
	grid.assign(n,crap);
	inp(m);
	for(int i = 0; i < m; i++){
		int x,y;
		inp(x);
		inp(y);
		grid[x-1].push_back(y-1);
		grid[y-1].push_back(x-1);
	}

	int cost[100005];
	for(int i = 0; i < n; i++){
		int temp;
		inp(temp);
		cost[i] = temp;
	}
	//bfs
	queue<int> dfs;
	//cout << "before dfs" << endl;
	int ccomp[100005] = {0};
	int count = 1;
	for(int i = 0; i < n; i++){
		if(ccomp[i] == 0){
			dfs.push(i);
			while(!dfs.empty()){
				int root = dfs.front();
				ccomp[root] = count;
				dfs.pop();
				for(int j = 0; j < grid[i].size(); j++){
					if(ccomp[grid[i][j]] == 0)
						dfs.push(grid[i][j]);
				}
			}
			count++;
		}
		
	}	
	//cout << "after dfs" << endl;
	// for(int i = 0; i < n; i++)
	// 	cout << ccomp[i] << endl;

	int min[100005];
	for (int i = 0; i < count+2; ++i)
	{
		min[i] = 1000000;
	}

	for(int i = 0; i < n; i++){
		int inde = ccomp[i];
		if(min[inde] > cost[i]){
			min[inde] = cost[i];
			//cout << min[inde] << endl;
		}
	}

	sort(min+1,min+count);
	if(min[1] < 0)
		cout << -1 << endl;
	else{
		long long int answer = 0;
		for(int i = 2; i < count; i++){
			answer+= min[i];
		}
		answer = answer + min[1]*(count-2);
		cout << answer << endl;
	}

	return 0;
}