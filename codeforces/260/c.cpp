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

lli n;
lli a[100010];
lli dp[100010];

int main(){
	
	cin >> n;

	memset(a, 0, sizeof a);
	memset(dp, 0, sizeof dp);
	lli nmax = 0;

	for(int i = 0; i < n; i++){
		lli temp; 
		cin >> temp;
		a[temp]++;
		if(temp > nmax) nmax = temp;
	}

	dp[1] = a[1];
	dp[0] = 0;

	for(int i = 2; i <= nmax; i++){
		dp[i] = max(a[i]*i + dp[i-2], dp[i-1]);
	}

	cout << dp[nmax] << endl;


	return 0;
}