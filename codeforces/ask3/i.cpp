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

  freopen("twocyl.in", "r", stdin); 
  freopen("twocyl.out", "w", stdout);
  double r1,r2;
  cin >> r1 >> r2;

  if(r1 < r2){
    double temp = r2;
    r2 = r1;
    r1 = temp;
  }
  
  int steps = 10000000;
  double vol = 0;
  for(int i = 0; i < steps; i++){
    double j = i*r2/steps; 
    vol+= 4 * sqrt((r1*r1 - j*j) * (r2*r2 - j*j)) * (r2/steps);
  }
  vol = 2*vol;
  cout << vol << endl;


	return 0;	
}
