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

	int p,q,l,r;

	pii z[60];
	pii x[60];

	cin >> p >> q >> l >> r;
	for (int i = 0; i < p; ++i)
	{
		int li,ri;
		cin >> li >> ri;
		z[i] = pii(li,ri);
	}

	for (int i = 0; i < q; ++i)
	{
		int li,ri;
		cin >> li >> ri;
		x[i] = pii(li,ri);
	}


	int cnt = 0;

	for(int i = l; i <= r; i++){
		int flag = 0;
		for(int j = 0; j < q; j++){
			for(int k = 0; k < p; k++){
				if((x[j].first+i >= z[k].first && x[j].first+i <= z[k].second) || (x[j].second+i >= z[k].first && x[j].second+i <= z[k].second) || (x[j].first + i <= z[k].first && x[j].second + i >= z[k].second))
					flag = 1;
			}
		}

		if(flag) cnt++;
	}

	cout << cnt << endl;

	return 0;	
}