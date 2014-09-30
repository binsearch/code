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

int main(){

	freopen("huffman.in", "r", stdin); 
	freopen("huffman.out", "w", stdout);

	int n;
	scanf("%d\n", &n);
	multiset<lli> inp;
	lli cumm_sum = 0;
	for(int i = 0; i < n; i++){
		int temp;
		scanf("%d", &temp);
		cumm_sum+= temp;
		inp.insert(inp.begin(), temp);
	}

	lli ans = 0;

	while(!inp.empty()){
		if(inp.size() == 1){
			ans+= *(inp.begin());
			break;
		}

		multiset<lli>::iterator it = inp.begin();

		lli temp = *it;
		it++;

		temp+= *it;

		ans+= temp;

		inp.erase(inp.begin());
		inp.erase(inp.begin());
		inp.insert(temp);
	}

	scanf("%lld\n", ans-cumm_sum);

	return 0;	
}