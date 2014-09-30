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

int gcd(int a, int b){
	if(b == 0) return a;
	else return gcd(b, a%b);
}

int main(){
	int ab,ac,bd, at_num, at_den;
	while(scanf("%d %d %d",&ab, &ac, &bd)!=EOF) {
		at_num = ab * ac;
		at_den = bd-ac;
		int a = max(at_num, at_den);
		int b = min(at_num, at_den);
		int g = gcd(a,b);
		at_num/= g;
		at_den/= g;
		printf("%d/%d\n", at_num, at_den);
	}


	return 0;	
}