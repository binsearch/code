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

int n_n[2];
int h[2][200010];

int kmp() {
  int m = n_n[1]-1;
  int ans = 0;
  vector<int> border(m + 1);
  border[0] = -1;
  for (int i = 0; i < m; ++i) {
    border[i+1] = border[i];
    while (border[i+1] > -1 and h[1][border[i+1]] != h[1][i]) {
      border[i+1] = border[border[i+1]];
    }
    border[i+1]++;
  }
 	
  int n = n_n[0]-1;
  int seen = 0;
  for (int i = 0; i < n; ++i){
    while (seen > -1 and h[1][seen] != h[0][i]) {
      seen = border[seen];
    }
    if (++seen == m) {
      ans++;
			seen = border[m]; // There are no more characters in needle, so with the next input character let's try with the border of the whole needle.
    }
  }
  return ans;
}



int main(){

	cin >> n_n[0] >> n_n[1]; 
	
	for (int i = 0; i < 2; ++i)
	{
		int prev;
		cin >> prev;
		for (int j = 1; j < n_n[i]; ++j)
		{
			int temp;
			cin >> temp;
			h[i][j-1] = temp - prev;
			prev = temp;
		}
	}
	if(n_n[1] == 1){
		cout << n_n[0] << endl;
	}
	else{
		int ans = kmp();
		cout << ans << endl;
	}
	return 0;
}