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
  cin >> n;
  int a[300010];
  for (int i = 0; i < n; ++i)
  {
    cin >> a[i];
  }

  sort(a, a+n);
  lli cumm_sum = 0;
  lli sum = 0; 

  for(int i = n-1; i >=0; i--){
    cumm_sum += a[i];
    sum = sum + cumm_sum;
  }

  sum = sum + cumm_sum - a[n-1];
  cout << sum << endl;


	return 0;	
}
