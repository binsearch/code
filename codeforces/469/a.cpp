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
	int a[110];
	a[0] = 1;

	int n;
	cin >> n;
	int p;
	cin >> p;
	for(int i = 0; i < p; i++){
		int t;
		cin >> t;
		a[t] = 1;
	}

	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		int t;
		cin >> t;
		a[t] = 1;
	}
	int flag = 1;
	for(int i = 1; i <= n; i++){
		if(a[i] != 1) flag = 0;
	}

	if(flag) cout << "I become the guy." << endl;
	else cout << "Oh, my keyboard!" << endl;


	return 0;	
}