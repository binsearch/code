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
	lli arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr+n);
	lli m = 0;
	lli sum = 0;
	for(int i = 0; i < k; i++){
		m = m - (k-1-i)*arr[i] + i*arr[i];
		sum+= arr[i];
	}

	int i = 1;
	lli temp = m;
	while(i+k-1 < n){
		temp = temp - 2*sum + (k+1) * arr[i-1] + (k-1) * arr[i+k-1];
		if(temp < m) m = temp;
		sum = sum + arr[i+k-1] - arr[i-1];
		i++;
	}

	cout << m << endl;


	return 0;	
}