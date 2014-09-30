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
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;

int main(){

	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];

	if(n <= 3){
		cout << "no" << endl;
		return 0;

	}

	int l;
	int r;
	if(a[2] < min(a[0],a[1])){
		l = -inf;
		r = min(a[0],a[1]);
	}

	else if(a[2] > max(a[0],a[1])){
		l = max(a[0],a[1]);
		r = inf;
	}

	else{
		l = min(a[0],a[1]);
		r = max(a[0],a[1]);
	}

	for(int i = 2; i < n; i++){
		if(!(a[i] < r && a[i] > l)){
			cout << "yes" <<  endl;
			return 0;
		}

		if(i == n-1){
			cout << "no" << endl;
			return 0;
		}

		if(a[i+1] > a[i]){
			l = a[i];
		}
		else
			r = a[i];
	}


	return 0;	
}