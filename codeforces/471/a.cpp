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
#define mod 1000000007
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;

int main(){

	int a[10] = {0};
	for (int i = 0; i < 6; ++i)
	{
		int t;
		cin >> t;
		a[t]--;
	}

	sort(a, a+10);

	if(a[0] == -6 || ((a[0] == -4) && a[1] == -2)){
		printf("Elephant\n");
	}

	else if(a[0] <= -4){
		printf("Bear\n");
	}

	else{
		printf("Alien\n");
	}

	return 0;	
}