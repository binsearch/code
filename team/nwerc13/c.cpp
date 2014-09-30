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
typedef long long int lli;
typedef pair<int,int> pii;
double dp[1200][1200];
int s[1200][1200];
int pos[1200];
int val[] = {2,3,4,5,6,7,8,9,10,10,10,10,11};
double prob(int a, int b){
	if(a > b) return 0;
	if(a == b) return 1.0;
	if(s[a][b] != -1) return dp[a][b];
	double ans = 0;
	if(pos[a] != 0){
		dp[a][b] = prob(a+pos[a],b);
		s[a][b] = 1;
		return dp[a][b];
	}
	for(int i = 0; i < 13; i++){
		ans+= (1.0/13.0) * prob(a+val[i],b);		
	}
	dp[a][b] = ans;
	s[a][b] = 1;
	return ans;
}


int main(){

	double ans;
	int n,m;
	int c[110];
	while(scanf("%d %d",&n,&m) != EOF){
		memset(s, -1, sizeof s);
		memset(pos, 0, sizeof pos);
		ans = 0;
		int cumm = m;
		for(int i = 0; i < n; i++){

			string t;
			cin >> t;
			if(t == "2") c[i] = 2;
			if(t == "3") c[i] = 3;
			if(t == "4") c[i] = 4;
			if(t == "5") c[i] = 5;
			if(t == "6") c[i] = 6;
			if(t == "7") c[i] = 7;
			if(t == "8") c[i] = 8;
			if(t == "9") c[i] = 9;
			if(t == "10") c[i] = 10;
			if(t == "J") c[i] = 10;
			if(t == "Q") c[i] = 10;
			if(t == "K") c[i] = 10;
			if(t == "A") c[i] = 11;
			pos[cumm] = c[i];
			cumm+= c[i];
		}
		cumm-= c[n-1];
		for(int i = 1; i <= 10; i++){
			ans+= (1/10.0) * prob(i, cumm);
		}
		printf("%.11f\n", ans);
	}	


	return 0;	
}














