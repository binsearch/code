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

	int n;
	int a[100010];

	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];

	int dip_in = -1;
	int flag = 0;

	for(int i = 0; i < n-1; i++){
		if(a[i] > a[i+1]){
			if(flag == 1) {
				flag = 2;
				break;
			}
			else{
				flag = 1;
				dip_in = i+1;
			}
		}
	}

	if(flag == 2) cout << -1 << endl;
	if(flag == 0) cout << 0 << endl;
	if(flag == 1){
		if(a[n-1] <= a[0])
			cout << n - dip_in << endl;
		else 
			cout << -1 << endl;
	}

	return 0;	
}