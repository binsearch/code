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
  int a[110];
  memset(a, 0, sizeof a);

  for(int i = 0; i < n; i++){
    int temp;
    cin >> temp;
    a[temp]++;
  }

  int h = 0;

  for(int i = 0; i < 110; i++){
    int temp = a[i]/(i+1);
    if(a[i]%(i+1) != 0) temp++;
    if(temp > h) h = temp;
  }

  cout << h << endl;

  return 0;

}