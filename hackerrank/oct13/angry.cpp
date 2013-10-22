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
inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
	n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int main(){

	int n,k;
	inp(n);
	inp(k);
	int arr[n];
	for(int i = 0; i < n; i++) inp(arr[i]);
	sort(arr, arr+n);
	int i = 1;
	int m = arr[k-1] - arr[0];
	while(i+k-1 < n){
		if(arr[i+k-1] - arr[i] < m) m = arr[i+k-1] - arr[i];
		i++;
	}
	cout << m << endl;

	return 0;	
}