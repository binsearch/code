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

  int n,t,c;
  cin >> n >> t >> c;
  int cnt = 0;
  int a[200010];
  for(int i = 0; i < n; i++)
    cin >> a[i] ;

  int left = -1;

  for(int i = 0; i < n; i++){
    if(a[i] <= t && left == -1){
      left = i;
    }

    if(a[i] > t && left != -1){
      if(i-left >= c){
      cnt+= i-left-c+1;
      }
      left = -1;
    }
  }

  if(left != -1 && n-left >= c)
    cnt+= n-left-c+1;

  cout << cnt << endl;
  return 0;

}