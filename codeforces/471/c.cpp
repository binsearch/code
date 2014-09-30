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
#define mod 1000000007
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;

int main(){

	lli n;
	cin >> n;
	int cnt = 0;

	for(lli i = 1; (i * (3*i+1)) / 2 <= n; i++){
		if((n -  (i * (3*i+1))/2 ) % 3 == 0)
			cnt++;
	}

	cout << cnt << endl;
	return 0;
}