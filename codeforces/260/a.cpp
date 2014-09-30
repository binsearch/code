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

int main(){

	int n;
	pii a[100010];
	cin >> n;
	for(int i = 0; i < n; i++){
		int ta,tb;
		cin >> ta >> tb;
		a[i] = pii(ta,tb);
	}

	sort(a, a+n);

	int flag = 0;

	for(int i = 0; i < n -1 ; i++){
		if(a[i].second > a[i+1].second){
			flag = 1;
			break;
		}
	}

	if(flag) cout << "Happy Alex" << endl;
	else cout << "Poor Alex" << endl;

	return 0;	
}