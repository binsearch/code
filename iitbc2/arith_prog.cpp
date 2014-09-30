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
  int a[100010];

  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i];
  
  if(n == 1){
    cout << "-1" << endl;
    return 0;
  }

   
  sort(a, a+n);

  int flag1 = 1; int flag2 = 0;
  int diff1 = a[1] - a[0], diff2 = -1; 
  int diff1ind, diff2ind;
  diff1ind = 0;
  
  for(int i = 1; i < n-1; i++){
    int tdiff = a[i+1] - a[i];
    if(tdiff == diff1 ){
      flag1++;
    }

    else if(flag2 == 0){
      diff2ind = i;
      diff2 = tdiff;
      flag2++;
    }
    else if(tdiff == diff2){
      flag2++;
    }
    else {
      cout << 0 << endl;
      return 0;
    }

    if(flag1 > 1 && flag2 > 1){
      cout << 0 << endl;
      return 0;
    }
  }
  
  if(flag2 == 0){
    if(diff1 != 0){

    if(n == 2 && diff1%2 == 0){
      cout << 3 << endl;
      cout << a[0] - diff1 << " " << a[0] + diff1/2 << " " << a[1] + diff1 << endl; 
    }
    else{
      cout << 2 << endl;
      cout << a[0] - diff1 << " " << a[n-1] + diff1 << endl;
    }
    }

    if(diff1 == 0){
      cout << 1 << endl;
      cout << a[0] << endl;
    }
  }
  else{ 
    if(flag2 == 1 && diff2 == 2 * diff1){
      cout << 1 << endl;
      cout << a[diff2ind] + diff1 << endl;
    }
    else if(flag1 == 1 && diff1 == 2 * diff2){
      cout << 1 << endl;
      cout << a[diff1ind] + diff2 << endl;
    }
    else{
      cout << 0 << endl;
    }
  }

	return 0;	
}
