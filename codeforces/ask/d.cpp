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
#define vvi vector<vector<int> > 
#define vi vector<int>


int main(){
	freopen("matrix.in", "r", stdin); 
	freopen("matrix.out", "w", stdout);
	int n,m;
	cin >> n >> m;
	int a[10010] = {0};
	for(int i = 0; i < m; i++){
		int v1,v2;
		cin >> v1 >> v2;
		a[v1]++;
		a[v2]++;
	}

	lli ans = (lli) (2 * m);
	for(int i = 1; i <= n; i++){
		ans+= (lli) (a[i] * (a[i]-1));
	}

	cout << ans  << endl;

	return 0;	
}