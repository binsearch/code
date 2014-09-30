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

bool myfunction (int i,int j) { return (i>j); }

int main(){

	int n;
	pii r[2010];
	int cnt[2010] = {0};
	cin >> n;
	int a = 0;
	int b = 0;
	int c = 0;
	for(int i = 0; i < n; i++){
		int t;
		cin >> t;
		r[i] = pii(t,i);
		cnt[t]++;
		if(cnt[t] >= 3) a = t;
		if(cnt[t] == 2 && b == 0) b = t;
		else if(cnt[t] == 2 && t != b) c = t;
	}

	sort(r, r+n);

	int ord[3][2010];

	if(a != 0){	
		// cout << "3" << endl;
		int flag = 0;
		for(int i = 0; i < n; i++){
			if(r[i].first == a && flag == 0){
				ord[0][i] = r[i].second;
				ord[0][i+1] = r[i+1].second;
				ord[0][i+2] = r[i+2].second;

				ord[1][i] = r[i+1].second;
				ord[1][i+1] = r[i].second;
				ord[1][i+2] = r[i+2].second;

				ord[2][i] = r[i+2].second;
				ord[2][i+1] = r[i+1].second;
				ord[2][i+2] = r[i].second;
				i+=2;
				flag = 1;
			}
			else{
				ord[0][i] = r[i].second;
				ord[1][i] = r[i].second;
				ord[2][i] = r[i].second;

			}
		}
	cout << "YES" << endl;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << ord[i][j]+1 << " ";
		}
		cout << endl;
	}

	}

	else if(b != 0 && c != 0){
		// cout << b << " " << c  << endl;
		int flag1 = 0;
		int flag2 = 0;
		for (int i = 0; i < n; ++i)
		{
		if(r[i].first == c && flag1 == 0){
			ord[0][i] = r[i].second;
			ord[0][i+1] = r[i+1].second;
			
			ord[1][i] = r[i].second;
			ord[1][i+1] = r[i+1].second;

			ord[2][i] = r[i+1].second;
			ord[2][i+1] = r[i].second;
			i++;
			flag1 = 1;
		}

		else if(r[i].first == b && flag2 == 0){
			ord[0][i] = r[i+1].second;
			ord[0][i+1] = r[i].second;
			
			ord[1][i] = r[i].second;
			ord[1][i+1] = r[i+1].second;

			ord[2][i] = r[i+1].second;
			ord[2][i+1] = r[i].second;
			i++;
			flag2 = 1;
		}

		else{
			ord[0][i] = r[i].second;
			ord[1][i] = r[i].second;
			ord[2][i] = r[i].second;

		}

	}
	cout << "YES" << endl;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << ord[i][j]+1 << " ";
		}
		cout << endl;
	}
	

	}

	else{
		cout << "NO" << endl;
	}

	return 0;
}