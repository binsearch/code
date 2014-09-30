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
  
  int n, x;
  int cumm_sum = 0;
  cin >> n >> x;
  for(int i = 0; i < n; i++){
    int temp;
    cin >> temp;
    cumm_sum+= temp;

  } 
  
  cumm_sum = abs(cumm_sum);
  
  int ans = cumm_sum/x;

  if(ans*x != cumm_sum) ans++;

  cout << ans << endl;

	return 0;	
}
