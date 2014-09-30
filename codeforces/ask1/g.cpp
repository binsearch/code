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

int main(){

	freopen("robbers.in", "r", stdin); 
	freopen("robbers.out", "w", stdout);

	int n, m, y;

	int x[n];

	for(int i = 0; i < n; i++){
		cin >> x[i];
	}

	float frac[n];
	float rem_coins = 0;
	for(int i = 0; i <n; i++){
		frac[i] =	(((float) (x[i] * m)) / y) - ((x[i] * m) / y) 
		rem_coins+= frac[i];
	}

	sort(frac, frac+n);

	int cnt = rem_coins + 0.5;

	

	return 0;	
}