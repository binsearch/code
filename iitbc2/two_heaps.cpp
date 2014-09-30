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
  int cnt[210];
  memset(cnt, 0, sizeof cnt);
  int a[210];
  cin >> n;
  for(int i = 0; i < 2*n; i++){
    cin >> a[i];
    cnt[a[i]]++;
  }
  

  int b[210];
  memset(b, -1, sizeof b);
  int tot[2];
  tot[0] = 0;
  tot[1] = 0;
  int h1 = 0;
  int h2 = 0;

  for(int i = 0; i < 100; i++){
    if(cnt[i] == 1){
      b[i] = h1;
      tot[h1]++;
      h1 = (h1+1)%2;
    }
  }




  for(int i = 0; i < 100; i++){
    if(cnt[i] > 1){
      tot[0]++;
      tot[1]++;
    }

    if(cnt[i]%2 == 0) b[i] = 0;
    else{
      if(cnt[i] != 1){
        b[i] = h1;
        h1 = (h1 + 1)%2;
      }
    }

  }
  cout << tot[0] * tot[1] << endl;

  for(int i = 0; i < 2*n ; i++){
    cout << b[a[i]] + 1 << " ";
    b[a[i]] = (b[a[i]] + 1) % 2;
  }


  cout << endl;
	return 0;	
}
