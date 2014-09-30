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


double mypow(double i, int p){
	if(p == 1) return i;
	if(p%2 == 0){
		double ans = mypow(i, p/2);
		return ans*ans;
	}

	return mypow(i,p-1) * i;
}

int main(){

	int m,n;
	cin >> m >> n;

	double ans = m;

	for(int i = m -1 ; i >= 1; i--){
		ans-= mypow(((double) (i))/m, n);
	}

	cout << ans << endl;

	return 0;	
}