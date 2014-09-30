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
typedef pair<char,int> pci;
#define vvi vector<vector<int> > 
#define vi vector<int>

std::vector<std::vector<pci> > trie;



int main(){

  lli n,m,k;
  cin >> n >> m >> k;

  lli ans = -1;

  if(n-1 >= k){
    // cout << "in" << endl;
    if(ans < (n/(k+1))*m) ans = (n/(k+1))*m;
  }

  if(m-1 >= k){
    // cout << "in2" << endl;
    if(ans < (m/(k+1))*n) ans = (m/(k+1))*n;
  }

  if(n-1 < k && m-1 < k){
    ans = max(m/(k-n+2) , n/(k-m+2));
  }

  if(k > n+m-2){
    ans = -1;
  }

  cout << ans << endl;

	return 0;	
}
